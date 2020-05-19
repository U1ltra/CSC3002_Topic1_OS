/****************************************************************************
** Meta object code from reading C++ file 'texteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI/texteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'texteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEditor_t {
    QByteArrayData data[13];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEditor_t qt_meta_stringdata_TextEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextEditor"
QT_MOC_LITERAL(1, 11, 27), // "on_action_NewFile_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 28), // "on_action_OpenFile_triggered"
QT_MOC_LITERAL(4, 69, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(5, 94, 26), // "on_action_SaveAs_triggered"
QT_MOC_LITERAL(6, 121, 24), // "on_action_Exit_triggered"
QT_MOC_LITERAL(7, 146, 24), // "on_action_Undo_triggered"
QT_MOC_LITERAL(8, 171, 23), // "on_action_Cut_triggered"
QT_MOC_LITERAL(9, 195, 24), // "on_action_Copy_triggered"
QT_MOC_LITERAL(10, 220, 25), // "on_action_Paste_triggered"
QT_MOC_LITERAL(11, 246, 24), // "on_action_Find_triggered"
QT_MOC_LITERAL(12, 271, 16) // "do_cursorChanged"

    },
    "TextEditor\0on_action_NewFile_triggered\0"
    "\0on_action_OpenFile_triggered\0"
    "on_action_Save_triggered\0"
    "on_action_SaveAs_triggered\0"
    "on_action_Exit_triggered\0"
    "on_action_Undo_triggered\0"
    "on_action_Cut_triggered\0"
    "on_action_Copy_triggered\0"
    "on_action_Paste_triggered\0"
    "on_action_Find_triggered\0do_cursorChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_NewFile_triggered(); break;
        case 1: _t->on_action_OpenFile_triggered(); break;
        case 2: _t->on_action_Save_triggered(); break;
        case 3: _t->on_action_SaveAs_triggered(); break;
        case 4: _t->on_action_Exit_triggered(); break;
        case 5: _t->on_action_Undo_triggered(); break;
        case 6: _t->on_action_Cut_triggered(); break;
        case 7: _t->on_action_Copy_triggered(); break;
        case 8: _t->on_action_Paste_triggered(); break;
        case 9: _t->on_action_Find_triggered(); break;
        case 10: _t->do_cursorChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TextEditor::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_TextEditor.data,
    qt_meta_data_TextEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
