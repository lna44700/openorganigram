/****************************************************************************
** Meta object code from reading C++ file 'ModuleManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Control/ModuleManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModuleManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModuleManager_t {
    QByteArrayData data[7];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModuleManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModuleManager_t qt_meta_stringdata_ModuleManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ModuleManager"
QT_MOC_LITERAL(1, 14, 8), // "EtatExec"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 24), // "ExecuterCommandeSuivante"
QT_MOC_LITERAL(4, 49, 18), // "ExecuterARUSuivant"
QT_MOC_LITERAL(5, 68, 14), // "RetourCommande"
QT_MOC_LITERAL(6, 83, 7) // "sRetour"

    },
    "ModuleManager\0EtatExec\0\0"
    "ExecuterCommandeSuivante\0ExecuterARUSuivant\0"
    "RetourCommande\0sRetour"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModuleManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   37,    2, 0x08 /* Private */,
       4,    0,   38,    2, 0x08 /* Private */,
       5,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,

       0        // eod
};

void ModuleManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModuleManager *_t = static_cast<ModuleManager *>(_o);
        switch (_id) {
        case 0: _t->EtatExec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ExecuterCommandeSuivante(); break;
        case 2: _t->ExecuterARUSuivant(); break;
        case 3: _t->RetourCommande((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModuleManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleManager::EtatExec)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ModuleManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModuleManager.data,
      qt_meta_data_ModuleManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModuleManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModuleManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleManager.stringdata))
        return static_cast<void*>(const_cast< ModuleManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ModuleManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ModuleManager::EtatExec(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
