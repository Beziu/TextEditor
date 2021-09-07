/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionKoniec;
    QAction *actionNowy;
    QAction *actionOtworz;
    QAction *actionZapisz;
    QAction *actionZapiszJako;
    QAction *actionTextWrap;
    QAction *actionKopiuj;
    QAction *actionWklej;
    QAction *actionWytnij;
    QAction *actionPonow;
    QAction *actionCofnij;
    QAction *actionTextKursiwe;
    QAction *actionDrukuj;
    QAction *actionPodgladWydruku;
    QAction *actionUstawieniaWydruku;
    QAction *actionPolski;
    QAction *actionAngielski;
    QAction *actionNiemiecki;
    QAction *actionSzukajIZastap;
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuFormat;
    QMenu *menuEdycja;
    QMenu *menuEXtras;
    QMenu *menuJezyk;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("App.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionKoniec = new QAction(MainWindow);
        actionKoniec->setObjectName(QString::fromUtf8("actionKoniec"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKoniec->setIcon(icon1);
        actionNowy = new QAction(MainWindow);
        actionNowy->setObjectName(QString::fromUtf8("actionNowy"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNowy->setIcon(icon2);
        actionOtworz = new QAction(MainWindow);
        actionOtworz->setObjectName(QString::fromUtf8("actionOtworz"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOtworz->setIcon(icon3);
        actionZapisz = new QAction(MainWindow);
        actionZapisz->setObjectName(QString::fromUtf8("actionZapisz"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZapisz->setIcon(icon4);
        actionZapiszJako = new QAction(MainWindow);
        actionZapiszJako->setObjectName(QString::fromUtf8("actionZapiszJako"));
        actionTextWrap = new QAction(MainWindow);
        actionTextWrap->setObjectName(QString::fromUtf8("actionTextWrap"));
        actionTextWrap->setCheckable(true);
        actionTextWrap->setChecked(true);
        actionKopiuj = new QAction(MainWindow);
        actionKopiuj->setObjectName(QString::fromUtf8("actionKopiuj"));
        actionWklej = new QAction(MainWindow);
        actionWklej->setObjectName(QString::fromUtf8("actionWklej"));
        actionWytnij = new QAction(MainWindow);
        actionWytnij->setObjectName(QString::fromUtf8("actionWytnij"));
        actionPonow = new QAction(MainWindow);
        actionPonow->setObjectName(QString::fromUtf8("actionPonow"));
        actionCofnij = new QAction(MainWindow);
        actionCofnij->setObjectName(QString::fromUtf8("actionCofnij"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("Search.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCofnij->setIcon(icon5);
        actionTextKursiwe = new QAction(MainWindow);
        actionTextKursiwe->setObjectName(QString::fromUtf8("actionTextKursiwe"));
        actionTextKursiwe->setCheckable(true);
        actionDrukuj = new QAction(MainWindow);
        actionDrukuj->setObjectName(QString::fromUtf8("actionDrukuj"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrukuj->setIcon(icon6);
        actionPodgladWydruku = new QAction(MainWindow);
        actionPodgladWydruku->setObjectName(QString::fromUtf8("actionPodgladWydruku"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("PagePreview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPodgladWydruku->setIcon(icon7);
        actionUstawieniaWydruku = new QAction(MainWindow);
        actionUstawieniaWydruku->setObjectName(QString::fromUtf8("actionUstawieniaWydruku"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("PageSetup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUstawieniaWydruku->setIcon(icon8);
        actionPolski = new QAction(MainWindow);
        actionPolski->setObjectName(QString::fromUtf8("actionPolski"));
        actionPolski->setCheckable(true);
        actionPolski->setChecked(true);
        actionAngielski = new QAction(MainWindow);
        actionAngielski->setObjectName(QString::fromUtf8("actionAngielski"));
        actionAngielski->setCheckable(true);
        actionNiemiecki = new QAction(MainWindow);
        actionNiemiecki->setObjectName(QString::fromUtf8("actionNiemiecki"));
        actionNiemiecki->setCheckable(true);
        actionSzukajIZastap = new QAction(MainWindow);
        actionSzukajIZastap->setObjectName(QString::fromUtf8("actionSzukajIZastap"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("SearchTransparent.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSzukajIZastap->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(6, 6, 6, 0);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        menuEdycja = new QMenu(menubar);
        menuEdycja->setObjectName(QString::fromUtf8("menuEdycja"));
        menuEXtras = new QMenu(menubar);
        menuEXtras->setObjectName(QString::fromUtf8("menuEXtras"));
        menuJezyk = new QMenu(menuEXtras);
        menuJezyk->setObjectName(QString::fromUtf8("menuJezyk"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuEdycja->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menubar->addAction(menuEXtras->menuAction());
        menuMenu->addAction(actionNowy);
        menuMenu->addAction(actionOtworz);
        menuMenu->addAction(actionZapisz);
        menuMenu->addAction(actionZapiszJako);
        menuMenu->addSeparator();
        menuMenu->addAction(actionPodgladWydruku);
        menuMenu->addAction(actionDrukuj);
        menuMenu->addAction(actionUstawieniaWydruku);
        menuMenu->addSeparator();
        menuMenu->addAction(actionKoniec);
        menuFormat->addAction(actionTextWrap);
        menuFormat->addAction(actionTextKursiwe);
        menuEdycja->addAction(actionCofnij);
        menuEdycja->addAction(actionPonow);
        menuEdycja->addSeparator();
        menuEdycja->addAction(actionWytnij);
        menuEdycja->addAction(actionKopiuj);
        menuEdycja->addAction(actionWklej);
        menuEdycja->addSeparator();
        menuEdycja->addAction(actionSzukajIZastap);
        menuEXtras->addAction(menuJezyk->menuAction());
        menuJezyk->addAction(actionPolski);
        menuJezyk->addAction(actionAngielski);
        menuJezyk->addAction(actionNiemiecki);
        toolBar->addAction(actionNowy);
        toolBar->addAction(actionOtworz);
        toolBar->addAction(actionZapisz);
        toolBar->addAction(actionDrukuj);
        toolBar->addSeparator();
        toolBar->addAction(actionSzukajIZastap);

        retranslateUi(MainWindow);
        QObject::connect(actionCofnij, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::undo));
        QObject::connect(actionKopiuj, &QAction::changed, textEdit, qOverload<>(&QTextEdit::copy));
        QObject::connect(actionWytnij, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::cut));
        QObject::connect(actionWklej, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::paste));
        QObject::connect(actionPonow, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::redo));
        QObject::connect(actionTextKursiwe, &QAction::toggled, textEdit, &QTextEdit::setFontItalic);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Edytor", nullptr));
        actionKoniec->setText(QCoreApplication::translate("MainWindow", "Koni&ec", nullptr));
        actionNowy->setText(QCoreApplication::translate("MainWindow", "&Nowy", nullptr));
#if QT_CONFIG(shortcut)
        actionNowy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOtworz->setText(QCoreApplication::translate("MainWindow", "&Otworz", nullptr));
#if QT_CONFIG(shortcut)
        actionOtworz->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZapisz->setText(QCoreApplication::translate("MainWindow", "Zapi&sz", nullptr));
#if QT_CONFIG(shortcut)
        actionZapisz->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZapiszJako->setText(QCoreApplication::translate("MainWindow", "Z&apisz jako...", nullptr));
        actionTextWrap->setText(QCoreApplication::translate("MainWindow", "Zawijanie wierszy", nullptr));
#if QT_CONFIG(shortcut)
        actionTextWrap->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKopiuj->setText(QCoreApplication::translate("MainWindow", "Kopiuj", nullptr));
#if QT_CONFIG(shortcut)
        actionKopiuj->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWklej->setText(QCoreApplication::translate("MainWindow", "Wklej", nullptr));
#if QT_CONFIG(shortcut)
        actionWklej->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWytnij->setText(QCoreApplication::translate("MainWindow", "Wytnij", nullptr));
#if QT_CONFIG(shortcut)
        actionWytnij->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPonow->setText(QCoreApplication::translate("MainWindow", "Ponow", nullptr));
        actionCofnij->setText(QCoreApplication::translate("MainWindow", "Cofnij", nullptr));
#if QT_CONFIG(shortcut)
        actionCofnij->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTextKursiwe->setText(QCoreApplication::translate("MainWindow", "Text Kursiwe", nullptr));
#if QT_CONFIG(shortcut)
        actionTextKursiwe->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDrukuj->setText(QCoreApplication::translate("MainWindow", "&Drukuj", nullptr));
#if QT_CONFIG(shortcut)
        actionDrukuj->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPodgladWydruku->setText(QCoreApplication::translate("MainWindow", "Podglad &wydruku", nullptr));
        actionUstawieniaWydruku->setText(QCoreApplication::translate("MainWindow", "Ustawienia wydruku", nullptr));
#if QT_CONFIG(tooltip)
        actionUstawieniaWydruku->setToolTip(QCoreApplication::translate("MainWindow", "Ustawienia wydruku", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPolski->setText(QCoreApplication::translate("MainWindow", "&Polski", nullptr));
        actionAngielski->setText(QCoreApplication::translate("MainWindow", "&Angielski", nullptr));
        actionNiemiecki->setText(QCoreApplication::translate("MainWindow", "&Niemiecki", nullptr));
        actionSzukajIZastap->setText(QCoreApplication::translate("MainWindow", "&Szukaj i zastap", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "&Plik", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("MainWindow", "&Format", nullptr));
        menuEdycja->setTitle(QCoreApplication::translate("MainWindow", "&Edycja", nullptr));
        menuEXtras->setTitle(QCoreApplication::translate("MainWindow", "E&xtras", nullptr));
        menuJezyk->setTitle(QCoreApplication::translate("MainWindow", "Jezyk", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
