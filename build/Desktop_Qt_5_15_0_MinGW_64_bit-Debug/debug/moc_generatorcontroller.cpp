/****************************************************************************
** Meta object code from reading C++ file 'generatorcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Controller/generatorcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generatorcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneratorController_t {
    QByteArrayData data[10];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneratorController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneratorController_t qt_meta_stringdata_GeneratorController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GeneratorController"
QT_MOC_LITERAL(1, 20, 11), // "qrCodeImage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "text"
QT_MOC_LITERAL(4, 38, 20), // "copyImageToClipboard"
QT_MOC_LITERAL(5, 59, 5), // "image"
QT_MOC_LITERAL(6, 65, 15), // "getTempFilePath"
QT_MOC_LITERAL(7, 81, 8), // "fileName"
QT_MOC_LITERAL(8, 90, 10), // "printImage"
QT_MOC_LITERAL(9, 101, 4) // "path"

    },
    "GeneratorController\0qrCodeImage\0\0text\0"
    "copyImageToClipboard\0image\0getTempFilePath\0"
    "fileName\0printImage\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneratorController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x02 /* Public */,
       4,    1,   37,    2, 0x02 /* Public */,
       6,    1,   40,    2, 0x02 /* Public */,
       8,    1,   43,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::QString, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString,    9,

       0        // eod
};

void GeneratorController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneratorController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->qrCodeImage((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->copyImageToClipboard((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: { QString _r = _t->getTempFilePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->printImage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GeneratorController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GeneratorController.data,
    qt_meta_data_GeneratorController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeneratorController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneratorController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GeneratorController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
