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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionNew;
    QAction *actionBold;
    QAction *actionClear;
    QAction *actionOpen;
    QAction *actionUnderline;
    QAction *actionItalic;
    QAction *actionColor;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionAbout;
    QAction *actionSelectAll;
    QAction *actionExit;
    QAction *actionLineWrap;
    QAction *actionShowStatusBar;
    QAction *actionShowToolbar;
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon);
        actionSave->setMenuRole(QAction::MenuRole::NoRole);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/\345\244\215\345\210\266.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCopy->setIcon(icon1);
        actionCopy->setMenuRole(QAction::MenuRole::NoRole);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/\347\262\230\350\264\264.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPaste->setIcon(icon2);
        actionPaste->setMenuRole(QAction::MenuRole::NoRole);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/\345\211\252\345\210\207.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCut->setIcon(icon3);
        actionCut->setMenuRole(QAction::MenuRole::NoRole);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/\346\226\260\345\273\272\347\233\256\345\275\225.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon4);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName("actionBold");
        actionBold->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/\347\262\227\344\275\223.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBold->setIcon(icon5);
        actionBold->setMenuRole(QAction::MenuRole::NoRole);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/ic_\346\270\205\347\251\272.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionClear->setIcon(icon6);
        actionClear->setMenuRole(QAction::MenuRole::NoRole);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon7);
        actionOpen->setMenuRole(QAction::MenuRole::NoRole);
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName("actionUnderline");
        actionUnderline->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/\344\270\213\345\210\222\347\272\277.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionUnderline->setIcon(icon8);
        actionUnderline->setMenuRole(QAction::MenuRole::NoRole);
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName("actionItalic");
        actionItalic->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/\346\226\234\344\275\223.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionItalic->setIcon(icon9);
        actionItalic->setMenuRole(QAction::MenuRole::NoRole);
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName("actionColor");
        actionColor->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/\351\242\234\350\211\262.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionColor->setIcon(icon10);
        actionColor->setMenuRole(QAction::MenuRole::NoRole);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/\346\222\244\351\224\200.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionUndo->setIcon(icon11);
        actionUndo->setMenuRole(QAction::MenuRole::NoRole);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/\346\225\260\346\215\256\346\201\242\345\244\215.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRedo->setIcon(icon12);
        actionRedo->setMenuRole(QAction::MenuRole::NoRole);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/24gf-lookup2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFind->setIcon(icon13);
        actionFind->setMenuRole(QAction::MenuRole::NoRole);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName("actionReplace");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/\346\233\277\346\215\242.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionReplace->setIcon(icon14);
        actionReplace->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName("actionSelectAll");
        actionSelectAll->setMenuRole(QAction::MenuRole::NoRole);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setMenuRole(QAction::MenuRole::NoRole);
        actionLineWrap = new QAction(MainWindow);
        actionLineWrap->setObjectName("actionLineWrap");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/\350\207\252\345\212\250\346\215\242\350\241\214.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionLineWrap->setIcon(icon15);
        actionLineWrap->setMenuRole(QAction::MenuRole::NoRole);
        actionShowStatusBar = new QAction(MainWindow);
        actionShowStatusBar->setObjectName("actionShowStatusBar");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/3\347\212\266\346\200\201\346\240\217.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionShowStatusBar->setIcon(icon16);
        actionShowStatusBar->setMenuRole(QAction::MenuRole::NoRole);
        actionShowToolbar = new QAction(MainWindow);
        actionShowToolbar->setObjectName("actionShowToolbar");
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/\345\267\245\345\205\267\346\240\217.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionShowToolbar->setIcon(icon17);
        actionShowToolbar->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(3, 0, 801, 531));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionSave);
        menu->addAction(actionOpen);
        menu->addAction(actionExit);
        menu_2->addAction(actionCopy);
        menu_2->addAction(actionPaste);
        menu_2->addAction(actionClear);
        menu_2->addAction(actionCut);
        menu_2->addAction(actionRedo);
        menu_2->addAction(actionUndo);
        menu_2->addAction(actionFind);
        menu_2->addAction(actionReplace);
        menu_2->addAction(actionSelectAll);
        menu_3->addAction(actionLineWrap);
        menu_3->addAction(actionColor);
        menu_4->addAction(actionShowToolbar);
        menu_4->addAction(actionShowStatusBar);
        menu_5->addAction(actionAbout);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addSeparator();
        toolBar->addAction(actionBold);
        toolBar->addAction(actionUnderline);
        toolBar->addAction(actionItalic);
        toolBar->addAction(actionColor);
        toolBar->addSeparator();
        toolBar->addAction(actionLineWrap);
        toolBar->addAction(actionShowStatusBar);
        toolBar->addAction(actionShowToolbar);

        retranslateUi(MainWindow);
        QObject::connect(actionCopy, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::copy));
        QObject::connect(actionCut, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::cut));
        QObject::connect(actionPaste, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::paste));
        QObject::connect(actionClear, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::clear));
        QObject::connect(actionNew, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::clear));
        QObject::connect(actionUndo, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::undo));
        QObject::connect(actionRedo, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::redo));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        actionBold->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actionUnderline->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
        actionItalic->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
        actionColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        actionReplace->setText(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        actionSelectAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionLineWrap->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        actionShowStatusBar->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        actionShowToolbar->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
        plainTextEdit->setPlainText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
