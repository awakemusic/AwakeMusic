/****************************************************************************
** Meta object code from reading C++ file 'musicmainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/application/musicmainwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicmainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicMainWidget_t {
    QByteArrayData data[11];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicMainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicMainWidget_t qt_meta_stringdata_MusicMainWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MusicMainWidget"
QT_MOC_LITERAL(1, 16, 18), // "slotShowSkinWidget"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "slotShowMin"
QT_MOC_LITERAL(4, 48, 9), // "slotClose"
QT_MOC_LITERAL(5, 58, 17), // "slotPreviousMusic"
QT_MOC_LITERAL(6, 76, 15), // "slotPlayOrPause"
QT_MOC_LITERAL(7, 92, 13), // "slotNextMusic"
QT_MOC_LITERAL(8, 106, 22), // "slotPlayProgressChange"
QT_MOC_LITERAL(9, 129, 24), // "slotShowOrHideDesktopLrc"
QT_MOC_LITERAL(10, 154, 8) // "slotTest"

    },
    "MusicMainWidget\0slotShowSkinWidget\0\0"
    "slotShowMin\0slotClose\0slotPreviousMusic\0"
    "slotPlayOrPause\0slotNextMusic\0"
    "slotPlayProgressChange\0slotShowOrHideDesktopLrc\0"
    "slotTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicMainWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       6,    1,   65,    2, 0x08 /* Private */,
       7,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void MusicMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicMainWidget *_t = static_cast<MusicMainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotShowSkinWidget(); break;
        case 1: _t->slotShowMin(); break;
        case 2: _t->slotClose(); break;
        case 3: _t->slotPreviousMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slotPlayOrPause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotNextMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->slotPlayProgressChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotShowOrHideDesktopLrc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotTest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MusicMainWidget::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_MusicMainWidget.data,
    qt_meta_data_MusicMainWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicMainWidget.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int MusicMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
