/****************************************************************************
** Meta object code from reading C++ file 'f_InterpreteurCommandes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Interface/f_InterpreteurCommandes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'f_InterpreteurCommandes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_f_InterpreteurCommandes_t {
    QByteArrayData data[14];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_f_InterpreteurCommandes_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_f_InterpreteurCommandes_t qt_meta_stringdata_f_InterpreteurCommandes = {
    {
QT_MOC_LITERAL(0, 0, 23), // "f_InterpreteurCommandes"
QT_MOC_LITERAL(1, 24, 15), // "EnvoyerDonneesL"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "Commande"
QT_MOC_LITERAL(4, 50, 16), // "EmetteurCommande"
QT_MOC_LITERAL(5, 67, 8), // "Emetteur"
QT_MOC_LITERAL(6, 76, 16), // "RecevoirDonneesL"
QT_MOC_LITERAL(7, 93, 13), // "DonneesRecues"
QT_MOC_LITERAL(8, 107, 14), // "ArduinoConnect"
QT_MOC_LITERAL(9, 122, 5), // "nEtat"
QT_MOC_LITERAL(10, 128, 4), // "sCOM"
QT_MOC_LITERAL(11, 133, 24), // "on_BoutonValider_clicked"
QT_MOC_LITERAL(12, 158, 13), // "Signal_TempsL"
QT_MOC_LITERAL(13, 172, 14) // "Incrementation"

    },
    "f_InterpreteurCommandes\0EnvoyerDonneesL\0"
    "\0Commande\0EmetteurCommande\0Emetteur\0"
    "RecevoirDonneesL\0DonneesRecues\0"
    "ArduinoConnect\0nEtat\0sCOM\0"
    "on_BoutonValider_clicked\0Signal_TempsL\0"
    "Incrementation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_f_InterpreteurCommandes[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   44,    2, 0x0a /* Public */,
       8,    2,   47,    2, 0x0a /* Public */,
      11,    0,   52,    2, 0x08 /* Private */,
      12,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   13,

       0        // eod
};

void f_InterpreteurCommandes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        f_InterpreteurCommandes *_t = static_cast<f_InterpreteurCommandes *>(_o);
        switch (_id) {
        case 0: _t->EnvoyerDonneesL((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EmetteurCommande(*)>(_a[2]))); break;
        case 1: _t->RecevoirDonneesL((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->ArduinoConnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_BoutonValider_clicked(); break;
        case 4: _t->Signal_TempsL((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (f_InterpreteurCommandes::*_t)(QString , EmetteurCommande );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&f_InterpreteurCommandes::EnvoyerDonneesL)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject f_InterpreteurCommandes::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_f_InterpreteurCommandes.data,
      qt_meta_data_f_InterpreteurCommandes,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *f_InterpreteurCommandes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *f_InterpreteurCommandes::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_f_InterpreteurCommandes.stringdata))
        return static_cast<void*>(const_cast< f_InterpreteurCommandes*>(this));
    return QDialog::qt_metacast(_clname);
}

int f_InterpreteurCommandes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void f_InterpreteurCommandes::EnvoyerDonneesL(QString _t1, EmetteurCommande _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
