/********************************************************************************
** Form generated from reading UI file 'f_Supervision.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_SUPERVISION_H
#define UI_F_SUPERVISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_Supervision
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *BtAfficher;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *BtHorizontal;
    QPushButton *BtVertical;
    QMdiArea *ZoneMDI;

    void setupUi(QWidget *f_Supervision)
    {
        if (f_Supervision->objectName().isEmpty())
            f_Supervision->setObjectName(QStringLiteral("f_Supervision"));
        f_Supervision->setEnabled(true);
        f_Supervision->resize(555, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(f_Supervision->sizePolicy().hasHeightForWidth());
        f_Supervision->setSizePolicy(sizePolicy);
        f_Supervision->setMinimumSize(QSize(300, 300));
        f_Supervision->setMaximumSize(QSize(16777215, 16777215));
        f_Supervision->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(f_Supervision);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BtAfficher = new QPushButton(f_Supervision);
        BtAfficher->setObjectName(QStringLiteral("BtAfficher"));
        BtAfficher->setAutoDefault(false);
        BtAfficher->setFlat(false);

        horizontalLayout->addWidget(BtAfficher);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        BtHorizontal = new QPushButton(f_Supervision);
        BtHorizontal->setObjectName(QStringLiteral("BtHorizontal"));
        BtHorizontal->setMinimumSize(QSize(90, 0));
        BtHorizontal->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(BtHorizontal);

        BtVertical = new QPushButton(f_Supervision);
        BtVertical->setObjectName(QStringLiteral("BtVertical"));

        horizontalLayout->addWidget(BtVertical);


        verticalLayout->addLayout(horizontalLayout);

        ZoneMDI = new QMdiArea(f_Supervision);
        ZoneMDI->setObjectName(QStringLiteral("ZoneMDI"));
        ZoneMDI->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ZoneMDI->sizePolicy().hasHeightForWidth());
        ZoneMDI->setSizePolicy(sizePolicy1);
        ZoneMDI->setMaximumSize(QSize(16777215, 16777215));
        ZoneMDI->setLayoutDirection(Qt::LeftToRight);
        ZoneMDI->setFrameShape(QFrame::NoFrame);
        ZoneMDI->setFrameShadow(QFrame::Plain);
        ZoneMDI->setMidLineWidth(-1);
        ZoneMDI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ZoneMDI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(ZoneMDI);


        retranslateUi(f_Supervision);

        BtAfficher->setDefault(false);
        BtHorizontal->setDefault(false);
        BtVertical->setDefault(false);


        QMetaObject::connectSlotsByName(f_Supervision);
    } // setupUi

    void retranslateUi(QWidget *f_Supervision)
    {
        f_Supervision->setWindowTitle(QApplication::translate("f_Supervision", "Supervision", 0));
        BtAfficher->setText(QApplication::translate("f_Supervision", "S\303\251lectionnerAffichage", 0));
#ifndef QT_NO_TOOLTIP
        BtHorizontal->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        BtHorizontal->setText(QApplication::translate("f_Supervision", "Organiser Horizontale", 0));
        BtVertical->setText(QApplication::translate("f_Supervision", "Organiser Verticale", 0));
    } // retranslateUi

};

namespace Ui {
    class f_Supervision: public Ui_f_Supervision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_SUPERVISION_H
