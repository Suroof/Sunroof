/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QLineEdit *searchText;
    QLabel *label;
    QPushButton *btFindNext;
    QPushButton *btCancel;
    QCheckBox *checkBox;
    QRadioButton *rbUp;
    QRadioButton *rbDown;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName("SearchDialog");
        SearchDialog->resize(672, 300);
        searchText = new QLineEdit(SearchDialog);
        searchText->setObjectName("searchText");
        searchText->setGeometry(QRect(180, 40, 161, 25));
        label = new QLabel(SearchDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 40, 91, 19));
        btFindNext = new QPushButton(SearchDialog);
        btFindNext->setObjectName("btFindNext");
        btFindNext->setGeometry(QRect(450, 60, 93, 28));
        btCancel = new QPushButton(SearchDialog);
        btCancel->setObjectName("btCancel");
        btCancel->setGeometry(QRect(450, 100, 93, 28));
        checkBox = new QCheckBox(SearchDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(120, 120, 98, 23));
        rbUp = new QRadioButton(SearchDialog);
        rbUp->setObjectName("rbUp");
        rbUp->setGeometry(QRect(230, 120, 118, 23));
        rbDown = new QRadioButton(SearchDialog);
        rbDown->setObjectName("rbDown");
        rbDown->setGeometry(QRect(310, 120, 118, 23));

        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "Dialog", nullptr));
        searchText->setText(QString());
        label->setText(QCoreApplication::translate("SearchDialog", "\346\237\245\346\211\276\347\233\256\346\240\207:", nullptr));
        btFindNext->setText(QCoreApplication::translate("SearchDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", nullptr));
        btCancel->setText(QCoreApplication::translate("SearchDialog", "\345\217\226\346\266\210", nullptr));
        checkBox->setText(QCoreApplication::translate("SearchDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        rbUp->setText(QCoreApplication::translate("SearchDialog", "\345\220\221\344\270\212", nullptr));
        rbDown->setText(QCoreApplication::translate("SearchDialog", "\345\220\221\344\270\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
