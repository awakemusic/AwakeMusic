/****************************************************************************
** Meta object code from reading C++ file 'titlewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/TitleBar/titlewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'titlewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TitleWidget_t {
    QByteArrayData data[8];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TitleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TitleWidget_t qt_meta_stringdata_TitleWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TitleWidget"
QT_MOC_LITERAL(1, 12, 10), // "signalSkin"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "signalMin"
QT_MOC_LITERAL(4, 34, 11), // "signalClose"
QT_MOC_LITERAL(5, 46, 19), // "signalSearchContent"
QT_MOC_LITERAL(6, 66, 4), // "test"
QT_MOC_LITERAL(7, 71, 19) // "signalSearchClicked"

    },
    "TitleWidget\0signalSkin\0\0signalMin\0"
    "signalClose\0signalSearchContent\0test\0"
    "signalSearchClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TitleWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    0,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void TitleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TitleWidget *_t = static_cast<TitleWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSkin(); break;
        case 1: _t->signalMin(); break;
        case 2: _t->signalClose(); break;
        case 3: _t->signalSearchContent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->signalSearchClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TitleWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleWidget::signalSkin)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TitleWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleWidget::signalMin)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TitleWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleWidget::signalClose)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TitleWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleWidget::signalSearchContent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TitleWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleWidget::signalSearchClicked)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TitleWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TitleWidget.data,
    qt_meta_data_TitleWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TitleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TitleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TitleWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TitleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void TitleWidget::signalSkin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TitleWidget::signalMin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TitleWidget::signalClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TitleWidget::signalSearchContent(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TitleWidget::signalSearchClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
