/********************************************************************************
** Form generated from reading UI file 'f_InterpreteurCommandes.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_INTERPRETEURCOMMANDES_H
#define UI_F_INTERPRETEURCOMMANDES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_InterpreteurCommandes
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *QLabelImage;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelNomPort;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelHeureDate;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabelUptime;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QTextEdit *QBoxReception;
    QHBoxLayout *horizontalLayout;
    QLineEdit *QTeEmission;
    QPushButton *BoutonValider;

    void setupUi(QDialog *f_InterpreteurCommandes)
    {
        if (f_InterpreteurCommandes->objectName().isEmpty())
            f_InterpreteurCommandes->setObjectName(QStringLiteral("f_InterpreteurCommandes"));
        f_InterpreteurCommandes->resize(400, 345);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/shell.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_InterpreteurCommandes->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(f_InterpreteurCommandes);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 6, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        QLabelImage = new QLabel(f_InterpreteurCommandes);
        QLabelImage->setObjectName(QStringLiteral("QLabelImage"));
        QLabelImage->setMaximumSize(QSize(16777215, 16777215));
        QLabelImage->setPixmap(QPixmap(QString::fromUtf8(":/Images/App/arduino_mega.png")));

        horizontalLayout_3->addWidget(QLabelImage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 6, -1, -1);
        LabelNomPort = new QLabel(f_InterpreteurCommandes);
        LabelNomPort->setObjectName(QStringLiteral("LabelNomPort"));
        LabelNomPort->setScaledContents(true);
        LabelNomPort->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(LabelNomPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        LabelHeureDate = new QLabel(f_InterpreteurCommandes);
        LabelHeureDate->setObjectName(QStringLiteral("LabelHeureDate"));

        horizontalLayout_2->addWidget(LabelHeureDate);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 6, -1, -1);
        LabelUptime = new QLabel(f_InterpreteurCommandes);
        LabelUptime->setObjectName(QStringLiteral("LabelUptime"));

        horizontalLayout_4->addWidget(LabelUptime);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        QBoxReception = new QTextEdit(f_InterpreteurCommandes);
        QBoxReception->setObjectName(QStringLiteral("QBoxReception"));
        QBoxReception->setMinimumSize(QSize(0, 100));
        QBoxReception->setMaximumSize(QSize(16777215, 130));
        QBoxReception->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        QBoxReception->setAutoFormatting(QTextEdit::AutoAll);
        QBoxReception->setTabChangesFocus(true);
        QBoxReception->setUndoRedoEnabled(false);
        QBoxReception->setLineWrapMode(QTextEdit::NoWrap);
        QBoxReception->setReadOnly(true);

        verticalLayout->addWidget(QBoxReception);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        QTeEmission = new QLineEdit(f_InterpreteurCommandes);
        QTeEmission->setObjectName(QStringLiteral("QTeEmission"));
        QTeEmission->setMaximumSize(QSize(16777215, 160));
        QTeEmission->setInputMethodHints(Qt::ImhNone);
        QTeEmission->setMaxLength(20);
        QTeEmission->setClearButtonEnabled(false);

        horizontalLayout->addWidget(QTeEmission);

        BoutonValider = new QPushButton(f_InterpreteurCommandes);
        BoutonValider->setObjectName(QStringLiteral("BoutonValider"));

        horizontalLayout->addWidget(BoutonValider);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(f_InterpreteurCommandes);

        QMetaObject::connectSlotsByName(f_InterpreteurCommandes);
    } // setupUi

    void retranslateUi(QDialog *f_InterpreteurCommandes)
    {
        f_InterpreteurCommandes->setWindowTitle(QApplication::translate("f_InterpreteurCommandes", "INTERPRETEUR", 0));
        QLabelImage->setText(QString());
        LabelNomPort->setText(QString());
        LabelHeureDate->setText(QString());
        LabelUptime->setText(QString());
        BoutonValider->setText(QApplication::translate("f_InterpreteurCommandes", "Valider", 0));
    } // retranslateUi

};

namespace Ui {
    class f_InterpreteurCommandes: public Ui_f_InterpreteurCommandes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_INTERPRETEURCOMMANDES_H
