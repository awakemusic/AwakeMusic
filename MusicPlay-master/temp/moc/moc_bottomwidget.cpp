/****************************************************************************
** Meta object code from reading C++ file 'bottomwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/BottomBar/bottomwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottomwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BottomWidget_t {
    QByteArrayData data[23];
    char stringdata0[396];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BottomWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BottomWidget_t qt_meta_stringdata_BottomWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BottomWidget"
QT_MOC_LITERAL(1, 13, 19), // "signalPreviousMusic"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "signalPlayOrPause"
QT_MOC_LITERAL(4, 52, 15), // "signalNextMusic"
QT_MOC_LITERAL(5, 68, 24), // "signalPlayProgressChange"
QT_MOC_LITERAL(6, 93, 19), // "signalHidOrShowLyrc"
QT_MOC_LITERAL(7, 113, 20), // "signalSendPlayVolume"
QT_MOC_LITERAL(8, 134, 21), // "signalSendPlayPostion"
QT_MOC_LITERAL(9, 156, 13), // "signalPlayCmd"
QT_MOC_LITERAL(10, 170, 16), // "signalShowOrHide"
QT_MOC_LITERAL(11, 187, 21), // "slotReceivePlayLength"
QT_MOC_LITERAL(12, 209, 17), // "slotSetPlayVolume"
QT_MOC_LITERAL(13, 227, 22), // "slotReceivePlayPostion"
QT_MOC_LITERAL(14, 250, 13), // "slotShowImage"
QT_MOC_LITERAL(15, 264, 5), // "image"
QT_MOC_LITERAL(16, 270, 15), // "slotPlayOrPause"
QT_MOC_LITERAL(17, 286, 18), // "slotSetPlayOrPause"
QT_MOC_LITERAL(18, 305, 11), // "slotNoVoice"
QT_MOC_LITERAL(19, 317, 18), // "slotShowOrHideLyrc"
QT_MOC_LITERAL(20, 336, 14), // "slotVoiceValue"
QT_MOC_LITERAL(21, 351, 21), // "slotPlayPostionChange"
QT_MOC_LITERAL(22, 373, 22) // "slotChangePlayModeIcon"

    },
    "BottomWidget\0signalPreviousMusic\0\0"
    "signalPlayOrPause\0signalNextMusic\0"
    "signalPlayProgressChange\0signalHidOrShowLyrc\0"
    "signalSendPlayVolume\0signalSendPlayPostion\0"
    "signalPlayCmd\0signalShowOrHide\0"
    "slotReceivePlayLength\0slotSetPlayVolume\0"
    "slotReceivePlayPostion\0slotShowImage\0"
    "image\0slotPlayOrPause\0slotSetPlayOrPause\0"
    "slotNoVoice\0slotShowOrHideLyrc\0"
    "slotVoiceValue\0slotPlayPostionChange\0"
    "slotChangePlayModeIcon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BottomWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    1,  115,    2, 0x06 /* Public */,
       4,    0,  118,    2, 0x06 /* Public */,
       5,    1,  119,    2, 0x06 /* Public */,
       6,    1,  122,    2, 0x06 /* Public */,
       7,    1,  125,    2, 0x06 /* Public */,
       8,    1,  128,    2, 0x06 /* Public */,
       9,    1,  131,    2, 0x06 /* Public */,
      10,    0,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  135,    2, 0x0a /* Public */,
      12,    1,  138,    2, 0x0a /* Public */,
      13,    1,  141,    2, 0x0a /* Public */,
      14,    1,  144,    2, 0x0a /* Public */,
      16,    0,  147,    2, 0x08 /* Private */,
      17,    1,  148,    2, 0x08 /* Private */,
      18,    0,  151,    2, 0x08 /* Private */,
      19,    0,  152,    2, 0x08 /* Private */,
      20,    1,  153,    2, 0x08 /* Private */,
      21,    1,  156,    2, 0x08 /* Private */,
      22,    1,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::QImage,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void BottomWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BottomWidget *_t = static_cast<BottomWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPreviousMusic(); break;
        case 1: _t->signalPlayOrPause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalNextMusic(); break;
        case 3: _t->signalPlayProgressChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signalHidOrShowLyrc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalSendPlayVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signalSendPlayPostion((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->signalPlayCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->signalShowOrHide(); break;
        case 9: _t->slotReceivePlayLength((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->slotSetPlayVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotReceivePlayPostion((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: _t->slotShowImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 13: _t->slotPlayOrPause(); break;
        case 14: _t->slotSetPlayOrPause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->slotNoVoice(); break;
        case 16: _t->slotShowOrHideLyrc(); break;
        case 17: _t->slotVoiceValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->slotPlayPostionChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->slotChangePlayModeIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BottomWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalPreviousMusic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalPlayOrPause)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalNextMusic)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalPlayProgressChange)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalHidOrShowLyrc)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalSendPlayVolume)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalSendPlayPostion)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalPlayCmd)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BottomWidget::signalShowOrHide)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BottomWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_BottomWidget.data,
    qt_meta_data_BottomWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BottomWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BottomWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BottomWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BottomWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void BottomWidget::signalPreviousMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BottomWidget::signalPlayOrPause(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BottomWidget::signalNextMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BottomWidget::signalPlayProgressChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BottomWidget::signalHidOrShowLyrc(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BottomWidget::signalSendPlayVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BottomWidget::signalSendPlayPostion(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void BottomWidget::signalPlayCmd(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void BottomWidget::signalShowOrHide()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
