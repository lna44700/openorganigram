/********************************************************************************
** Form generated from reading UI file 'f_ModInst_Boucle.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_BOUCLE_H
#define UI_F_MODINST_BOUCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_Boucle
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RadioTQ;
    QRadioButton *RadioJQ;

    void setupUi(QDialog *f_ModInst_Boucle)
    {
        if (f_ModInst_Boucle->objectName().isEmpty())
            f_ModInst_Boucle->setObjectName(QStringLiteral("f_ModInst_Boucle"));
        f_ModInst_Boucle->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Items/iconboucle.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ModInst_Boucle->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ModInst_Boucle);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        RadioTQ = new QRadioButton(f_ModInst_Boucle);
        RadioTQ->setObjectName(QStringLiteral("RadioTQ"));

        horizontalLayout->addWidget(RadioTQ);

        RadioJQ = new QRadioButton(f_ModInst_Boucle);
        RadioJQ->setObjectName(QStringLiteral("RadioJQ"));

        horizontalLayout->addWidget(RadioJQ);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(f_ModInst_Boucle);

        QMetaObject::connectSlotsByName(f_ModInst_Boucle);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_Boucle)
    {
        f_ModInst_Boucle->setWindowTitle(QApplication::translate("f_ModInst_Boucle", "Modification de la boucle", 0));
        RadioTQ->setText(QApplication::translate("f_ModInst_Boucle", "Boucle Tant que...fin", 0));
        RadioJQ->setText(QApplication::translate("f_ModInst_Boucle", "Boucle R\303\251p\303\251ter...Jusqu'\303\240", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_Boucle: public Ui_f_ModInst_Boucle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_BOUCLE_H
