/********************************************************************************
** Form generated from reading UI file 'f_AffichageFenetre.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_AFFICHAGEFENETRE_H
#define UI_F_AFFICHAGEFENETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_AffichageFenetre
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_AffichageFenetre)
    {
        if (f_AffichageFenetre->objectName().isEmpty())
            f_AffichageFenetre->setObjectName(QStringLiteral("f_AffichageFenetre"));
        f_AffichageFenetre->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_AffichageFenetre->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_AffichageFenetre);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView = new QListView(f_AffichageFenetre);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        buttonBox = new QDialogButtonBox(f_AffichageFenetre);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_AffichageFenetre);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_AffichageFenetre, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_AffichageFenetre, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_AffichageFenetre);
    } // setupUi

    void retranslateUi(QDialog *f_AffichageFenetre)
    {
        f_AffichageFenetre->setWindowTitle(QApplication::translate("f_AffichageFenetre", "S\303\251lectionner affichage", 0));
    } // retranslateUi

};

namespace Ui {
    class f_AffichageFenetre: public Ui_f_AffichageFenetre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_AFFICHAGEFENETRE_H
