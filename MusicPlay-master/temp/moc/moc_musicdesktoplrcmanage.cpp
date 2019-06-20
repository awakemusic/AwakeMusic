/****************************************************************************
** Meta object code from reading C++ file 'musicdesktoplrcmanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/DesktopLrc/musicdesktoplrcmanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicdesktoplrcmanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicDesktopLrcManage_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicDesktopLrcManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicDesktopLrcManage_t qt_meta_stringdata_MusicDesktopLrcManage = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MusicDesktopLrcManage"
QT_MOC_LITERAL(1, 22, 8), // "slotLock"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "slotClose"
QT_MOC_LITERAL(4, 42, 14), // "slotAnalyseLrc"
QT_MOC_LITERAL(5, 57, 4), // "name"
QT_MOC_LITERAL(6, 62, 20), // "slotReceiveMusicInfo"
QT_MOC_LITERAL(7, 83, 26) // "slotReceiveCurrentPlayTime"

    },
    "MusicDesktopLrcManage\0slotLock\0\0"
    "slotClose\0slotAnalyseLrc\0name\0"
    "slotReceiveMusicInfo\0slotReceiveCurrentPlayTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicDesktopLrcManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::LongLong,    2,

       0        // eod
};

void MusicDesktopLrcManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicDesktopLrcManage *_t = static_cast<MusicDesktopLrcManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotLock(); break;
        case 1: _t->slotClose(); break;
        case 2: _t->slotAnalyseLrc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotReceiveMusicInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotReceiveCurrentPlayTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MusicDesktopLrcManage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MusicDesktopLrcManage.data,
    qt_meta_data_MusicDesktopLrcManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicDesktopLrcManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicDesktopLrcManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicDesktopLrcManage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MusicDesktopLrcManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
