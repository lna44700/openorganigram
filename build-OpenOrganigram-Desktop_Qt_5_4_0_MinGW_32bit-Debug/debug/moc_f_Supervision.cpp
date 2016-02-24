/****************************************************************************
** Meta object code from reading C++ file 'f_Supervision.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Supervision/f_Supervision.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_Supervision.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_Supervision_t {
    QByteArrayData data[11];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_Supervision_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_Supervision_t qt_meta_stringdata_f_Supervision = {
    {
QT_MOC_LITERAL(0, 0, 13), // "f_Supervision"
QT_MOC_LITERAL(1, 14, 14), // "RetourCommande"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "ValeurRetour"
QT_MOC_LITERAL(4, 43, 22), // "EmplacementSupervision"
QT_MOC_LITERAL(5, 66, 18), // "Qt::DockWidgetArea"
QT_MOC_LITERAL(6, 85, 3), // "Loc"
QT_MOC_LITERAL(7, 89, 21), // "on_BtAfficher_clicked"
QT_MOC_LITERAL(8, 111, 13), // "on_TempsFinit"
QT_MOC_LITERAL(9, 125, 23), // "on_BtHorizontal_clicked"
QT_MOC_LITERAL(10, 149, 21) // "on_BtVertical_clicked"

    },
    "f_Supervision\0RetourCommande\0\0"
    "ValeurRetour\0EmplacementSupervision\0"
    "Qt::DockWidgetArea\0Loc\0on_BtAfficher_clicked\0"
    "on_TempsFinit\0on_BtHorizontal_clicked\0"
    "on_BtVertical_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_Supervision[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void f_Supervision::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_Supervision *_t = static_cast<f_Supervision *>(_o);
        switch (_id) {
        case 0: _t->RetourCommande((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->EmplacementSupervision((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 2: _t->on_BtAfficher_clicked(); break;
        case 3: _t->on_TempsFinit(); break;
        case 4: _t->on_BtHorizontal_clicked(); break;
        case 5: _t->on_BtVertical_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject f_Supervision::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_f_Supervision.data,
      qt_meta_data_f_Supervision,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_Supervision::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_Supervision::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_Supervision.stringdata))
        return static_cast<void*>(const_cast< f_Supervision*>(this));
    return QWidget::qt_metacast(_clname);
}

int f_Supervision::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
