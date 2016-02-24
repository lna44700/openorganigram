/****************************************************************************
** Meta object code from reading C++ file 'f_Compilation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Interface/f_Compilation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_Compilation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_Compilation_t {
    QByteArrayData data[10];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_Compilation_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_Compilation_t qt_meta_stringdata_f_Compilation = {
    {
QT_MOC_LITERAL(0, 0, 13), // "f_Compilation"
QT_MOC_LITERAL(1, 14, 32), // "on_CB_Module_currentIndexChanged"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 23), // "on_Btn_Compiler_clicked"
QT_MOC_LITERAL(4, 72, 14), // "slot_EtatSlots"
QT_MOC_LITERAL(5, 87, 14), // "slot_Transfert"
QT_MOC_LITERAL(6, 102, 14), // "RetourCommande"
QT_MOC_LITERAL(7, 117, 6), // "Retour"
QT_MOC_LITERAL(8, 124, 22), // "on_Btn_Envoyer_clicked"
QT_MOC_LITERAL(9, 147, 16) // "NouvelleImageGif"

    },
    "f_Compilation\0on_CB_Module_currentIndexChanged\0"
    "\0on_Btn_Compiler_clicked\0slot_EtatSlots\0"
    "slot_Transfert\0RetourCommande\0Retour\0"
    "on_Btn_Envoyer_clicked\0NouvelleImageGif"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_Compilation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       3,    0,   52,    2, 0x08 /* Private */,
       4,    0,   53,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    1,   55,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void f_Compilation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_Compilation *_t = static_cast<f_Compilation *>(_o);
        switch (_id) {
        case 0: _t->on_CB_Module_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_Btn_Compiler_clicked(); break;
        case 2: _t->slot_EtatSlots(); break;
        case 3: _t->slot_Transfert(); break;
        case 4: _t->RetourCommande((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->on_Btn_Envoyer_clicked(); break;
        case 6: _t->NouvelleImageGif((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject f_Compilation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_f_Compilation.data,
      qt_meta_data_f_Compilation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_Compilation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_Compilation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_Compilation.stringdata))
        return static_cast<void*>(const_cast< f_Compilation*>(this));
    return QDialog::qt_metacast(_clname);
}

int f_Compilation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
