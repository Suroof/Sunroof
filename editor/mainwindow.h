#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QFontComboBox>
#include <QLabel>
#include <QColorDialog>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QDir>
#include <QFile>

// 前向声明
class SearchDialog;
class ReplaceDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionBold_triggered(bool checked);
    void on_plainTextEdit_copyAvailable(bool b);
    void on_spinFontSize_valueChanged(int aFontsize);
    void on_comboFont_currentIndexChanged(const QString &text);
    void on_actionItalic_triggered(bool checked);
    void on_actionUnderline_triggered(bool checked);
    void on_actionColor_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_acitonNew_triggered();
    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionAbout_triggered();
    void on_actionSelectAll_triggered();
    void on_actionExit_triggered();
    void on_actionShowToolbar_triggered();
    void on_actionShowStatusBar_triggered();  // 修改为正确的名称
    void on_actionLineWrap_triggered(bool checked);
private:
    Ui::MainWindow *ui;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;
    QLabel *currentFile;
    QString file_path_;
    QPlainTextEdit *pTextEdit;  // 添加文本编辑器指针
    QLabel statusCursorLabel;
    QLabel statusLabel;
    QAction *actionLineWrap;
    QAction *actionShowStatusBar;
    QAction *actionShowToolbar;

    void initUI();
    void initConnections();
};

#endif // MAINWINDOW_H
