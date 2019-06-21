/****************************************************************************
** Meta object code from reading C++ file 'musiclyrcwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/ContentWidget/MusisLyrc/musiclyrcwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musiclyrcwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicLyrcWidget_t {
    QByteArrayData data[7];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicLyrcWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicLyrcWidget_t qt_meta_stringdata_MusicLyrcWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MusicLyrcWidget"
QT_MOC_LITERAL(1, 16, 13), // "signalHideLrc"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "slotReceiveMusicInfo"
QT_MOC_LITERAL(4, 52, 4), // "name"
QT_MOC_LITERAL(5, 57, 26), // "slotReceiveCurrentPlayTime"
QT_MOC_LITERAL(6, 84, 16) // "slotAnalyseMedia"

    },
    "MusicLyrcWidget\0signalHideLrc\0\0"
    "slotReceiveMusicInfo\0name\0"
    "slotReceiveCurrentPlayTime\0slotAnalyseMedia"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicLyrcWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void MusicLyrcWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicLyrcWidget *_t = static_cast<MusicLyrcWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalHideLrc(); break;
        case 1: _t->slotReceiveMusicInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slotReceiveCurrentPlayTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->slotAnalyseMedia((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicLyrcWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicLyrcWidget::signalHideLrc)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MusicLyrcWidget::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_MusicLyrcWidget.data,
    qt_meta_data_MusicLyrcWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicLyrcWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicLyrcWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicLyrcWidget.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int MusicLyrcWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void MusicLyrcWidget::signalHideLrc()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
