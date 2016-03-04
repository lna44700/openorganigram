/********************************************************************************
** Form generated from reading UI file 'f_ModInst_Tempo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_TEMPO_H
#define UI_F_MODINST_TEMPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_Tempo
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ModInst_Tempo)
    {
        if (f_ModInst_Tempo->objectName().isEmpty())
            f_ModInst_Tempo->setObjectName(QStringLiteral("f_ModInst_Tempo"));
        f_ModInst_Tempo->resize(302, 70);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Items/icontemp.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ModInst_Tempo->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(f_ModInst_Tempo);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(f_ModInst_Tempo);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(f_ModInst_Tempo);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox->setReadOnly(false);
        spinBox->setMaximum(65535);

        verticalLayout->addWidget(spinBox);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(f_ModInst_Tempo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(f_ModInst_Tempo);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ModInst_Tempo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ModInst_Tempo, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_ModInst_Tempo);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_Tempo)
    {
        f_ModInst_Tempo->setWindowTitle(QApplication::translate("f_ModInst_Tempo", "Temps de pause", 0));
        label->setText(QApplication::translate("f_ModInst_Tempo", "Choisir le temps de pause du programme :", 0));
        spinBox->setSuffix(QApplication::translate("f_ModInst_Tempo", " ms", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_Tempo: public Ui_f_ModInst_Tempo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_TEMPO_H
