/********************************************************************************
** Form generated from reading UI file 'f_ModInst_EP.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_EP_H
#define UI_F_MODINST_EP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_EP
{
public:
    QGroupBox *groupBtnChoix;
    QRadioButton *choix2;
    QRadioButton *choix3;
    QRadioButton *choix4;
    QRadioButton *choix5;
    QDialogButtonBox *BtnAccept;

    void setupUi(QWidget *f_ModInst_EP)
    {
        if (f_ModInst_EP->objectName().isEmpty())
            f_ModInst_EP->setObjectName(QStringLiteral("f_ModInst_EP"));
        f_ModInst_EP->resize(400, 161);
        groupBtnChoix = new QGroupBox(f_ModInst_EP);
        groupBtnChoix->setObjectName(QStringLiteral("groupBtnChoix"));
        groupBtnChoix->setGeometry(QRect(9, 10, 381, 111));
        choix2 = new QRadioButton(groupBtnChoix);
        choix2->setObjectName(QStringLiteral("choix2"));
        choix2->setGeometry(QRect(20, 40, 82, 17));
        choix3 = new QRadioButton(groupBtnChoix);
        choix3->setObjectName(QStringLiteral("choix3"));
        choix3->setGeometry(QRect(20, 80, 82, 17));
        choix4 = new QRadioButton(groupBtnChoix);
        choix4->setObjectName(QStringLiteral("choix4"));
        choix4->setGeometry(QRect(180, 40, 82, 17));
        choix5 = new QRadioButton(groupBtnChoix);
        choix5->setObjectName(QStringLiteral("choix5"));
        choix5->setGeometry(QRect(180, 80, 82, 17));
        BtnAccept = new QDialogButtonBox(f_ModInst_EP);
        BtnAccept->setObjectName(QStringLiteral("BtnAccept"));
        BtnAccept->setGeometry(QRect(120, 130, 156, 23));
        BtnAccept->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(f_ModInst_EP);

        QMetaObject::connectSlotsByName(f_ModInst_EP);
    } // setupUi

    void retranslateUi(QWidget *f_ModInst_EP)
    {
        f_ModInst_EP->setWindowTitle(QApplication::translate("f_ModInst_EP", "Form", 0));
        groupBtnChoix->setTitle(QApplication::translate("f_ModInst_EP", "Nombre de Branches", 0));
        choix2->setText(QApplication::translate("f_ModInst_EP", "2", 0));
        choix3->setText(QApplication::translate("f_ModInst_EP", "3", 0));
        choix4->setText(QApplication::translate("f_ModInst_EP", "4", 0));
        choix5->setText(QApplication::translate("f_ModInst_EP", "5", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_EP: public Ui_f_ModInst_EP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_EP_H
