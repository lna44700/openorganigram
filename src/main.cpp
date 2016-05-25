//-------------------------------------------------------------------------------
/**
 * @file        main.cpp
 * @brief       Programme principal
 *
 * @author      N.Jarnoux, J. Aubry, F. De Dutto, K. Batard
 * @author      L. Guitton
 * @author      STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
 * @since       18/02/14
 * @version     1.0
 * @date        01/03/2016
 *
 * Programme principal : initialise l'application et ses différents composants
 *
 * Fabrication  OpenOrganigram.pro
 *
 * @todo        A completer lors de la réunification des parties
 *
 * @bug         /
 */
//-------------------------------------------------------------------------------

//=== Headers standards ===
#include <QApplication>

//===   Headers persos  ===
#include "f_MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication    a  (argc, argv) ;
    f_MainWindow    w  (0) ;

   // return a.exec();
    a.exec();
    return 0;
}
