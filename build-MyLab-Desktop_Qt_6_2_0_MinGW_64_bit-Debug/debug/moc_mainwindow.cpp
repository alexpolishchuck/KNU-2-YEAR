/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyLab/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 21), // "on_pushButton_pressed"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 23), // "on_pushButton_2_pressed"
QT_MOC_LITERAL(58, 23), // "on_pushButton_3_pressed"
QT_MOC_LITERAL(82, 23), // "on_pushButton_4_pressed"
QT_MOC_LITERAL(106, 24), // "on_pushButton_2_released"
QT_MOC_LITERAL(131, 24), // "on_pushButton_3_released"
QT_MOC_LITERAL(156, 24), // "on_pushButton_4_released"
QT_MOC_LITERAL(181, 22), // "on_pushButton_released"
QT_MOC_LITERAL(204, 27), // "on_lineEdit_editingFinished"
QT_MOC_LITERAL(232, 13), // "removeChecked"
QT_MOC_LITERAL(246, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(263, 4), // "item"
QT_MOC_LITERAL(268, 10), // "saveToFile"
QT_MOC_LITERAL(279, 12), // "readFromFile"
QT_MOC_LITERAL(292, 12), // "QListWidget*"
QT_MOC_LITERAL(305, 13), // "saveToArchive"
QT_MOC_LITERAL(319, 18) // "removeSelectedItem"

    },
    "MainWindow\0on_pushButton_pressed\0\0"
    "on_pushButton_2_pressed\0on_pushButton_3_pressed\0"
    "on_pushButton_4_pressed\0"
    "on_pushButton_2_released\0"
    "on_pushButton_3_released\0"
    "on_pushButton_4_released\0"
    "on_pushButton_released\0"
    "on_lineEdit_editingFinished\0removeChecked\0"
    "QListWidgetItem*\0item\0saveToFile\0"
    "readFromFile\0QListWidget*\0saveToArchive\0"
    "removeSelectedItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    1,  107,    2, 0x08,   10 /* Private */,
      14,    0,  110,    2, 0x08,   12 /* Private */,
      15,    2,  111,    2, 0x08,   13 /* Private */,
      17,    1,  116,    2, 0x08,   16 /* Private */,
      18,    0,  119,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
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
        case 8: _t->on_lineEdit_editingFinished(); break;
        case 9: _t->removeChecked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->saveToFile(); break;
        case 11: _t->readFromFile((*reinterpret_cast< QListWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->saveToArchive((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: _t->removeSelectedItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QListWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE