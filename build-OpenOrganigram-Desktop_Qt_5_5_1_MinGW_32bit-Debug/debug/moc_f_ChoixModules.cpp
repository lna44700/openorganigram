/****************************************************************************
** Meta object code from reading C++ file 'f_ChoixModules.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ConfigurationMaquette/f_ChoixModules.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_ChoixModules.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_ChoixModules_t {
    QByteArrayData data[6];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_ChoixModules_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_ChoixModules_t qt_meta_stringdata_f_ChoixModules = {
    {
QT_MOC_LITERAL(0, 0, 14), // "f_ChoixModules"
QT_MOC_LITERAL(1, 15, 22), // "on_Btn_Ajouter_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 20), // "on_Btn_Suppr_clicked"
QT_MOC_LITERAL(4, 60, 19), // "on_Btn_Suiv_clicked"
QT_MOC_LITERAL(5, 80, 19) // "on_Btn_Prec_clicked"

    },
    "f_ChoixModules\0on_Btn_Ajouter_clicked\0"
    "\0on_Btn_Suppr_clicked\0on_Btn_Suiv_clicked\0"
    "on_Btn_Prec_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_ChoixModules[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void f_ChoixModules::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_ChoixModules *_t = static_cast<f_ChoixModules *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Btn_Ajouter_clicked(); break;
        case 1: _t->on_Btn_Suppr_clicked(); break;
        case 2: _t->on_Btn_Suiv_clicked(); break;
        case 3: _t->on_Btn_Prec_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject f_ChoixModules::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_f_ChoixModules.data,
      qt_meta_data_f_ChoixModules,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_ChoixModules::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_ChoixModules::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_ChoixModules.stringdata0))
        return static_cast<void*>(const_cast< f_ChoixModules*>(this));
    return QDialog::qt_metacast(_clname);
}

int f_ChoixModules::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
