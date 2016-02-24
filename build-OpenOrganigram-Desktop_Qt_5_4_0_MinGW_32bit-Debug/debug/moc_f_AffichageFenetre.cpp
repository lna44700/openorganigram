/****************************************************************************
** Meta object code from reading C++ file 'f_AffichageFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Supervision/f_AffichageFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_AffichageFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_AffichageFenetre_t {
    QByteArrayData data[5];
    char stringdata[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_AffichageFenetre_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_AffichageFenetre_t qt_meta_stringdata_f_AffichageFenetre = {
    {
QT_MOC_LITERAL(0, 0, 18), // "f_AffichageFenetre"
QT_MOC_LITERAL(1, 19, 16), // "slot_itemChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "QStandardItem*"
QT_MOC_LITERAL(4, 52, 4) // "item"

    },
    "f_AffichageFenetre\0slot_itemChanged\0"
    "\0QStandardItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_AffichageFenetre[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void f_AffichageFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_AffichageFenetre *_t = static_cast<f_AffichageFenetre *>(_o);
        switch (_id) {
        case 0: _t->slot_itemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject f_AffichageFenetre::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_f_AffichageFenetre.data,
      qt_meta_data_f_AffichageFenetre,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_AffichageFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_AffichageFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_AffichageFenetre.stringdata))
        return static_cast<void*>(const_cast< f_AffichageFenetre*>(this));
    return QDialog::qt_metacast(_clname);
}

int f_AffichageFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
