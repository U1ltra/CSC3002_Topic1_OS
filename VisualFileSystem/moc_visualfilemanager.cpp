/****************************************************************************
** Meta object code from reading C++ file 'visualfilemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "visualfilemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualfilemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VisualFileManager_t {
    QByteArrayData data[15];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VisualFileManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VisualFileManager_t qt_meta_stringdata_VisualFileManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "VisualFileManager"
QT_MOC_LITERAL(1, 18, 10), // "initialize"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "fileNotExist"
QT_MOC_LITERAL(4, 43, 4), // "Root"
QT_MOC_LITERAL(5, 48, 4), // "Copy"
QT_MOC_LITERAL(6, 53, 5), // "Paste"
QT_MOC_LITERAL(7, 59, 6), // "Create"
QT_MOC_LITERAL(8, 66, 6), // "Delete"
QT_MOC_LITERAL(9, 73, 2), // "Up"
QT_MOC_LITERAL(10, 76, 2), // "Cd"
QT_MOC_LITERAL(11, 79, 4), // "Exit"
QT_MOC_LITERAL(12, 84, 13), // "doubleClicked"
QT_MOC_LITERAL(13, 98, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 115, 9) // "showError"

    },
    "VisualFileManager\0initialize\0\0"
    "fileNotExist\0Root\0Copy\0Paste\0Create\0"
    "Delete\0Up\0Cd\0Exit\0doubleClicked\0"
    "QListWidgetItem*\0showError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VisualFileManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   76,    2, 0x09 /* Protected */,
       5,    0,   77,    2, 0x09 /* Protected */,
       6,    0,   78,    2, 0x09 /* Protected */,
       7,    0,   79,    2, 0x09 /* Protected */,
       8,    0,   80,    2, 0x09 /* Protected */,
       9,    0,   81,    2, 0x09 /* Protected */,
      10,    0,   82,    2, 0x09 /* Protected */,
      11,    0,   83,    2, 0x09 /* Protected */,
      12,    1,   84,    2, 0x09 /* Protected */,
      14,    0,   87,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,

       0        // eod
};

void VisualFileManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VisualFileManager *_t = static_cast<VisualFileManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initialize(); break;
        case 1: _t->fileNotExist(); break;
        case 2: _t->Root(); break;
        case 3: _t->Copy(); break;
        case 4: _t->Paste(); break;
        case 5: _t->Create(); break;
        case 6: _t->Delete(); break;
        case 7: _t->Up(); break;
        case 8: _t->Cd(); break;
        case 9: _t->Exit(); break;
        case 10: _t->doubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->showError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VisualFileManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualFileManager::initialize)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VisualFileManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualFileManager::fileNotExist)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject VisualFileManager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VisualFileManager.data,
      qt_meta_data_VisualFileManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VisualFileManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisualFileManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VisualFileManager.stringdata0))
        return static_cast<void*>(const_cast< VisualFileManager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VisualFileManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void VisualFileManager::initialize()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void VisualFileManager::fileNotExist()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
