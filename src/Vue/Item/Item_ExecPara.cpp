//-------------------------------------------------------------------------------
/**
 * @file        Item_ExecPara.cpp
 * @brief       Item de gestion de l'exécution parallèle
 *
 * @author      L.Guitton
 * @author      STS SNIR, Lycée Nicolas APPERT, ORVAULT (FRANCE)
 * @since       02/02/2016
 * @version     1.0
 * @date        08/03/2016
 *
 * Element graphique représentant une exécution d'une ou plusieurs branches en même temps
 *
 * Fabrication  OpenOrganigram.pro
 *
 * @todo        /
 *
 * @bug         /
 */
//-------------------------------------------------------------------------------

//===== Headers standards =====
#include <QBrush>
#include <QPainter>
#include <QGraphicsView>

#include <QDebug>
#include <QMessageBox>

//=====   Headers Peros   =====
#include "Item_ExecPara.h"
#include "../../Control/Inst/Inst_EP.h"


/**
 * Constructeur
 *
 * @brief   Item_ES::Item_ES(QGraphicsItem * pParent = 0)
 * @param   pParent     Pointeur vers l'objet QGraphicsItem (ou dérivé) parent.
 * @see     Item
 */
Item_ExecPara::Item_ExecPara(Instruction *   pInst, Item *pItemPrec, QGraphicsItem * pParent) :
    Item(pInst, pItemPrec, pParent)
{
    setTexte("Execution Parallele") ;
}

/**
 * Décrit le façon de dessiner l'élément sur la scène
 *
 * @brief   Item_ES::paint(QPainter *pPainter, const QStyleOptionGraphicsItem * option, QWidget * widget)
 * @param   pPainter    le pinceau servant à dessiner sur la scène
 * @param   option      Option sur le dessin (pas utile dans notre cas)
 * @param   widget      Pointer vers le widget sur lequel l'item sera peint (pas utile dans notre cas)
 * @see     Item
 */
void Item_ExecPara::paint(QPainter *pPainter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    this->GererSelection(pPainter) ;
    this->sTexte = this->pInstRepresentee->toString() ;
    Inst_EP* pInst_EP  (static_cast<Inst_EP *>(this->pInstRepresentee));

    pPainter->setPen(QPen());

    qreal           top             (this->rect.top()) ;
    qreal           left            (this->rect.left()) ;

    //Définition des points
    QPointF Point1 ;
    QPointF Point2 ;
    QPointF Point3 ;
    QPointF Point4 ;
    QPointF Point5 ;
    QPointF Point6 ;
    QPointF Point7 ;
    QPointF Point8 ;


    //Dessin première ligne
    Point1.setX(left) ;
    Point1.setY(top) ;

    Point2.setX(-left) ;
    Point2.setY(top) ;

    pPainter->drawLine(Point1, Point2) ;

    //Dessin deuxième ligne
    Point3.setX(left) ;
    Point3.setY(top-0.5) ;

    Point4.setX(-left) ;
    Point4.setY(top-0.5) ;

    pPainter->drawLine(Point3, Point4) ;

    //Dessin troisième ligne
    Point5.setX(left) ;
    Point5.setY(-top) ;

    Point6.setX(-left) ;
    Point6.setY(-top) ;

    pPainter->drawLine(Point5, Point6) ;

    //Dessin quatrième ligne
    Point7.setX(left) ;
    Point7.setY(-top+0.5) ;

    Point8.setX(-left) ;
    Point8.setY(-top+0.5) ;

    pPainter->drawLine(Point7, Point8) ;
}
