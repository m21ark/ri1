/****************************************************************************
** Meta object code from reading C++ file 'pause_tool.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../flatland/flatland_rviz_plugins/include/flatland_rviz_plugins/pause_tool.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pause_tool.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_flatland_rviz_plugins__PauseTool_t {
    QByteArrayData data[1];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_flatland_rviz_plugins__PauseTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_flatland_rviz_plugins__PauseTool_t qt_meta_stringdata_flatland_rviz_plugins__PauseTool = {
    {
QT_MOC_LITERAL(0, 0, 32) // "flatland_rviz_plugins::PauseTool"

    },
    "flatland_rviz_plugins::PauseTool"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_flatland_rviz_plugins__PauseTool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void flatland_rviz_plugins::PauseTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject flatland_rviz_plugins::PauseTool::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::Tool::staticMetaObject>(),
    qt_meta_stringdata_flatland_rviz_plugins__PauseTool.data,
    qt_meta_data_flatland_rviz_plugins__PauseTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *flatland_rviz_plugins::PauseTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *flatland_rviz_plugins::PauseTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_flatland_rviz_plugins__PauseTool.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::Tool::qt_metacast(_clname);
}

int flatland_rviz_plugins::PauseTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::Tool::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
