/****************************************************************************
** Meta object code from reading C++ file 'f_ModInst_Rout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Control/ModInst/f_ModInst_Rout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_ModInst_Rout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_ModInst_Rout_t {
    QByteArrayData data[6];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_ModInst_Rout_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_ModInst_Rout_t qt_meta_stringdata_f_ModInst_Rout = {
    {
QT_MOC_LITERAL(0, 0, 14), // "f_ModInst_Rout"
QT_MOC_LITERAL(1, 15, 22), // "on_Liste_doubleClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "index"
QT_MOC_LITERAL(4, 45, 20), // "on_Btn_Suppr_clicked"
QT_MOC_LITERAL(5, 66, 20) // "on_Btn_Ajout_clicked"

    },
    "f_ModInst_Rout\0on_Liste_doubleClicked\0"
    "\0index\0on_Btn_Suppr_clicked\0"
    "on_Btn_Ajout_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_ModInst_Rout[] = {

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
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void f_ModInst_Rout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_ModInst_Rout *_t = static_cast<f_ModInst_Rout *>(_o);
        switch (_id) {
        case 0: _t->on_Liste_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_Btn_Suppr_clicked(); break;
        case 2: _t->on_Btn_Ajout_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject f_ModInst_Rout::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_f_ModInst_Rout.data,
      qt_meta_data_f_ModInst_Rout,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_ModInst_Rout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_ModInst_Rout::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_ModInst_Rout.stringdata))
        return static_cast<void*>(const_cast< f_ModInst_Rout*>(this));
    return QDialog::qt_metacast(_clname);
}

int f_ModInst_Rout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
