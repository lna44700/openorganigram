//  Item_ExecPara.h  1.0     08/03/2016    L.Guitton

#ifndef ITEM_EXECPARA
#define ITEM_EXECPARA

class Item_ExecPara ;

//===== Headers standards =====

//=====   Headers Peros   =====
#include "../Item.h"

class Item_ExecPara : public Item
{
    public:
        explicit    Item_ExecPara(Instruction *pInst, Item * pItemPrec = 0, QGraphicsItem *pParent = 0) ;           //Constructeur
            void    paint(QPainter *pPainter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/) ;//Fonction de dessin
};


#endif // ITEM_EXECPARA

