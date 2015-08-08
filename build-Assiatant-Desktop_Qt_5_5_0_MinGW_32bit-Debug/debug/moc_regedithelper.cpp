/****************************************************************************
** Meta object code from reading C++ file 'regedithelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Assiatant/regedithelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regedithelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_regeditHelper_t {
    QByteArrayData data[11];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_regeditHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_regeditHelper_t qt_meta_stringdata_regeditHelper = {
    {
QT_MOC_LITERAL(0, 0, 13), // "regeditHelper"
QT_MOC_LITERAL(1, 14, 17), // "getetInfoFinished"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 27), // "vector<pair<QString,bool> >"
QT_MOC_LITERAL(4, 61, 4), // "list"
QT_MOC_LITERAL(5, 66, 7), // "refresh"
QT_MOC_LITERAL(6, 74, 15), // "refreshListView"
QT_MOC_LITERAL(7, 90, 13), // "removeRegItem"
QT_MOC_LITERAL(8, 104, 4), // "name"
QT_MOC_LITERAL(9, 109, 10), // "addRegItem"
QT_MOC_LITERAL(10, 120, 13) // "enableRegItem"

    },
    "regeditHelper\0getetInfoFinished\0\0"
    "vector<pair<QString,bool> >\0list\0"
    "refresh\0refreshListView\0removeRegItem\0"
    "name\0addRegItem\0enableRegItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_regeditHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,
       9,    1,   52,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void regeditHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        regeditHelper *_t = static_cast<regeditHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getetInfoFinished((*reinterpret_cast< vector<pair<QString,bool> >(*)>(_a[1]))); break;
        case 1: _t->refresh(); break;
        case 2: _t->refreshListView(); break;
        case 3: _t->removeRegItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->addRegItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->enableRegItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (regeditHelper::*_t)(vector<pair<QString,bool>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&regeditHelper::getetInfoFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (regeditHelper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&regeditHelper::refresh)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject regeditHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_regeditHelper.data,
      qt_meta_data_regeditHelper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *regeditHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *regeditHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_regeditHelper.stringdata0))
        return static_cast<void*>(const_cast< regeditHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int regeditHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void regeditHelper::getetInfoFinished(vector<pair<QString,bool>> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void regeditHelper::refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
