/****************************************************************************
** Meta object code from reading C++ file 'Arduino.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Interface/Arduino.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QQueue>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Arduino.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Arduino_t {
    QByteArrayData data[28];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Arduino_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Arduino_t qt_meta_stringdata_Arduino = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Arduino"
QT_MOC_LITERAL(1, 8, 14), // "ArduinoConnect"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "nEtat"
QT_MOC_LITERAL(4, 30, 4), // "sCOM"
QT_MOC_LITERAL(5, 35, 12), // "DonneesALire"
QT_MOC_LITERAL(6, 48, 7), // "Donnees"
QT_MOC_LITERAL(7, 56, 25), // "RetourCommandeSupervision"
QT_MOC_LITERAL(8, 82, 15), // "ValeurRetourSup"
QT_MOC_LITERAL(9, 98, 24), // "RetourCommandeOrganigram"
QT_MOC_LITERAL(10, 123, 15), // "ValeurRetourOrg"
QT_MOC_LITERAL(11, 139, 12), // "Signal_Temps"
QT_MOC_LITERAL(12, 152, 14), // "Incrementation"
QT_MOC_LITERAL(13, 167, 28), // "RetourCommandeSupervisionWEB"
QT_MOC_LITERAL(14, 196, 15), // "QQueue<QString>"
QT_MOC_LITERAL(15, 212, 25), // "QueueRetourCommandeSupWeb"
QT_MOC_LITERAL(16, 238, 22), // "RetourCommandeGenerale"
QT_MOC_LITERAL(17, 261, 15), // "ValeurRetourGen"
QT_MOC_LITERAL(18, 277, 14), // "EnvoyerDonnees"
QT_MOC_LITERAL(19, 292, 9), // "sCommande"
QT_MOC_LITERAL(20, 302, 16), // "EmetteurCommande"
QT_MOC_LITERAL(21, 319, 8), // "Emetteur"
QT_MOC_LITERAL(22, 328, 15), // "RecevoirDonnees"
QT_MOC_LITERAL(23, 344, 13), // "RemplirTampon"
QT_MOC_LITERAL(24, 358, 7), // "Tableau"
QT_MOC_LITERAL(25, 366, 8), // "Detecter"
QT_MOC_LITERAL(26, 375, 24), // "RetourCommandeSimulation"
QT_MOC_LITERAL(27, 400, 15) // "UtiliserArduino"

    },
    "Arduino\0ArduinoConnect\0\0nEtat\0sCOM\0"
    "DonneesALire\0Donnees\0RetourCommandeSupervision\0"
    "ValeurRetourSup\0RetourCommandeOrganigram\0"
    "ValeurRetourOrg\0Signal_Temps\0"
    "Incrementation\0RetourCommandeSupervisionWEB\0"
    "QQueue<QString>\0QueueRetourCommandeSupWeb\0"
    "RetourCommandeGenerale\0ValeurRetourGen\0"
    "EnvoyerDonnees\0sCommande\0EmetteurCommande\0"
    "Emetteur\0RecevoirDonnees\0RemplirTampon\0"
    "Tableau\0Detecter\0RetourCommandeSimulation\0"
    "UtiliserArduino"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Arduino[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    1,   89,    2, 0x06 /* Public */,
       7,    1,   92,    2, 0x06 /* Public */,
       9,    1,   95,    2, 0x06 /* Public */,
      11,    1,   98,    2, 0x06 /* Public */,
      13,    1,  101,    2, 0x06 /* Public */,
      16,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    2,  107,    2, 0x0a /* Public */,
      18,    2,  112,    2, 0x0a /* Public */,
      22,    0,  117,    2, 0x0a /* Public */,
      23,    1,  118,    2, 0x0a /* Public */,
      25,    0,  121,    2, 0x08 /* Private */,
      26,    0,  122,    2, 0x08 /* Private */,
      27,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QTime,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QByteArray,   17,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 20,   19,   21,
    QMetaType::Bool, QMetaType::QByteArray, 0x80000000 | 20,   19,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Arduino::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Arduino *_t = static_cast<Arduino *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ArduinoConnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->DonneesALire((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->RetourCommandeSupervision((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->RetourCommandeOrganigram((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->Signal_Temps((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 5: _t->RetourCommandeSupervisionWEB((*reinterpret_cast< QQueue<QString>(*)>(_a[1]))); break;
        case 6: _t->RetourCommandeGenerale((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: { bool _r = _t->EnvoyerDonnees((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EmetteurCommande(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->EnvoyerDonnees((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< EmetteurCommande(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->RecevoirDonnees(); break;
        case 10: _t->RemplirTampon((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->Detecter(); break;
        case 12: _t->RetourCommandeSimulation(); break;
        case 13: _t->UtiliserArduino(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQueue<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Arduino::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::ArduinoConnect)) {
                *result = 0;
            }
        }
        {
            typedef void (Arduino::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::DonneesALire)) {
                *result = 1;
            }
        }
        {
            typedef void (Arduino::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::RetourCommandeSupervision)) {
                *result = 2;
            }
        }
        {
            typedef void (Arduino::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::RetourCommandeOrganigram)) {
                *result = 3;
            }
        }
        {
            typedef void (Arduino::*_t)(QTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::Signal_Temps)) {
                *result = 4;
            }
        }
        {
            typedef void (Arduino::*_t)(QQueue<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::RetourCommandeSupervisionWEB)) {
                *result = 5;
            }
        }
        {
            typedef void (Arduino::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::RetourCommandeGenerale)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject Arduino::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Arduino.data,
      qt_meta_data_Arduino,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Arduino::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Arduino::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Arduino.stringdata0))
        return static_cast<void*>(const_cast< Arduino*>(this));
    return QObject::qt_metacast(_clname);
}

int Arduino::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Arduino::ArduinoConnect(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Arduino::DonneesALire(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Arduino::RetourCommandeSupervision(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Arduino::RetourCommandeOrganigram(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Arduino::Signal_Temps(QTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Arduino::RetourCommandeSupervisionWEB(QQueue<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Arduino::RetourCommandeGenerale(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
