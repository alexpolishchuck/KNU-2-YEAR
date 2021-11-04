/****************************************************************************
** Meta object code from reading C++ file 'secondwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyLab/secondwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secondwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_secondwindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_secondwindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_secondwindow_t qt_meta_stringdata_secondwindow = {
    {
QT_MOC_LITERAL(0, 12), // "secondwindow"
QT_MOC_LITERAL(13, 21), // "on_pushButton_pressed"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 23), // "on_pushButton_2_pressed"
QT_MOC_LITERAL(60, 23), // "on_pushButton_3_pressed"
QT_MOC_LITERAL(84, 23), // "on_pushButton_4_pressed"
QT_MOC_LITERAL(108, 24), // "on_pushButton_2_released"
QT_MOC_LITERAL(133, 24), // "on_pushButton_3_released"
QT_MOC_LITERAL(158, 24), // "on_pushButton_4_released"
QT_MOC_LITERAL(183, 22), // "on_pushButton_released"
QT_MOC_LITERAL(206, 12), // "readFromFile"
QT_MOC_LITERAL(219, 12), // "QListWidget*"
QT_MOC_LITERAL(232, 13), // "removeChecked"
QT_MOC_LITERAL(246, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(263, 4), // "item"
QT_MOC_LITERAL(268, 18), // "removeSelectedItem"
QT_MOC_LITERAL(287, 10), // "moveToFile"
QT_MOC_LITERAL(298, 11) // "saveArchive"

    },
    "secondwindow\0on_pushButton_pressed\0\0"
    "on_pushButton_2_pressed\0on_pushButton_3_pressed\0"
    "on_pushButton_4_pressed\0"
    "on_pushButton_2_released\0"
    "on_pushButton_3_released\0"
    "on_pushButton_4_released\0"
    "on_pushButton_released\0readFromFile\0"
    "QListWidget*\0removeChecked\0QListWidgetItem*\0"
    "item\0removeSelectedItem\0moveToFile\0"
    "saveArchive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_secondwindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    2,  100,    2, 0x08,    9 /* Private */,
      12,    1,  105,    2, 0x08,   12 /* Private */,
      15,    0,  108,    2, 0x08,   14 /* Private */,
      16,    1,  109,    2, 0x08,   15 /* Private */,
      17,    0,  112,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,

       0        // eod
};

void secondwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<secondwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_pressed(); break;
        case 1: _t->on_pushButton_2_pressed(); break;
        case 2: _t->on_pushButton_3_pressed(); break;
        case 3: _t->on_pushButton_4_pressed(); break;
        case 4: _t->on_pushButton_2_released(); break;
        case 5: _t->on_pushButton_3_released(); break;
        case 6: _t->on_pushButton_4_released(); break;
        case 7: _t->on_pushButton_released(); break;
        case 8: _t->readFromFile((*reinterpret_cast< QListWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->removeChecked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->removeSelectedItem(); break;
        case 11: _t->moveToFile((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->saveArchive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QListWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject secondwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_secondwindow.offsetsAndSize,
    qt_meta_data_secondwindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_secondwindow_t
, QtPrivate::TypeAndForceComplete<secondwindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *secondwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *secondwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_secondwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int secondwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
