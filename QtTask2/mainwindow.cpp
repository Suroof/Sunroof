#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include <QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // 设置窗口图标
    setWindowIcon(QIcon(":/new/images/C:/Users/Administrator/Downloads/icon.png"));
    setFixedSize(800, 600); // 设置窗口大小为800x600
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    AboutDialog aboutDialog(this);  // 创建 AboutDialog 实例
    aboutDialog.exec();              // 显示对话框
}
