/********************************************************************************
** Form generated from reading UI file 'f_RealiserPlanCablage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_REALISERPLANCABLAGE_H
#define UI_F_REALISERPLANCABLAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_RealiserPlanCablage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *GrpBx;
    QGridLayout *LayListeCapteursEtActionneurs;
    QComboBox *CB_Interface;
    QGraphicsView *Vue;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Prec;
    QPushButton *Btn_Suiv;

    void setupUi(QDialog *f_RealiserPlanCablage)
    {
        if (f_RealiserPlanCablage->objectName().isEmpty())
            f_RealiserPlanCablage->setObjectName(QStringLiteral("f_RealiserPlanCablage"));
        f_RealiserPlanCablage->resize(941, 536);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_RealiserPlanCablage->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_RealiserPlanCablage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        GrpBx = new QGroupBox(f_RealiserPlanCablage);
        GrpBx->setObjectName(QStringLiteral("GrpBx"));
        GrpBx->setMinimumSize(QSize(0, 0));
        GrpBx->setMaximumSize(QSize(16777215, 16777215));
        LayListeCapteursEtActionneurs = new QGridLayout(GrpBx);
        LayListeCapteursEtActionneurs->setSpacing(6);
        LayListeCapteursEtActionneurs->setContentsMargins(11, 11, 11, 11);
        LayListeCapteursEtActionneurs->setObjectName(QStringLiteral("LayListeCapteursEtActionneurs"));
        CB_Interface = new QComboBox(GrpBx);
        CB_Interface->setObjectName(QStringLiteral("CB_Interface"));
        CB_Interface->setMinimumSize(QSize(270, 20));

        LayListeCapteursEtActionneurs->addWidget(CB_Interface, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(GrpBx);

        Vue = new QGraphicsView(f_RealiserPlanCablage);
        Vue->setObjectName(QStringLiteral("Vue"));
        Vue->setMinimumSize(QSize(621, 485));
        Vue->setMaximumSize(QSize(621, 485));
        Vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Vue->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Vue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Vue->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        horizontalLayout_2->addWidget(Vue);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_Prec = new QPushButton(f_RealiserPlanCablage);
        Btn_Prec->setObjectName(QStringLiteral("Btn_Prec"));

        horizontalLayout->addWidget(Btn_Prec);

        Btn_Suiv = new QPushButton(f_RealiserPlanCablage);
        Btn_Suiv->setObjectName(QStringLiteral("Btn_Suiv"));

        horizontalLayout->addWidget(Btn_Suiv);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(f_RealiserPlanCablage);

        Btn_Suiv->setDefault(true);


        QMetaObject::connectSlotsByName(f_RealiserPlanCablage);
    } // setupUi

    void retranslateUi(QDialog *f_RealiserPlanCablage)
    {
        f_RealiserPlanCablage->setWindowTitle(QApplication::translate("f_RealiserPlanCablage", "R\303\251alisation du plan de c\303\242blage", 0));
        GrpBx->setTitle(QApplication::translate("f_RealiserPlanCablage", "Liste des capteurs/actionneurs", 0));
        Btn_Prec->setText(QApplication::translate("f_RealiserPlanCablage", "Pr\303\251c\303\251dent", 0));
        Btn_Suiv->setText(QApplication::translate("f_RealiserPlanCablage", "Suivant", 0));
    } // retranslateUi

};

namespace Ui {
    class f_RealiserPlanCablage: public Ui_f_RealiserPlanCablage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_REALISERPLANCABLAGE_H
