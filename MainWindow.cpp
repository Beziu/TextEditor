#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Systemowa klasa wyskakujacych okienek w dowolnym jezyku.
    //    sysTranslator = new QTranslator();
    //    bSysTranslatorLoaded = sysTranslator->load("qt_pl",
    //                                               QLibraryInfo::path(QLibraryInfo::TranslationsPath));

    //    if (bSysTranslatorLoaded)
    //        qApp->installTranslator(sysTranslator);


    ui->setupUi(this);

    init();

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::init()
{
    dlgSearchAndReplace = nullptr;

    // Pozycje menu dla języka można sprawdzić.
    // Aby można było wybrać tylko jeden wpis naraz,
    // należy je połączyć w ActionGroup.
    QActionGroup* actionGroupLanguage = new QActionGroup(this);
    actionGroupLanguage->addAction(ui->actionPolski);
    actionGroupLanguage->addAction(ui->actionAngielski);
    actionGroupLanguage->addAction(ui->actionNiemiecki);

    // Tlumaczenie dla jezyka systemowego
    sysTranslator = new QTranslator();
    bSysTranslatorLoaded = false;

    // Tlumaczenie dla Angielskiego
    enTranslator = new QTranslator();
    bEnTranslatorLoaded = enTranslator->load(QLocale::English,
                                             QDir::currentPath() + QDir::separator() + "WindowDialoge", "_");
    bEnTranslatorLoaded = false;

    // Tlumaczenie dla Niemieckiego
    deTranslator = new QTranslator();
    bDeTranslatorLoaded = deTranslator->load(QLocale::German,
                                             QDir::currentPath() + QDir::separator() + "WindowDialoge", "_");
    bDeTranslatorLoaded = false;


    // Dla stałych wiadomości w StatusBar: Utwórz nową etykietę,
    // która będzie używana w StatusBar dla wiadomości tekstowych.
    statusLabel = new QLabel(this);

    // Wcięcie tekstu wewnątrz etykiety
    statusLabel->setIndent(9);

    // Pozycja na lewo '1' na pasku statusu
    this->statusBar()->addWidget(statusLabel, 1);

    // Kolor zaznaczonego tekstu w tle nieaktywnego okna
    // zawsze zostaje niebieski pomimo nieaktywnego okna
    QPalette pal = ui->textEdit->palette();
    pal.setColor(QPalette::HighlightedText, Qt::white);
    pal.setColor(QPalette::Highlight, QColor(0, 112, 255));
    ui->textEdit->setPalette(pal);

    hashCode = qHash(ui->textEdit->toPlainText());

    QString xmlConfigPath = QDir::homePath() + "/AppData/Local/" + QCoreApplication::applicationName();
    xmlConfigFile = xmlConfigPath + "/" + QCoreApplication::applicationName() + ".xml";

    readXMLSettings(xmlConfigFile);

}

void MainWindow::on_actionPlik_triggered()
{
    close();

}

void MainWindow::on_actionOtworz_triggered()
{
    openFile();

}

void MainWindow::openFile()
{
    if (!querySave())
        return;

    QString actDir;
    QString defaultFilter = tr("Dokumenty tekstowe (*.txt)");

    // Zwraca katalog domowy użytkownika.
    actDir = QDir::homePath();

    QString filename = QFileDialog::getOpenFileName(this, tr("Dokument tekstowy"), actDir,
                                                    tr("Wszytkie pliki (*.*);;") + defaultFilter, &defaultFilter);

    //qDebug() << filename;

    if (!filename.isEmpty())
        readFile(filename);

}

void MainWindow::readFile(const QString &filename)
{
    // Otwiera plik do odczytu
    QFile file(filename);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, tr("Plik otwarty"),
                              QString(tr("Plik nie moze byc otwarty %1:\n%2"))
                              .arg(filename.arg(file.errorString())));
        return;
    }

    // Przekazywanie nazwy pliku do TextStream
    QTextStream inStream(&file);
    ui->textEdit->setText(inStream.readAll());

    file.close();

    // Aby wyświetlić pełną nazwę pliku na pasku stanu
    //this->statusBar()->showMessage(QDir::toNativeSeparators(filename));

    // Jeśli ma być wyświetlana tylko nazwa pliku
    //this->statusBar()->showMessage(QFileInfo(filename).fileName());

    // Wyświetlanie nazwy pliku w etykiecie dodanej do StatusBar
    statusLabel->setText(QFileInfo(filename).fileName());

    // Zapisz nazwę bieżącego pliku
    actFile = filename;

    hashCode = qHash(ui->textEdit->toPlainText());

}

bool MainWindow::saveFile(const QString &filename)
{
    QString errorMessage;

    if (filename.isEmpty())
        return saveFileAs();

    // Zapisz plik
    QSaveFile file(filename);

    if (file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream outStream(&file);

        outStream << ui->textEdit->toPlainText();

        if (!file.commit())
        {
            errorMessage = QString(tr("Blad przy zapisie pliku %1:\n%2"))
                    .arg(QDir::toNativeSeparators(filename)
                         .arg(file.errorString()));
        }
    }
    else
    {
        errorMessage = QString(tr("Blad zapisu pliku %1:\n%2"))
                .arg(QDir::toNativeSeparators(filename)
                     .arg(file.errorString()));
    }

    if (!errorMessage.isEmpty())
    {
        QMessageBox::critical(this, this->windowTitle(), errorMessage);
        return false;
    }

    ui->textEdit->document()->setModified(false);

    return true;

}

bool MainWindow::saveFileAs()
{
    QString filter = tr("Dokument tekstowy (*.txt);;Wszystkie typy (*.*)");
    QString defaultFilter = tr("Dokument tekstowy (*.txt)");

    QString  filename = QFileDialog::getSaveFileName(this, tr("Zapisz w..."),
                                                     QDir::currentPath(), filter, &defaultFilter);

    if (filename.isEmpty())
        return false;

    return saveFile(filename);

}

// Zwraca 'true' jeśli program ma zostać zakończony
bool MainWindow::queryExit()
{
    bool retValue = true;

    int msgValue = QMessageBox::question(this, tr("Koniec"), tr("Na pewno zamknac?"),
                                         QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (msgValue == QMessageBox::No)
        retValue = false;

    return retValue;

}

// Zwraca 'true' jeśli program ma zostać zakończony
bool MainWindow::querySave()
{
    bool retValue;

    // Jeśli dokument został zmodyfikowany
    //if (!ui->textEdit->document()->isModified())
    //    return true;

    // Sprawdzanie zmian za pomocą HashCode.
    uint actHashCode = qHash(ui->textEdit->toPlainText());

    if (actHashCode == hashCode)
        return true;

    int msgValue = QMessageBox::question(this, this->windowTitle(), tr("Dane zmienione.\n" "Co dalej ???"),
                                         QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
                                         QMessageBox::Cancel);

    switch(msgValue)
    {
    case QMessageBox::Save:
        //qDebug() << "Zapisz i wyjdź z programu";
        retValue = saveFile(actFile);
        break;

    case QMessageBox::Cancel:
        //qDebug() << "Anuluj i wróć do programu";
        retValue = false;
        break;

    default:
        //qDebug() << "Nie zapisuj i zakończ program";
        retValue = true;
    }

    return retValue;

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //    if (queryExit())
    //        event->accept();
    //    else
    //        event->ignore();

    if (querySave())
    {
        // Aktualny jezyk w pliku konfiguracji zapisujemy
        writeXMLSettings((xmlConfigFile));
        event->accept();
    }
    else
        event->ignore();

}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        ui->retranslateUi(this);

}

void MainWindow::loadLanguage(const QString &language)
{
    removeAllTranslators();

    if (language.toLower() == "en")
    {
        bSysTranslatorLoaded = sysTranslator->load("qt_" + language,
                                                   QLibraryInfo::path(QLibraryInfo::TranslationsPath));
        bEnTranslatorLoaded = qApp->installTranslator(enTranslator);

        currentLanguage = language;
        ui->actionAngielski->setChecked(true);

    }
    else if (language.toLower() == "de")
    {
        bSysTranslatorLoaded = sysTranslator->load("qt_" + language,
                                                   QLibraryInfo::path(QLibraryInfo::TranslationsPath));
        bDeTranslatorLoaded = qApp->installTranslator(deTranslator);

        currentLanguage = language;
        ui->actionNiemiecki->setChecked(true);

    }
    // Standardowy jezyk systemu.
    else
    {
        bSysTranslatorLoaded = sysTranslator->load("qt_pl",
                                                   QLibraryInfo::path(QLibraryInfo::TranslationsPath));
        ui->actionPolski->setChecked(true);
    }

    if (bSysTranslatorLoaded)
    {
        bSysTranslatorLoaded = qApp->installTranslator(sysTranslator);
    }

}

void MainWindow::removeAllTranslators()
{
    if (bEnTranslatorLoaded)
    {
        qApp->removeTranslator(enTranslator);
        bEnTranslatorLoaded = false;
    }
    else if (bDeTranslatorLoaded)
    {
        qApp->removeTranslator(deTranslator);
        bDeTranslatorLoaded = false;
    }

    qApp->removeTranslator(sysTranslator);
    bSysTranslatorLoaded = false;

    currentLanguage.clear();

}

void MainWindow::writeXMLSettings(const QString &filename)
{
    // Sprawdź, czy katalog istnieje, jeśli nie, utwórz go
    QFileInfo fi(filename);

    // Wyodrębnij tylko nazwę katalogu z pełnej nazwy pliku
    QString xmlConfigPath = fi.absolutePath();

    QDir dir(xmlConfigPath);
    if(!dir.exists())
        dir.mkpath(xmlConfigPath);

    QFile file(filename);

    if (!file.open(QFile::WriteOnly))
    {
        QMessageBox::critical(this, this->windowTitle(), file.errorString());
        return;
    }

    QXmlStreamWriter xmlWriter(&file);

    // Automatyczne formatowanie pliku XML
    xmlWriter.setAutoFormatting(true);

    // Naglowek pliku XML zawierajacy informacje o wersji 1.0 oraz kodowanie
    xmlWriter.writeStartDocument();

    // Zapisuje element poczatkowy (wezel) pliku XML: <Settings>
    xmlWriter.writeStartElement("Settings");

    // zapisuje atrybut w wezle jako: <Language>en</Language>
    xmlWriter.writeTextElement("Language", currentLanguage);

    // Konczenie Kontu Settings w stylu: </Settings>
    xmlWriter.writeEndElement();

    file.close();

}

void MainWindow::readXMLSettings(const QString &filename)
{
    QString language;
    QFile file(filename);

    if (!file.open(QFile::ReadOnly | QFile:: Text))
        return;

    QXmlStreamReader xmlReader(&file);

    do
    {
        if (xmlReader.readNextStartElement())
        {
            if (xmlReader.name() == QString("Settings"))
            {
                do
                {
                    xmlReader.readNext();

                    // Koniec aktualnego wezla?
                    if (xmlReader.isEndElement())
                        break;

                    if (xmlReader.name() == QString("Language"))
                        language = xmlReader.readElementText();

                } while (!xmlReader.atEnd());
            }
        }
    } while(!xmlReader.atEnd());

    file.close();

    loadLanguage(language);

}

void MainWindow::on_actionZapisz_triggered()
{
    saveFile(actFile);
}

void MainWindow::on_actionZapiszJako_triggered()
{
    saveFileAs();

}

void MainWindow::on_actionNowy_triggered()
{
    setNewDocument();

}

void MainWindow::setNewDocument()
{
    // Zapytuje czy dokument zmieniono i zapisano.
    // konczy funkcje jesli wcisnieto 'Cancel'
    // jesli 'Save'  to zapisuje i tworzy nowy
    // lub 'Discard' tylko tworzy nowy

    if (!querySave())
        return;

    // czysci tekst w polu textEdit
    ui->textEdit->clear();
    // zapamietuje nowa wartosc hash
    hashCode = qHash(ui->textEdit->toPlainText());
    // usuwa aktywny plik z bufora
    actFile.clear();
    // usuwa status z paska dolnego
    statusLabel->clear();

}

void MainWindow::setTextWrap()
{
    // Gdy z Menu Format wybierzesz 'Text Wrap' zawijanie tekstu
    // DEFAULT ON
    if (ui->actionTextWrap->isChecked())
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    else
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);

}

void MainWindow::on_actionTextWrap_triggered()
{
    setTextWrap();

}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_actionPolski_triggered()
{
    loadLanguage("");

}

void MainWindow::on_actionAngielski_triggered()
{
    loadLanguage("en");

}

void MainWindow::on_actionNiemiecki_triggered()
{
    loadLanguage("de");

}

void MainWindow::on_actionSzukajIZastap_triggered()
{
//    dlgSearchAndReplace dlg(ui->textEdit, this);
//    dlg.exec();

//    delete dlgSearchAndReplace;

//    dlgSearchAndReplace = new SearchAndReplaceDial(ui->textEdit, this);
//    dlgSearchAndReplace->show();

    // lub

    if (dlgSearchAndReplace == nullptr)
    {
        // Dialog wywolany jako new i pokazany
        dlgSearchAndReplace = new SearchAndReplaceDial(ui->textEdit, this);

        connect(dlgSearchAndReplace, SIGNAL(windowClosed(const QWidget*)), this,
                SLOT(onWindowClosed(const QWidget*)));

        dlgSearchAndReplace->show();

        ui->actionSzukajIZastap->setEnabled(false);

    }
    else
    {
        // Dialog pokazany i jako aktywne okno ustawiony
        dlgSearchAndReplace->show();
        dlgSearchAndReplace->activateWindow();
    }

}

void MainWindow::onWindowClosed(const QWidget * widget)
{
    if (widget == dlgSearchAndReplace)
    {
        ui->actionSzukajIZastap->setEnabled(true);

        delete dlgSearchAndReplace;

        dlgSearchAndReplace = nullptr;
    }

}


