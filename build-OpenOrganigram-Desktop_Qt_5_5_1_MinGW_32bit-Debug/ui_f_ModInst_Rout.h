/********************************************************************************
** Form generated from reading UI file 'f_ModInst_Rout.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_ROUT_H
#define UI_F_MODINST_ROUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_Rout
{
public:
    QVBoxLayout *verticalLayout;
    QListView *Liste;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Ajout;
    QPushButton *Btn_Suppr;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ModInst_Rout)
    {
        if (f_ModInst_Rout->objectName().isEmpty())
            f_ModInst_Rout->setObjectName(QStringLiteral("f_ModInst_Rout"));
        f_ModInst_Rout->resize(400, 300);
        verticalLayout = new QVBoxLayout(f_ModInst_Rout);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Liste = new QListView(f_ModInst_Rout);
        Liste->setObjectName(QStringLiteral("Liste"));
        Liste->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(Liste);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 6, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_Ajout = new QPushButton(f_ModInst_Rout);
        Btn_Ajout->setObjectName(QStringLiteral("Btn_Ajout"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Ajout->setIcon(icon);

        horizontalLayout->addWidget(Btn_Ajout);

        Btn_Suppr = new QPushButton(f_ModInst_Rout);
        Btn_Suppr->setObjectName(QStringLiteral("Btn_Suppr"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/App/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Suppr->setIcon(icon1);

        horizontalLayout->addWidget(Btn_Suppr);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(f_ModInst_Rout);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_ModInst_Rout);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ModInst_Rout, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ModInst_Rout, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_ModInst_Rout);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_Rout)
    {
        f_ModInst_Rout->setWindowTitle(QApplication::translate("f_ModInst_Rout", "Appel de routine", 0));
        Btn_Ajout->setText(QString());
        Btn_Suppr->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_Rout: public Ui_f_ModInst_Rout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_ROUT_H
