#include "SearchAndReplaceDial.h"
#include "ui_SearchAndReplaceDial.h"

SearchAndReplaceDial::SearchAndReplaceDial(QTextEdit* textEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchAndReplaceDial)
{
    ui->setupUi(this);

    this->textEdit = textEdit;

    init();

}

SearchAndReplaceDial::~SearchAndReplaceDial()
{
    delete ui;
}

void SearchAndReplaceDial::init()
{
    findCounter = 0;
    replaceCounter = 0;
    replaceAllFlag = false;

    if (textEdit->textCursor().hasSelection())
    {
        ui->textSzukaj->setText(textEdit->textCursor().selectedText());
        ui->textSzukaj->selectAll();
        findCounter = 1;
    }

    enableButtons();

}

void SearchAndReplaceDial::enableButtons()
{
    // Aktywuj przycisk, aby kontynuować wyszukiwanie, jeśli
    // wyszukiwany termin został wprowadzony w tekście wyszukiwania.
    ui->btnSzukajDalej->setEnabled(ui->textSzukaj->text().length() > 0);
    // Dezaktywuj przycisk zastępowania, jeśli tekst wyszukiwania nie jest dostępny
    ui->btnZastap->setEnabled(ui->btnZastapWszystko->isEnabled());
    // Przycisk do zamiany wszystkich tekstów jest aktywny tylko wtedy,
    // gdy przycisk Zamień jest również aktywny.
    ui->btnZastapWszystko->setEnabled(ui->btnZastap->isEnabled());

}

bool SearchAndReplaceDial::findText()
{
    bool retValue = false;
    int msgValue;

    if (ui->checkMaleDuze->isChecked())
    {
        // Rozważ wielkie i małe litery
        retValue = textEdit->find(ui->textSzukaj->text(), QTextDocument::FindCaseSensitively);
    }
    else
    {
        // Bez rozróżniania wielkości liter
        retValue = textEdit->find(ui->textSzukaj->text());
    }

    // Po znalezieniu wyszukiwanego terminu zwiększ wartość findCounter
    findCounter += (retValue) ? 1 : 0;

    if (!retValue)
    {
        // brak komunikatu, jeśli wybrano „Zamień wszystko”
        if (replaceAllFlag)
            replaceAllFlag = false;
        else
        {
            // Do tej pory znaleziono co najmniej 1 wyszukiwane hasło
            if (findCounter > 0)
            {
                msgValue = showEndOfTextMessage();
                if (msgValue == QMessageBox::Yes)
                {
                    // Umieść kursor tekstowy na początku tekstu
                    QTextCursor cursor = textEdit->textCursor();
                    cursor.movePosition(QTextCursor::MoveOperation::Start);
                    textEdit->setTextCursor(cursor);

                    findCounter = 0;

                    retValue = findText();
                }
            }
            else
                QMessageBox::information(this, this->windowTitle(),
                                         tr("Podany ciag nie zostal znaleziony"));
        }
    }
    return retValue;

}

bool SearchAndReplaceDial::replaceText()
{

    QTextCursor cursor = textEdit->textCursor();

    if (cursor.hasSelection())
    {

        // Male/Duze lisery uwzgledniac
        if (ui->checkMaleDuze->isChecked() &&
            textEdit->textCursor().selectedText().compare(ui->textSzukaj->text(), Qt::CaseSensitive) == 0)
        {
             textEdit->textCursor().insertText(ui->textZastap->text());
             replaceCounter++;
        }
        // Male/Duze lisery nie uwzgledniac
        else if (!ui->checkMaleDuze->isChecked() &&
                  textEdit->textCursor().selectedText().compare(ui->textSzukaj->text(), Qt::CaseInsensitive) == 0)
        {
            textEdit->textCursor().insertText(ui->textSzukaj->text());
            replaceCounter++;
        }

    }

    // Wybierz następne wyszukiwane hasło
    return findText();

}

void SearchAndReplaceDial::replaceAllText()
{
    findCounter = 0;
    replaceCounter = 0;

    replaceAllFlag = true;

    // Umieść TextCursor na początku tekstu
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::MoveOperation::Start);
    textEdit->setTextCursor(cursor);

    while(replaceText()) {}

    // Umieść TextCursor z powrotem na początku tekstu
    cursor.movePosition(QTextCursor::MoveOperation::Start);
    textEdit->setTextCursor(cursor);

    if (replaceCounter > 0)
        QMessageBox::information(this, this->windowTitle(),
                                 QString(tr("Zastapiono %L1 Fragmentow tekstu")).arg(replaceCounter));
    else
        QMessageBox::information(this, this->windowTitle(),
                                 tr("Podany ciąg nie został znaleziony"));

    findCounter = 0;
    replaceCounter = 0;

}

int SearchAndReplaceDial::showEndOfTextMessage()
{
    return QMessageBox::question(this, this->windowTitle(),
                                 tr("Wyszukiwanie osiągnęło koniec tekstu.\nKontynuuj wyszukiwanie od początku tekstu"),
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

}

void SearchAndReplaceDial::on_btnSzukajDalej_clicked()
{
    findText();

}

void SearchAndReplaceDial::on_textSzukaj_textChanged(const QString&)
{
    // Szukany tekst zostal zmieniony
    findCounter = 0;

    enableButtons();

}

void SearchAndReplaceDial::on_textSzukaj_returnPressed()
{
    this->focusNextChild();

}

void SearchAndReplaceDial::on_textZastap_returnPressed()
{
    // Ustawia fokus na nastepny element
    this->focusNextChild();

}

void SearchAndReplaceDial::on_btnZastap_clicked()
{
    replaceText();

}

void SearchAndReplaceDial::on_btnZastapWszystko_clicked()
{
    replaceAllText();

}

void SearchAndReplaceDial::on_btnAnuluj_clicked()
{
    close();

}

void SearchAndReplaceDial::closeEvent(QCloseEvent*)
{
    emit windowClosed(this);

}

