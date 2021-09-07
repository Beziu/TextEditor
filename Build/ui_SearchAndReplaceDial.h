/********************************************************************************
** Form generated from reading UI file 'SearchAndReplaceDial.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHANDREPLACEDIAL_H
#define UI_SEARCHANDREPLACEDIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchAndReplaceDial
{
public:
    QLabel *lblSzukaj;
    QLineEdit *textSzukaj;
    QLabel *lblZastap;
    QLineEdit *textZastap;
    QCheckBox *checkMaleDuze;
    QPushButton *btnSzukajDalej;
    QPushButton *btnZastap;
    QPushButton *btnAnuluj;
    QPushButton *btnZastapWszystko;

    void setupUi(QDialog *SearchAndReplaceDial)
    {
        if (SearchAndReplaceDial->objectName().isEmpty())
            SearchAndReplaceDial->setObjectName(QString::fromUtf8("SearchAndReplaceDial"));
        SearchAndReplaceDial->resize(560, 160);
        SearchAndReplaceDial->setMinimumSize(QSize(560, 160));
        SearchAndReplaceDial->setMaximumSize(QSize(560, 160));
        QFont font;
        font.setPointSize(10);
        SearchAndReplaceDial->setFont(font);
        lblSzukaj = new QLabel(SearchAndReplaceDial);
        lblSzukaj->setObjectName(QString::fromUtf8("lblSzukaj"));
        lblSzukaj->setGeometry(QRect(10, 10, 76, 20));
        textSzukaj = new QLineEdit(SearchAndReplaceDial);
        textSzukaj->setObjectName(QString::fromUtf8("textSzukaj"));
        textSzukaj->setGeometry(QRect(75, 5, 330, 30));
        textSzukaj->setClearButtonEnabled(true);
        lblZastap = new QLabel(SearchAndReplaceDial);
        lblZastap->setObjectName(QString::fromUtf8("lblZastap"));
        lblZastap->setGeometry(QRect(10, 50, 76, 20));
        textZastap = new QLineEdit(SearchAndReplaceDial);
        textZastap->setObjectName(QString::fromUtf8("textZastap"));
        textZastap->setGeometry(QRect(75, 45, 330, 30));
        checkMaleDuze = new QCheckBox(SearchAndReplaceDial);
        checkMaleDuze->setObjectName(QString::fromUtf8("checkMaleDuze"));
        checkMaleDuze->setGeometry(QRect(80, 95, 176, 30));
        btnSzukajDalej = new QPushButton(SearchAndReplaceDial);
        btnSzukajDalej->setObjectName(QString::fromUtf8("btnSzukajDalej"));
        btnSzukajDalej->setGeometry(QRect(410, 5, 140, 30));
        btnSzukajDalej->setAutoDefault(false);
        btnZastap = new QPushButton(SearchAndReplaceDial);
        btnZastap->setObjectName(QString::fromUtf8("btnZastap"));
        btnZastap->setGeometry(QRect(410, 45, 140, 30));
        btnZastap->setAutoDefault(false);
        btnAnuluj = new QPushButton(SearchAndReplaceDial);
        btnAnuluj->setObjectName(QString::fromUtf8("btnAnuluj"));
        btnAnuluj->setGeometry(QRect(410, 120, 140, 30));
        btnAnuluj->setAutoDefault(false);
        btnZastapWszystko = new QPushButton(SearchAndReplaceDial);
        btnZastapWszystko->setObjectName(QString::fromUtf8("btnZastapWszystko"));
        btnZastapWszystko->setGeometry(QRect(410, 80, 140, 30));
        btnZastapWszystko->setAutoDefault(false);
        QWidget::setTabOrder(textSzukaj, textZastap);
        QWidget::setTabOrder(textZastap, checkMaleDuze);
        QWidget::setTabOrder(checkMaleDuze, btnSzukajDalej);
        QWidget::setTabOrder(btnSzukajDalej, btnZastap);
        QWidget::setTabOrder(btnZastap, btnZastapWszystko);
        QWidget::setTabOrder(btnZastapWszystko, btnAnuluj);

        retranslateUi(SearchAndReplaceDial);

        QMetaObject::connectSlotsByName(SearchAndReplaceDial);
    } // setupUi

    void retranslateUi(QDialog *SearchAndReplaceDial)
    {
        SearchAndReplaceDial->setWindowTitle(QCoreApplication::translate("SearchAndReplaceDial", "Szukaj i Zastap", nullptr));
        lblSzukaj->setText(QCoreApplication::translate("SearchAndReplaceDial", "Szukaj:", nullptr));
        lblZastap->setText(QCoreApplication::translate("SearchAndReplaceDial", "Zastap:", nullptr));
        checkMaleDuze->setText(QCoreApplication::translate("SearchAndReplaceDial", "Duze/Male litery", nullptr));
        btnSzukajDalej->setText(QCoreApplication::translate("SearchAndReplaceDial", "Szukaj / Dalej", nullptr));
        btnZastap->setText(QCoreApplication::translate("SearchAndReplaceDial", "Zastap", nullptr));
        btnAnuluj->setText(QCoreApplication::translate("SearchAndReplaceDial", "Anuluj", nullptr));
        btnZastapWszystko->setText(QCoreApplication::translate("SearchAndReplaceDial", "Zastap wszystkie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchAndReplaceDial: public Ui_SearchAndReplaceDial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHANDREPLACEDIAL_H
