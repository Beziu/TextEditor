/****************************************************************************
** Meta object code from reading C++ file 'SearchAndReplaceDial.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SearchAndReplaceDial.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchAndReplaceDial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchAndReplaceDial_t {
    const uint offsetsAndSize[30];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SearchAndReplaceDial_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SearchAndReplaceDial_t qt_meta_stringdata_SearchAndReplaceDial = {
    {
QT_MOC_LITERAL(0, 20), // "SearchAndReplaceDial"
QT_MOC_LITERAL(21, 12), // "windowClosed"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 14), // "const QWidget*"
QT_MOC_LITERAL(50, 25), // "on_btnSzukajDalej_clicked"
QT_MOC_LITERAL(76, 25), // "on_textSzukaj_textChanged"
QT_MOC_LITERAL(102, 4), // "arg1"
QT_MOC_LITERAL(107, 27), // "on_textSzukaj_returnPressed"
QT_MOC_LITERAL(135, 27), // "on_textZastap_returnPressed"
QT_MOC_LITERAL(163, 20), // "on_btnZastap_clicked"
QT_MOC_LITERAL(184, 28), // "on_btnZastapWszystko_clicked"
QT_MOC_LITERAL(213, 20), // "on_btnAnuluj_clicked"
QT_MOC_LITERAL(234, 10), // "closeEvent"
QT_MOC_LITERAL(245, 12), // "QCloseEvent*"
QT_MOC_LITERAL(258, 5) // "event"

    },
    "SearchAndReplaceDial\0windowClosed\0\0"
    "const QWidget*\0on_btnSzukajDalej_clicked\0"
    "on_textSzukaj_textChanged\0arg1\0"
    "on_textSzukaj_returnPressed\0"
    "on_textZastap_returnPressed\0"
    "on_btnZastap_clicked\0on_btnZastapWszystko_clicked\0"
    "on_btnAnuluj_clicked\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchAndReplaceDial[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   71,    2, 0x08,    2 /* Private */,
       5,    1,   72,    2, 0x08,    3 /* Private */,
       7,    0,   75,    2, 0x08,    5 /* Private */,
       8,    0,   76,    2, 0x08,    6 /* Private */,
       9,    0,   77,    2, 0x08,    7 /* Private */,
      10,    0,   78,    2, 0x08,    8 /* Private */,
      11,    0,   79,    2, 0x08,    9 /* Private */,
      12,    1,   80,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void SearchAndReplaceDial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchAndReplaceDial *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->windowClosed((*reinterpret_cast< const QWidget*(*)>(_a[1]))); break;
        case 1: _t->on_btnSzukajDalej_clicked(); break;
        case 2: _t->on_textSzukaj_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_textSzukaj_returnPressed(); break;
        case 4: _t->on_textZastap_returnPressed(); break;
        case 5: _t->on_btnZastap_clicked(); break;
        case 6: _t->on_btnZastapWszystko_clicked(); break;
        case 7: _t->on_btnAnuluj_clicked(); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchAndReplaceDial::*)(const QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchAndReplaceDial::windowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SearchAndReplaceDial::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SearchAndReplaceDial.offsetsAndSize,
    qt_meta_data_SearchAndReplaceDial,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SearchAndReplaceDial_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QWidget *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *SearchAndReplaceDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchAndReplaceDial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchAndReplaceDial.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SearchAndReplaceDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SearchAndReplaceDial::windowClosed(const QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
