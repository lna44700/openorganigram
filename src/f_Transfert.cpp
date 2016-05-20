#include "f_Transfert.h"
#include "ui_f_Transfert.h"

f_Transfert::f_Transfert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::f_Transfert)
{
    ui->setupUi(this);
}

f_Transfert::~f_Transfert()
{
    delete ui;
}
