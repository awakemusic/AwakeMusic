/****************************************************************************
** Meta object code from reading C++ file 'contentwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/ContentWidget/contentwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contentwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Contentwidget_t {
    QByteArrayData data[27];
    char stringdata0[470];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Contentwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Contentwidget_t qt_meta_stringdata_Contentwidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Contentwidget"
QT_MOC_LITERAL(1, 14, 15), // "signalPlayMusic"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "music"
QT_MOC_LITERAL(4, 37, 20), // "signalPlayMediaMusic"
QT_MOC_LITERAL(5, 58, 4), // "path"
QT_MOC_LITERAL(6, 63, 18), // "signalSendPlayNext"
QT_MOC_LITERAL(7, 82, 23), // "signalSendPlayPreviouse"
QT_MOC_LITERAL(8, 106, 23), // "signalSendPlayNextMusic"
QT_MOC_LITERAL(9, 130, 28), // "signalSendPlayPreviouseMusic"
QT_MOC_LITERAL(10, 159, 27), // "signalRequestFirstPlayMusic"
QT_MOC_LITERAL(11, 187, 24), // "signalSendFirstPlayMusic"
QT_MOC_LITERAL(12, 212, 25), // "signalRequestPlayingMusic"
QT_MOC_LITERAL(13, 238, 24), // "signalRequestCurPlayTime"
QT_MOC_LITERAL(14, 263, 20), // "signalRequestPlayCmd"
QT_MOC_LITERAL(15, 284, 22), // "signalSendPlayCmdMusic"
QT_MOC_LITERAL(16, 307, 14), // "signalShowInfo"
QT_MOC_LITERAL(17, 322, 16), // "signalSendPinYin"
QT_MOC_LITERAL(18, 339, 25), // "slotReceiveFirstPlayMusic"
QT_MOC_LITERAL(19, 365, 11), // "slotShowLrc"
QT_MOC_LITERAL(20, 377, 11), // "slotHideLrc"
QT_MOC_LITERAL(21, 389, 12), // "slotShowList"
QT_MOC_LITERAL(22, 402, 3), // "row"
QT_MOC_LITERAL(23, 406, 14), // "slotAddNewList"
QT_MOC_LITERAL(24, 421, 14), // "slotDeleteList"
QT_MOC_LITERAL(25, 436, 14), // "slotShowOrHide"
QT_MOC_LITERAL(26, 451, 18) // "slotShowMediaSongs"

    },
    "Contentwidget\0signalPlayMusic\0\0music\0"
    "signalPlayMediaMusic\0path\0signalSendPlayNext\0"
    "signalSendPlayPreviouse\0signalSendPlayNextMusic\0"
    "signalSendPlayPreviouseMusic\0"
    "signalRequestFirstPlayMusic\0"
    "signalSendFirstPlayMusic\0"
    "signalRequestPlayingMusic\0"
    "signalRequestCurPlayTime\0signalRequestPlayCmd\0"
    "signalSendPlayCmdMusic\0signalShowInfo\0"
    "signalSendPinYin\0slotReceiveFirstPlayMusic\0"
    "slotShowLrc\0slotHideLrc\0slotShowList\0"
    "row\0slotAddNewList\0slotDeleteList\0"
    "slotShowOrHide\0slotShowMediaSongs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Contentwidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    1,  127,    2, 0x06 /* Public */,
       6,    0,  130,    2, 0x06 /* Public */,
       7,    0,  131,    2, 0x06 /* Public */,
       8,    1,  132,    2, 0x06 /* Public */,
       9,    1,  135,    2, 0x06 /* Public */,
      10,    0,  138,    2, 0x06 /* Public */,
      11,    1,  139,    2, 0x06 /* Public */,
      12,    1,  142,    2, 0x06 /* Public */,
      13,    1,  145,    2, 0x06 /* Public */,
      14,    1,  148,    2, 0x06 /* Public */,
      15,    1,  151,    2, 0x06 /* Public */,
      16,    3,  154,    2, 0x06 /* Public */,
      17,    2,  161,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  166,    2, 0x0a /* Public */,
      19,    0,  169,    2, 0x0a /* Public */,
      20,    0,  170,    2, 0x0a /* Public */,
      21,    1,  171,    2, 0x0a /* Public */,
      23,    0,  174,    2, 0x0a /* Public */,
      24,    1,  175,    2, 0x0a /* Public */,
      25,    0,  178,    2, 0x0a /* Public */,
      26,    0,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Contentwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Contentwidget *_t = static_cast<Contentwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPlayMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalPlayMediaMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalSendPlayNext(); break;
        case 3: _t->signalSendPlayPreviouse(); break;
        case 4: _t->signalSendPlayNextMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->signalSendPlayPreviouseMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->signalRequestFirstPlayMusic(); break;
        case 7: _t->signalSendFirstPlayMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->signalRequestPlayingMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->signalRequestCurPlayTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->signalRequestPlayCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->signalSendPlayCmdMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->signalShowInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 13: _t->signalSendPinYin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->slotReceiveFirstPlayMusic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->slotShowLrc(); break;
        case 16: _t->slotHideLrc(); break;
        case 17: _t->slotShowList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->slotAddNewList(); break;
        case 19: _t->slotDeleteList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->slotShowOrHide(); break;
        case 21: _t->slotShowMediaSongs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Contentwidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalPlayMusic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalPlayMediaMusic)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendPlayNext)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendPlayPreviouse)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendPlayNextMusic)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendPlayPreviouseMusic)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalRequestFirstPlayMusic)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendFirstPlayMusic)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalRequestPlayingMusic)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalRequestCurPlayTime)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalRequestPlayCmd)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendPlayCmdMusic)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalShowInfo)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Contentwidget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Contentwidget::signalSendPinYin)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Contentwidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Contentwidget.data,
    qt_meta_data_Contentwidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Contentwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Contentwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Contentwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Contentwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Contentwidget::signalPlayMusic(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Contentwidget::signalPlayMediaMusic(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Contentwidget::signalSendPlayNext()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Contentwidget::signalSendPlayPreviouse()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Contentwidget::signalSendPlayNextMusic(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Contentwidget::signalSendPlayPreviouseMusic(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Contentwidget::signalRequestFirstPlayMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Contentwidget::signalSendFirstPlayMusic(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Contentwidget::signalRequestPlayingMusic(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Contentwidget::signalRequestCurPlayTime(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Contentwidget::signalRequestPlayCmd(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Contentwidget::signalSendPlayCmdMusic(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Contentwidget::signalShowInfo(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Contentwidget::signalSendPinYin(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
