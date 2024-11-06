/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QPushButton *btFind;
    QLabel *label;
    QRadioButton *rbDown;
    QCheckBox *checkCase;
    QRadioButton *rbUp;
    QLineEdit *findText;
    QPushButton *btReplace;
    QLabel *label_2;
    QLineEdit *replaceText;
    QPushButton *btReplaceAll;
    QPushButton *btCancel;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName("ReplaceDialog");
        ReplaceDialog->resize(679, 300);
        btFind = new QPushButton(ReplaceDialog);
        btFind->setObjectName("btFind");
        btFind->setGeometry(QRect(390, 40, 93, 28));
        label = new QLabel(ReplaceDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 91, 19));
        rbDown = new QRadioButton(ReplaceDialog);
        rbDown->setObjectName("rbDown");
        rbDown->setGeometry(QRect(250, 120, 118, 23));
        checkCase = new QCheckBox(ReplaceDialog);
        checkCase->setObjectName("checkCase");
        checkCase->setGeometry(QRect(60, 120, 98, 23));
        rbUp = new QRadioButton(ReplaceDialog);
        rbUp->setObjectName("rbUp");
        rbUp->setGeometry(QRect(170, 120, 118, 23));
        findText = new QLineEdit(ReplaceDialog);
        findText->setObjectName("findText");
        findText->setGeometry(QRect(120, 40, 161, 25));
        btReplace = new QPushButton(ReplaceDialog);
        btReplace->setObjectName("btReplace");
        btReplace->setGeometry(QRect(390, 80, 93, 28));
        label_2 = new QLabel(ReplaceDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 91, 19));
        replaceText = new QLineEdit(ReplaceDialog);
        replaceText->setObjectName("replaceText");
        replaceText->setGeometry(QRect(120, 80, 161, 25));
        btReplaceAll = new QPushButton(ReplaceDialog);
        btReplaceAll->setObjectName("btReplaceAll");
        btReplaceAll->setGeometry(QRect(390, 130, 93, 28));
        btCancel = new QPushButton(ReplaceDialog);
        btCancel->setObjectName("btCancel");
        btCancel->setGeometry(QRect(390, 170, 93, 28));

        retranslateUi(ReplaceDialog);

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QCoreApplication::translate("ReplaceDialog", "Dialog", nullptr));
        btFind->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", nullptr));
        label->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\347\233\256\346\240\207:", nullptr));
        rbDown->setText(QCoreApplication::translate("ReplaceDialog", "\345\220\221\344\270\213", nullptr));
        checkCase->setText(QCoreApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        rbUp->setText(QCoreApplication::translate("ReplaceDialog", "\345\220\221\344\270\212", nullptr));
        findText->setText(QString());
        btReplace->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", nullptr));
        label_2->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\344\270\272\357\274\232", nullptr));
        replaceText->setText(QString());
        btReplaceAll->setText(QCoreApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242", nullptr));
        btCancel->setText(QCoreApplication::translate("ReplaceDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
