/****************************************************************************
** Meta object code from reading C++ file 'musicsongsmedia.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/ContentWidget/MusiSongList/musicsongsmedia.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicsongsmedia.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicSongsMedia_t {
    QByteArrayData data[16];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicSongsMedia_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicSongsMedia_t qt_meta_stringdata_MusicSongsMedia = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MusicSongsMedia"
QT_MOC_LITERAL(1, 16, 20), // "signalPlayMediaMusic"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "path"
QT_MOC_LITERAL(4, 43, 18), // "signalShowMediaLrc"
QT_MOC_LITERAL(5, 62, 10), // "songPinYin"
QT_MOC_LITERAL(6, 73, 11), // "slotAddItem"
QT_MOC_LITERAL(7, 85, 5), // "title"
QT_MOC_LITERAL(8, 91, 6), // "singer"
QT_MOC_LITERAL(9, 98, 5), // "album"
QT_MOC_LITERAL(10, 104, 17), // "slotSaveMusicInfo"
QT_MOC_LITERAL(11, 122, 4), // "name"
QT_MOC_LITERAL(12, 127, 6), // "pinyin"
QT_MOC_LITERAL(13, 134, 21), // "slotCellDoubleClicked"
QT_MOC_LITERAL(14, 156, 3), // "row"
QT_MOC_LITERAL(15, 160, 6) // "cloumn"

    },
    "MusicSongsMedia\0signalPlayMediaMusic\0"
    "\0path\0signalShowMediaLrc\0songPinYin\0"
    "slotAddItem\0title\0singer\0album\0"
    "slotSaveMusicInfo\0name\0pinyin\0"
    "slotCellDoubleClicked\0row\0cloumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicSongsMedia[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   45,    2, 0x0a /* Public */,
      10,    2,   52,    2, 0x0a /* Public */,
      13,    2,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,

       0        // eod
};

void MusicSongsMedia::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicSongsMedia *_t = static_cast<MusicSongsMedia *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPlayMediaMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalShowMediaLrc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotAddItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->slotSaveMusicInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->slotCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicSongsMedia::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicSongsMedia::signalPlayMediaMusic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicSongsMedia::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicSongsMedia::signalShowMediaLrc)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MusicSongsMedia::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_MusicSongsMedia.data,
    qt_meta_data_MusicSongsMedia,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicSongsMedia::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicSongsMedia::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicSongsMedia.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int MusicSongsMedia::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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
void MusicSongsMedia::signalPlayMediaMusic(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicSongsMedia::signalShowMediaLrc(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
