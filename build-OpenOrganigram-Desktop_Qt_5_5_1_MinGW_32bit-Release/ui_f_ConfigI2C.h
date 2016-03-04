/********************************************************************************
** Form generated from reading UI file 'f_ConfigI2C.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CONFIGI2C_H
#define UI_F_CONFIGI2C_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_ConfigI2C
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *TabLCD;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QSpinBox *Ligne;
    QSpinBox *Car;
    QSpinBox *Addr;
    QCommandLinkButton *Btn_Reprogrammer;
    QWidget *tab_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ConfigI2C)
    {
        if (f_ConfigI2C->objectName().isEmpty())
            f_ConfigI2C->setObjectName(QStringLiteral("f_ConfigI2C"));
        f_ConfigI2C->resize(414, 300);
        verticalLayout = new QVBoxLayout(f_ConfigI2C);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(f_ConfigI2C);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        TabLCD = new QWidget();
        TabLCD->setObjectName(QStringLiteral("TabLCD"));
        verticalLayout_2 = new QVBoxLayout(TabLCD);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(TabLCD);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setCheckable(true);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        Ligne = new QSpinBox(groupBox);
        Ligne->setObjectName(QStringLiteral("Ligne"));
        Ligne->setMinimum(1);
        Ligne->setMaximum(9);
        Ligne->setValue(2);

        gridLayout->addWidget(Ligne, 1, 1, 1, 1);

        Car = new QSpinBox(groupBox);
        Car->setObjectName(QStringLiteral("Car"));
        Car->setMinimum(1);
        Car->setValue(16);

        gridLayout->addWidget(Car, 2, 1, 1, 1);

        Addr = new QSpinBox(groupBox);
        Addr->setObjectName(QStringLiteral("Addr"));
        Addr->setMinimum(1);
        Addr->setMaximum(255);
        Addr->setValue(39);

        gridLayout->addWidget(Addr, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        Btn_Reprogrammer = new QCommandLinkButton(TabLCD);
        Btn_Reprogrammer->setObjectName(QStringLiteral("Btn_Reprogrammer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Btn_Reprogrammer->sizePolicy().hasHeightForWidth());
        Btn_Reprogrammer->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Reprogrammer->setIcon(icon);

        verticalLayout_2->addWidget(Btn_Reprogrammer);

        tabWidget->addTab(TabLCD, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(f_ConfigI2C);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_ConfigI2C);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ConfigI2C, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ConfigI2C, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(f_ConfigI2C);
    } // setupUi

    void retranslateUi(QDialog *f_ConfigI2C)
    {
        f_ConfigI2C->setWindowTitle(QApplication::translate("f_ConfigI2C", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("f_ConfigI2C", "Ecran LCD Pr\303\251sent", 0));
        label_3->setText(QApplication::translate("f_ConfigI2C", "Nombre de caract\303\250res par ligne(s)", 0));
        label_2->setText(QApplication::translate("f_ConfigI2C", "Nombre de ligne(s)", 0));
        label->setText(QApplication::translate("f_ConfigI2C", "Adresse I2C", 0));
        label_4->setText(QApplication::translate("f_ConfigI2C", "(En d\303\251cimal)", 0));
        Btn_Reprogrammer->setText(QApplication::translate("f_ConfigI2C", "Reprogrammer la configuration", 0));
        tabWidget->setTabText(tabWidget->indexOf(TabLCD), QApplication::translate("f_ConfigI2C", "Ecran LCD", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("f_ConfigI2C", "Horloge Temps R\303\251el", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ConfigI2C: public Ui_f_ConfigI2C {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CONFIGI2C_H
