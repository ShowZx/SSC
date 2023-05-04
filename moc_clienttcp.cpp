/****************************************************************************
** Meta object code from reading C++ file 'clienttcp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clienttcp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clienttcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientTcp_t {
    QByteArrayData data[16];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientTcp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientTcp_t qt_meta_stringdata_ClientTcp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ClientTcp"
QT_MOC_LITERAL(1, 10, 14), // "emettreMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "Message"
QT_MOC_LITERAL(4, 34, 11), // "emettreData"
QT_MOC_LITERAL(5, 46, 4), // "data"
QT_MOC_LITERAL(6, 51, 11), // "emettreDate"
QT_MOC_LITERAL(7, 63, 9), // "_datetime"
QT_MOC_LITERAL(8, 73, 12), // "lire_Message"
QT_MOC_LITERAL(9, 86, 14), // "Ecrire_Message"
QT_MOC_LITERAL(10, 101, 9), // "Connexion"
QT_MOC_LITERAL(11, 111, 2), // "ip"
QT_MOC_LITERAL(12, 114, 4), // "port"
QT_MOC_LITERAL(13, 119, 11), // "ConnexionOk"
QT_MOC_LITERAL(14, 131, 11), // "Deconnexion"
QT_MOC_LITERAL(15, 143, 8) // "Acquerir"

    },
    "ClientTcp\0emettreMessage\0\0Message\0"
    "emettreData\0data\0emettreDate\0_datetime\0"
    "lire_Message\0Ecrire_Message\0Connexion\0"
    "ip\0port\0ConnexionOk\0Deconnexion\0"
    "Acquerir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientTcp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   78,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
       9,    1,   80,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x0a /* Public */,
      10,    2,   86,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    0,   92,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientTcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientTcp *_t = static_cast<ClientTcp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emettreMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->emettreData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->emettreDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->lire_Message(); break;
        case 4: _t->Ecrire_Message(); break;
        case 5: _t->Ecrire_Message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->Ecrire_Message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->Connexion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->ConnexionOk(); break;
        case 9: _t->Deconnexion(); break;
        case 10: _t->Acquerir(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientTcp::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientTcp::emettreMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClientTcp::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientTcp::emettreData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ClientTcp::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientTcp::emettreDate)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ClientTcp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientTcp.data,
      qt_meta_data_ClientTcp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientTcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientTcp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientTcp.stringdata0))
        return static_cast<void*>(const_cast< ClientTcp*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientTcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ClientTcp::emettreMessage(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientTcp::emettreData(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientTcp::emettreDate(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
