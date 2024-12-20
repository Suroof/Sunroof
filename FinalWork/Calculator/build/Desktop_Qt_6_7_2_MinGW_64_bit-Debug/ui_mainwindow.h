/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *btnStandard;
    QAction *btnScientific;
    QAction *btnProgrammer;
    QAction *btnDate;
    QAction *btnConverter;
    QWidget *centralwidget;
    QStackedWidget *modeStack;
    QWidget *page;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_20;
    QPushButton *pushButton_5;
    QPushButton *pushButton_14;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_18;
    QPushButton *pushButton_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton_25;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_19;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_17;
    QPushButton *pushButton_11;
    QPushButton *pushButton_23;
    QPushButton *pushButton_21;
    QPushButton *pushButton;
    QPushButton *pushButton_22;
    QPushButton *pushButton_24;
    QPushButton *pushButton_16;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QLabel *label;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(852, 705);
        btnStandard = new QAction(MainWindow);
        btnStandard->setObjectName("btnStandard");
        btnStandard->setMenuRole(QAction::MenuRole::NoRole);
        btnScientific = new QAction(MainWindow);
        btnScientific->setObjectName("btnScientific");
        btnScientific->setMenuRole(QAction::MenuRole::NoRole);
        btnProgrammer = new QAction(MainWindow);
        btnProgrammer->setObjectName("btnProgrammer");
        btnProgrammer->setMenuRole(QAction::MenuRole::NoRole);
        btnDate = new QAction(MainWindow);
        btnDate->setObjectName("btnDate");
        btnDate->setMenuRole(QAction::MenuRole::NoRole);
        btnConverter = new QAction(MainWindow);
        btnConverter->setObjectName("btnConverter");
        btnConverter->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        modeStack = new QStackedWidget(centralwidget);
        modeStack->setObjectName("modeStack");
        modeStack->setGeometry(QRect(0, -20, 851, 671));
        page = new QWidget();
        page->setObjectName("page");
        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 50, 681, 401));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 0, 1, 1, 1);

        pushButton_20 = new QPushButton(widget);
        pushButton_20->setObjectName("pushButton_20");

        gridLayout->addWidget(pushButton_20, 1, 3, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 1, 0, 1, 1);

        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName("pushButton_14");

        gridLayout->addWidget(pushButton_14, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName("pushButton_18");

        gridLayout->addWidget(pushButton_18, 4, 3, 1, 1);

        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName("pushButton_15");

        gridLayout->addWidget(pushButton_15, 1, 2, 1, 1);

        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName("pushButton_13");

        gridLayout->addWidget(pushButton_13, 4, 2, 1, 1);

        pushButton_25 = new QPushButton(widget);
        pushButton_25->setObjectName("pushButton_25");

        gridLayout->addWidget(pushButton_25, 1, 4, 1, 1);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 3, 1, 1, 1);

        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName("pushButton_12");

        gridLayout->addWidget(pushButton_12, 2, 2, 1, 1);

        pushButton_19 = new QPushButton(widget);
        pushButton_19->setObjectName("pushButton_19");

        gridLayout->addWidget(pushButton_19, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout->addWidget(pushButton_10, 1, 1, 1, 1);

        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName("pushButton_17");

        gridLayout->addWidget(pushButton_17, 2, 3, 1, 1);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout->addWidget(pushButton_11, 3, 2, 1, 1);

        pushButton_23 = new QPushButton(widget);
        pushButton_23->setObjectName("pushButton_23");

        gridLayout->addWidget(pushButton_23, 4, 4, 1, 1);

        pushButton_21 = new QPushButton(widget);
        pushButton_21->setObjectName("pushButton_21");

        gridLayout->addWidget(pushButton_21, 3, 4, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);

        pushButton_22 = new QPushButton(widget);
        pushButton_22->setObjectName("pushButton_22");

        gridLayout->addWidget(pushButton_22, 2, 4, 1, 1);

        pushButton_24 = new QPushButton(widget);
        pushButton_24->setObjectName("pushButton_24");

        gridLayout->addWidget(pushButton_24, 0, 4, 1, 1);

        pushButton_16 = new QPushButton(widget);
        pushButton_16->setObjectName("pushButton_16");

        gridLayout->addWidget(pushButton_16, 3, 3, 1, 1);

        pushButton_26 = new QPushButton(widget);
        pushButton_26->setObjectName("pushButton_26");

        gridLayout->addWidget(pushButton_26, 5, 0, 1, 1);

        pushButton_27 = new QPushButton(widget);
        pushButton_27->setObjectName("pushButton_27");

        gridLayout->addWidget(pushButton_27, 5, 1, 1, 1);

        pushButton_28 = new QPushButton(widget);
        pushButton_28->setObjectName("pushButton_28");

        gridLayout->addWidget(pushButton_28, 5, 2, 1, 1);

        pushButton_29 = new QPushButton(widget);
        pushButton_29->setObjectName("pushButton_29");

        gridLayout->addWidget(pushButton_29, 5, 3, 1, 1);

        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 30, 111, 19));
        modeStack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        modeStack->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 852, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        modeStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnStandard->setText(QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206\345\236\213", nullptr));
#if QT_CONFIG(tooltip)
        btnStandard->setToolTip(QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        btnScientific->setText(QCoreApplication::translate("MainWindow", "\347\247\221\345\255\246\345\236\213", nullptr));
        btnProgrammer->setText(QCoreApplication::translate("MainWindow", "\347\250\213\345\272\217\345\221\230", nullptr));
        btnDate->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237\350\256\241\347\256\227", nullptr));
        btnConverter->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215\350\275\254\346\215\242", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "M+", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", " \342\210\232", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "M-", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\244\232\345\212\237\350\203\275\350\256\241\347\256\227\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
