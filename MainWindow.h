#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTextStream>
#include <QLabel>
#include <QCloseEvent>
#include <QTranslator>
#include <QLibraryInfo>
#include <QSaveFile>
#include <QTextEdit>
#include <QActionGroup>
#include <QXmlStreamReader>

#include "SearchAndReplaceDial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPlik_triggered();
    void on_actionOtworz_triggered();
    void on_actionZapisz_triggered();
    void on_actionZapiszJako_triggered();
    void on_actionNowy_triggered();
    void on_textEdit_textChanged();
    void on_actionTextWrap_triggered();
    void on_actionPolski_triggered();
    void on_actionAngielski_triggered();
    void on_actionNiemiecki_triggered();
    void on_actionSzukajIZastap_triggered();

    void onWindowClosed(const QWidget* widget);

private:
    Ui::MainWindow *ui;

    SearchAndReplaceDial* dlgSearchAndReplace;

    QLabel* statusLabel;

    QTranslator* sysTranslator;
    bool bSysTranslatorLoaded;
    QTranslator* enTranslator;
    bool bEnTranslatorLoaded;
    QTranslator* deTranslator;
    bool bDeTranslatorLoaded;

    QString currentLanguage;

    QString actFile;
    QString xmlConfigFile;

    void init();
    uint hashCode;

    void openFile();
    void readFile(const QString& filename);
    bool saveFile(const QString& filename);
    bool saveFileAs();

    bool queryExit();
    bool querySave();
    // Przy zamykaniu zwraca
    void closeEvent(QCloseEvent* event) override;

    // Nadpisanie changeEvent dla tlumaczenia
    void changeEvent(QEvent* event) override;

    void loadLanguage(const QString&);
    void removeAllTranslators();

    void writeXMLSettings(const QString&);
    void readXMLSettings(const QString&);

    void setTextWrap();
    void setNewDocument();

    bool x;

};
#endif // MAINWINDOW_H
