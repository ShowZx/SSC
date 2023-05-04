/****************************************************************************
** Meta object code from reading C++ file 'sgbd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sgbd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sgbd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SGBD_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SGBD_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SGBD_t qt_meta_stringdata_SGBD = {
    {
QT_MOC_LITERAL(0, 0, 4), // "SGBD"
QT_MOC_LITERAL(1, 5, 15), // "DatabaseConnect"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "QSqlDatabase&"
QT_MOC_LITERAL(4, 36, 3), // "db_"
QT_MOC_LITERAL(5, 40, 15), // "DatabaseSelectS"
QT_MOC_LITERAL(6, 56, 14), // "DatabaseRecord"
QT_MOC_LITERAL(7, 71, 5), // "value"
QT_MOC_LITERAL(8, 77, 15), // "DatabaseSelectR"
QT_MOC_LITERAL(9, 93, 19) // "DatabaseDeconnecter"

    },
    "SGBD\0DatabaseConnect\0\0QSqlDatabase&\0"
    "db_\0DatabaseSelectS\0DatabaseRecord\0"
    "value\0DatabaseSelectR\0DatabaseDeconnecter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SGBD[] = {

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
       1,    0,   44,    2, 0x0a /* Public */,
       1,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SGBD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SGBD *_t = static_cast<SGBD *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DatabaseConnect(); break;
        case 1: _t->DatabaseConnect((*reinterpret_cast< QSqlDatabase(*)>(_a[1]))); break;
        case 2: _t->DatabaseSelectS(); break;
        case 3: _t->DatabaseRecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->DatabaseSelectR(); break;
        case 5: _t->DatabaseDeconnecter(); break;
        default: ;
        }
    }
}

const QMetaObject SGBD::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SGBD.data,
      qt_meta_data_SGBD,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SGBD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SGBD::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SGBD.stringdata0))
        return static_cast<void*>(const_cast< SGBD*>(this));
    return QObject::qt_metacast(_clname);
}

int SGBD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
