/****************************************************************************
** Meta object code from reading C++ file 'f_ChoixControleur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ConfigurationMaquette/f_ChoixControleur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_ChoixControleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_ChoixControleur_t {
    QByteArrayData data[6];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_ChoixControleur_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_ChoixControleur_t qt_meta_stringdata_f_ChoixControleur = {
    {
QT_MOC_LITERAL(0, 0, 17), // "f_ChoixControleur"
QT_MOC_LITERAL(1, 18, 36), // "on_CB_Controleur_currentIndex..."
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 4), // "arg1"
QT_MOC_LITERAL(4, 61, 19), // "on_Btn_Suiv_clicked"
QT_MOC_LITERAL(5, 81, 27) // "on_LE_NomProjet_textChanged"

    },
    "f_ChoixControleur\0"
    "on_CB_Controleur_currentIndexChanged\0"
    "\0arg1\0on_Btn_Suiv_clicked\0"
    "on_LE_NomProjet_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_ChoixControleur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void f_ChoixControleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_ChoixControleur *_t = static_cast<f_ChoixControleur *>(_o);
        switch (_id) {
        case 0: _t->on_CB_Controleur_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_Btn_Suiv_clicked(); break;
        case 2: _t->on_LE_NomProjet_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject f_ChoixControleur::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_f_ChoixControleur.data,
      qt_meta_data_f_ChoixControleur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_ChoixControleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_ChoixControleur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_ChoixControleur.stringdata))
        return static_cast<void*>(const_cast< f_ChoixControleur*>(this));
    return QDialog::qt_metacast(_clname);
}

int f_ChoixControleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
