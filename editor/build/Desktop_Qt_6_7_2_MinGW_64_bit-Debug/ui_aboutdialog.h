/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName("AboutDialog");
        AboutDialog->resize(715, 300);
        label = new QLabel(AboutDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 0, 291, 61));
        label->setStyleSheet(QString::fromUtf8("font-size:50px;"));
        label->setIndent(-1);
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 100, 111, 19));
        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 150, 181, 19));
        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(350, 200, 231, 19));
        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 60, 221, 221));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/images/OIP-C.jfif);\n"
""));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AboutDialog", "\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("AboutDialog", "\345\274\200\345\217\221\350\200\205:\347\237\263\346\266\246\345\263\260", nullptr));
        label_3->setText(QCoreApplication::translate("AboutDialog", "\345\255\246\345\217\267\357\274\2322022414040131", nullptr));
        label_4->setText(QCoreApplication::translate("AboutDialog", "email\357\274\2322663159189@qq.com", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
