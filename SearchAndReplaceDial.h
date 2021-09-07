#ifndef SEARCHANDREPLACEDIAL_H
#define SEARCHANDREPLACEDIAL_H

#include <QDialog>
#include <QTextEdit>
#include <QMessageBox>

namespace Ui {
class SearchAndReplaceDial;
}

class SearchAndReplaceDial : public QDialog
{
    Q_OBJECT

public:
    explicit SearchAndReplaceDial(QTextEdit* textEdit, QWidget *parent = nullptr);
    ~SearchAndReplaceDial();

signals:
    // Kiedy wywolamy z menu Dialog sie reaktywuje
    void windowClosed(const QWidget*);

private slots:
    void on_btnSzukajDalej_clicked();
    void on_textSzukaj_textChanged(const QString &arg1);
    void on_textSzukaj_returnPressed();
    void on_textZastap_returnPressed();
    void on_btnZastap_clicked();
    void on_btnZastapWszystko_clicked();
    void on_btnAnuluj_clicked();

    void closeEvent(QCloseEvent * event) override;

private:
    Ui::SearchAndReplaceDial *ui;

    QTextEdit* textEdit;

    int findCounter;
    int replaceCounter;
    bool replaceAllFlag;

    void init();
    void enableButtons();
    bool findText();
    bool replaceText();
    void replaceAllText();
    int showEndOfTextMessage();

};

#endif // SEARCHANDREPLACEDIAL_H
