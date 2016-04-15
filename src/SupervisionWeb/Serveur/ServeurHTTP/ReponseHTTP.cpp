/**
  @file
  @author Florian Philippeau
*/

//Includes Perso
#include "ReponseHTTP.h"

HttpReponse::HttpReponse(QTcpSocket* socket)
{
    this->socket=socket;
    codeStatus=200;
    statusText="OK";
    headersEnvoye=false;
    dernierePartieEnvoyee=false;
    modeChunked=false;
}

void HttpReponse::definirHeader(QByteArray nom, QByteArray valeur)
{
    Q_ASSERT(headersEnvoye==false);
    headers.insert(nom,valeur);
}

void HttpReponse::definirHeader(QByteArray nom, int valeur)
{
    Q_ASSERT(headersEnvoye==false);
    headers.insert(nom,QByteArray::number(valeur));
}

QMap<QByteArray,QByteArray>& HttpReponse::getHeaders()
{
    return headers;
}

void HttpReponse::setStatus(int codeStatus, QByteArray description)
{
    this->codeStatus=codeStatus;
    statusText=description;
}

int HttpReponse::getCodeStatus() const
{
   return this->codeStatus;
}

void HttpReponse::ecrireHeaders()
{
    Q_ASSERT(headersEnvoye==false);
    QByteArray buffer;
    buffer.append("HTTP/1.1 ");
    buffer.append(QByteArray::number(codeStatus));
    buffer.append(' ');
    buffer.append(statusText);
    buffer.append("\r\n");
    foreach(QByteArray nom, headers.keys())
    {
        buffer.append(nom);
        buffer.append(": ");
        buffer.append(headers.value(nom));
        buffer.append("\r\n");
    }

    buffer.append("\r\n");
    ecrireDansSocket(buffer);
    headersEnvoye=true;
}

bool HttpReponse::ecrireDansSocket(QByteArray data)
{
    int remaining=data.size();
    char* ptr=data.data();
    while (socket->isOpen() && remaining>0)
    {
        // If the output buffer has become large, then wait until it has been sent.
        if (socket->bytesToWrite()>16384)
        {
            socket->waitForBytesWritten(-1);
        }

        int written=socket->write(ptr,remaining);
        if (written==-1)
        {
          return false;
        }
        ptr+=written;
        remaining-=written;
    }
    return true;
}

void HttpReponse::ecrire(QByteArray data, bool dernierePartie)
{
    Q_ASSERT(dernierePartieEnvoyee==false);

    // Send HTTP headers, if not already done (that happens only on the first call to ecrire())
    if (headersEnvoye==false)
    {
        // If the whole response is generated with a single call to ecrire(), then we know the total
        // size of the response and therefore can set the Content-Length header automatically.
        if (dernierePartie)
        {
           // Automatically set the Content-Length header
           headers.insert("Content-Length",QByteArray::number(data.size()));
        }

        // else if we will not close the connection at the end, them we must use the chunked mode.
        else
        {
            bool connectionClose=QString::compare(headers.value("Connection"),"close",Qt::CaseInsensitive)==0;
            if (!connectionClose)
            {
                headers.insert("Transfer-Encoding","chunked");
                modeChunked=true;
            }
        }

        ecrireHeaders();
    }

    // Send data
    if (data.size()>0)
    {
        if (modeChunked)
        {
            if (data.size()>0)
            {
                QByteArray size=QByteArray::number(data.size(),16);
                ecrireDansSocket(size);
                ecrireDansSocket("\r\n");
                ecrireDansSocket(data);
                ecrireDansSocket("\r\n");
            }
        }
        else
        {
            ecrireDansSocket(data);
        }
    }

    // Only for the last chunk, send the terminating marker and flush the buffer.
    if (dernierePartie)
    {
        if (modeChunked)
        {
            ecrireDansSocket("0\r\n\r\n");
        }
        socket->flush();
        dernierePartieEnvoyee=true;
    }
}


bool HttpReponse::aEnvoyeDernierePartie() const
{
    return dernierePartieEnvoyee;
}


void HttpReponse::redirect(const QByteArray& url)
{
    setStatus(303,"See Other");
    definirHeader("Location",url);
    ecrire("Redirect",true);
}


void HttpReponse::flush()
{
    socket->flush();
}


bool HttpReponse::isConnected() const
{
    return socket->isOpen();
}
