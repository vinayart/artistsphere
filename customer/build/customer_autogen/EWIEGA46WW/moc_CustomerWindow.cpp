/****************************************************************************
** Meta object code from reading C++ file 'CustomerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CustomerWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomerWindow_t {
    QByteArrayData data[12];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomerWindow_t qt_meta_stringdata_CustomerWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomerWindow"
QT_MOC_LITERAL(1, 15, 13), // "performSearch"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "addToFavorites"
QT_MOC_LITERAL(4, 45, 11), // "viewArtwork"
QT_MOC_LITERAL(5, 57, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 74, 4), // "item"
QT_MOC_LITERAL(7, 79, 17), // "updateSuggestions"
QT_MOC_LITERAL(8, 97, 4), // "text"
QT_MOC_LITERAL(9, 102, 23), // "handleSuggestionClicked"
QT_MOC_LITERAL(10, 126, 10), // "artistName"
QT_MOC_LITERAL(11, 137, 16) // "openArtistViewer"

    },
    "CustomerWindow\0performSearch\0\0"
    "addToFavorites\0viewArtwork\0QListWidgetItem*\0"
    "item\0updateSuggestions\0text\0"
    "handleSuggestionClicked\0artistName\0"
    "openArtistViewer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomerWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,
       9,    1,   52,    2, 0x08 /* Private */,
      11,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void CustomerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->performSearch(); break;
        case 1: _t->addToFavorites(); break;
        case 2: _t->viewArtwork((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->updateSuggestions((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->handleSuggestionClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->openArtistViewer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CustomerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CustomerWindow.data,
    qt_meta_data_CustomerWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomerWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CustomerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
