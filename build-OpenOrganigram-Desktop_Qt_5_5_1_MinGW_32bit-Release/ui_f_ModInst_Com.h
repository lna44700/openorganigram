/********************************************************************************
** Form generated from reading UI file 'f_ModInst_Com.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_COM_H
#define UI_F_MODINST_COM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_Com
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ModInst_Com)
    {
        if (f_ModInst_Com->objectName().isEmpty())
            f_ModInst_Com->setObjectName(QStringLiteral("f_ModInst_Com"));
        f_ModInst_Com->resize(294, 221);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Items/iconcom.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ModInst_Com->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ModInst_Com);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(f_ModInst_Com);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        buttonBox = new QDialogButtonBox(f_ModInst_Com);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_ModInst_Com);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ModInst_Com, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ModInst_Com, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_ModInst_Com);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_Com)
    {
        f_ModInst_Com->setWindowTitle(QApplication::translate("f_ModInst_Com", "Modification d'un commentaire", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_Com: public Ui_f_ModInst_Com {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_COM_H
