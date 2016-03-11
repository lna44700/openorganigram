// f_ModInst_EP.h 1.0 10/03/16
#ifndef F_MODINST_EP_H
#define F_MODINST_EP_H

class f_ModInst_EP ;

//===== Headers standards =====
#include <QDialog>

//=====   Headers Peros   =====
#include "../Inst/Inst_EP.h"

namespace Ui {
class f_ModInst_EP;
}

class f_ModInst_EP : public QDialog
{
    Q_OBJECT

public:
    explicit f_ModInst_EP(Inst_EP * pInstructionAModifier, QWidget *parent = 0);
    ~f_ModInst_EP();

    DescEP  getDescription() ;

private slots:
    void on_BtnAccept_accepted();

    void on_BtnAccept_rejected();

private:
    Inst_EP *           pInstructionAModifier ;

    Ui::f_ModInst_EP *ui;
};

#endif // F_MODINST_EP_H
