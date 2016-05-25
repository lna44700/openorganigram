#-------------------------------------------------
#
# Project created by QtCreator 2014-02-18T09:50:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenOrganigram
TEMPLATE = app

unix {
    CONFIG += qesp_linux_udev
}

include (Interface/LibSerialPort/qextserialport.pri)
include (Interface/LibParser/LibParser.pri)
include(SupervisionWeb/Serveur/ServeurHTTP/ServeurHTTP.pri)


SOURCES += main.cpp\
        f_MainWindow.cpp \
    ConfigurationAppli/f_Configuration.cpp \
    ConfigurationAppli/f_CreerProfil.cpp \
    ConfigurationAppli/f_ChoixProfil.cpp \
    ConfigurationAppli/f_SupprimerProfil.cpp \
    ConfigurationAppli/f_ModifierProfil.cpp \
    ConfigurationAppli/f_APropos.cpp \
    ConfigurationMaquette/f_DefinirActionsEtTests.cpp \
    ConfigurationMaquette/f_RealiserPlanCablage.cpp \
    ConfigurationMaquette/AssistantConfiguration.cpp \
    ConfigurationMaquette/f_ChoixControleur.cpp \
    ConfigurationMaquette/f_ChoixInterface.cpp \
    ConfigurationMaquette/f_ChoixModules.cpp \
    ConfigurationMaquette/RealiserPlanDeCablage/ListeCapteurVue.cpp \
    ConfigurationMaquette/RealiserPlanDeCablage/ScenePlanDeCablage.cpp \
    ConfigurationMaquette/RealiserPlanDeCablage/ItemBroche.cpp \
    ConfigurationMaquette/RealiserPlanDeCablage/Photo.cpp \
    ConfigurationMaquette/RealiserPlanDeCablage/CapteurActionneur.cpp \
    ConfigurationMaquette/DefinirActionsEtTests/ItemActionTest.cpp \
    ConfigurationMaquette/DefinirActionsEtTests/f_EditerActionTest.cpp \
    Control/Routine.cpp \
    Control/Instruction.cpp \
    Control/ModuleManager.cpp \
    Control/Compil_Inst.cpp \
    Control/Compil_Rout.cpp \
    Control/Inst/Inst_Ope.cpp \
    Control/ModInst/f_ModInst_Ope.cpp \
    Control/Inst/Inst_Cond.cpp \
    Control/ModInst/f_ModInst_Cond.cpp \
    Control/Inst/Inst_ES.cpp \
    Control/ModInst/f_ModInst_ES.cpp \
    Control/Inst/Inst_Rout.cpp \
    Control/ModInst/f_ModInst_Rout.cpp \
    Control/Inst/Inst_Tempo.cpp \
    Control/ModInst/f_ModInst_Tempo.cpp \
    Control/Inst/Inst_Com.cpp \
    Control/ModInst/f_ModInst_Com.cpp \
    Control/Inst/Inst_Boucle.cpp \
    Control/ModInst/f_ModInst_Boucle.cpp \
    Control/Inst/Inst_EP.cpp \
    Control/ModInst/f_ModInst_EP.cpp \
    Control/Inst/Inst_DebFin.cpp \
    Interface/BtnItem.cpp \
    Interface/f_InterpreteurCommandes.cpp \
    Interface/Arduino.cpp \
    Interface/f_GestionMem.cpp \
    Interface/InterpreteurFichierIni.cpp \
    Interface/f_SaisieNom.cpp \
    Interface/f_ConfigI2C.cpp \
    Interface/f_Compilation.cpp \
    Supervision/f_SubWindow.cpp \
    Supervision/f_Supervision.cpp \
    Supervision/f_WidgetInterne.cpp \
    Supervision/f_AffichageFenetre.cpp \
    Supervision/Widgets/WidgetNI.cpp \
    Supervision/Switch.cpp \
    Supervision/Widgets/WidgetNO.cpp \
    Supervision/Widgets/WidgetAI.cpp \
    Supervision/Widgets/WidgetMOT1.cpp \
    SupervisionWeb/Serveur/RequeteMapper.cpp \
    SupervisionWeb/Serveur/Serveur.cpp \
    SupervisionWeb/Web/src/Donnees.cpp \
    Vue/Vue.cpp \
    Vue/Scene.cpp \
    Vue/Item.cpp \
    Vue/Item/Item_DebFin.cpp \
    Vue/Item/Item_Ope.cpp \
    Vue/Item/Item_Cond.cpp \
    Vue/Item/Item_ES.cpp \
    Vue/Item/Item_Rout.cpp \
    Vue/Item/Item_Tempo.cpp \
    Vue/Item/Item_Com.cpp \
    Vue/Item/Item_Boucle.cpp \
    Vue/Item/Item_ExecPara.cpp \
    Vue/Fleche.cpp \
    Vue/MarqueurDrop.cpp


HEADERS  += f_MainWindow.h \
    ConfigurationAppli/f_Configuration.h \
    ConfigurationAppli/f_CreerProfil.h \
    ConfigurationAppli/f_ChoixProfil.h \
    ConfigurationAppli/f_SupprimerProfil.h \
    ConfigurationAppli/f_ModifierProfil.h \
    ConfigurationAppli/f_APropos.h \
    ConfigurationMaquette/f_DefinirActionsEtTests.h \
    ConfigurationMaquette/f_RealiserPlanCablage.h \
    ConfigurationMaquette/AssistantConfiguration.h \
    ConfigurationMaquette/f_ChoixControleur.h \
    ConfigurationMaquette/f_ChoixInterface.h \
    ConfigurationMaquette/f_ChoixModules.h \
    ConfigurationMaquette/RealiserPlanDeCablage/ListeCapteurVue.h \
    ConfigurationMaquette/RealiserPlanDeCablage/ScenePlanDeCablage.h \
    ConfigurationMaquette/RealiserPlanDeCablage/ItemBroche.h \
    ConfigurationMaquette/RealiserPlanDeCablage/Photo.h \
    ConfigurationMaquette/RealiserPlanDeCablage/CapteurActionneur.h \
    ConfigurationMaquette/DefinirActionsEtTests/ItemActionTest.h \
    ConfigurationMaquette/DefinirActionsEtTests/f_EditerActionTest.h \
    Control/Routine.h \
    Control/Instruction.h \
    Control/ModuleManager.h \
    Control/Compil_Inst.h \
    Control/Compil_Rout.h \
    Control/Inst/Inst_Ope.h \
    Control/ModInst/f_ModInst_Ope.h \
    Control/Inst/Inst_Cond.h \
    Control/ModInst/f_ModInst_Cond.h \
    Control/Inst/Inst_ES.h \
    Control/ModInst/f_ModInst_ES.h \
    Control/Inst/Inst_Rout.h \
    Control/ModInst/f_ModInst_Rout.h \
    Control/Inst/Inst_Tempo.h \
    Control/ModInst/f_ModInst_Tempo.h \
    Control/Inst/Inst_Com.h \
    Control/ModInst/f_ModInst_Com.h \
    Control/Inst/Inst_Boucle.h \
    Control/ModInst/f_ModInst_Boucle.h \
    Control/Inst/Inst_EP.h \
    Control/ModInst/f_ModInst_EP.h \
    Control/Inst/Inst_DebFin.h \
    Interface/BtnItem.h \
    Interface/f_InterpreteurCommandes.h \
    Interface/Arduino.h \
    Interface/f_GestionMem.h \
    Interface/InterpreteurFichierIni.h \
    Interface/f_SaisieNom.h \
    Interface/f_ConfigI2C.h \
    Interface/f_Compilation.h \
    Supervision/f_SubWindow.h \
    Supervision/f_Supervision.h \
    Supervision/f_WidgetInterne.h \
    Supervision/f_AffichageFenetre.h \
    Supervision/Widgets/WidgetNI.h \
    Supervision/Switch.h \
    Supervision/Widgets/WidgetNO.h \
    Supervision/Widgets/WidgetAI.h \
    Supervision/Widgets/WidgetMOT1.h \
    SupervisionWeb/Serveur/RequeteMapper.h \
    SupervisionWeb/Serveur/Serveur.h \
    SupervisionWeb/Web/src/Donnees.h \
    Vue/Vue.h \
    Vue/Scene.h \
    Vue/Item.h \
    Vue/Item/Item_DebFin.h \
    Vue/Item/Item_Ope.h \
    Vue/Item/Item_Cond.h \
    Vue/Item/Item_ES.h \
    Vue/Item/Item_Rout.h \
    Vue/Item/Item_Tempo.h \
    Vue/Item/Item_Com.h \
    Vue/Item/Item_Boucle.h \
    Vue/Item/Item_ExecPara.h \
    Vue/Fleche.h \
    Vue/MarqueurDrop.h

FORMS    += f_MainWindow.ui \
    Interface/f_InterpreteurCommandes.ui \
    ConfigurationMaquette/f_DefinirActionsEtTests.ui \
    ConfigurationMaquette/f_RealiserPlanCablage.ui \
    ConfigurationAppli/f_Configuration.ui \
    ConfigurationAppli/f_CreerProfil.ui \
    ConfigurationAppli/f_ChoixProfil.ui \
    ConfigurationAppli/f_SupprimerProfil.ui \
    ConfigurationAppli/f_APropos.ui \
    Control/ModInst/f_ModInst_Ope.ui \
    Control/ModInst/f_ModInst_Cond.ui \
    Control/ModInst/f_ModInst_ES.ui \
    Control/ModInst/f_ModInst_Rout.ui \
    ConfigurationAppli/f_ModifierProfil.ui \
    Control/ModInst/f_ModInst_Tempo.ui \
    Control/ModInst/f_ModInst_Com.ui \
    Control/ModInst/f_ModInst_Boucle.ui \
    Interface/f_GestionMem.ui \
    Interface/f_SaisieNom.ui \
    Interface/f_ConfigI2C.ui \
    Interface/f_Compilation.ui \
    ConfigurationMaquette/f_ChoixControleur.ui \
    ConfigurationMaquette/f_ChoixInterface.ui \
    ConfigurationMaquette/f_ChoixModules.ui \
    ConfigurationMaquette/DefinirActionsEtTests/f_EditerActionTest.ui \
    Control/ModInst/f_ModInst_EP.ui \
    Supervision/f_Supervision.ui


RESOURCES += \
    ressources.qrc \
    Supervision.qrc

RC_FILE += OpenOrganigram.rc

OTHER_FILES += SupervisionWeb/Web/etc/* SupervisionWeb/Web/etc/www/*
