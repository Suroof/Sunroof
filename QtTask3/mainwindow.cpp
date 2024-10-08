#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJSEngine>
#include <QMessageBox>
#include <QString>
#include <QJSValue>
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setReadOnly(true);

    // 信号与槽连接
    connect(ui->button0, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button5, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button6, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button7, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button8, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->button9, &QPushButton::clicked, this, &MainWindow::onButtonClicked);


    connect(ui->buttonAdd, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->buttonSubtract, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->buttonMultiply, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->buttonDivide, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->buttonDecimal, &QPushButton::clicked, this, &MainWindow::onDecimalClicked);
    connect(ui->buttonEquals, &QPushButton::clicked, this, &MainWindow::calculateResult);
    connect(ui->buttonClear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->buttonBackspace, &QPushButton::clicked, this, &MainWindow::backspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        ui->lineEdit->setText(ui->lineEdit->text() + button->text());
    }
}

void MainWindow::onDecimalClicked()
{
    QString text = ui->lineEdit->text();
    if (!text.isEmpty() && !text.endsWith('.')) {
        ui->lineEdit->setText(text + ".");
    }
}

void MainWindow::onOperatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        ui->lineEdit->setText(ui->lineEdit->text() + " " + button->text() + " ");
    }
}

void MainWindow::calculateResult()
{
    QString input = ui->lineEdit->text();
    // 创建 QJSEngine 实例
    QJSEngine engine;

    // 解析并计算输入表达式
    QJSValue result = engine.evaluate(input);

    // 检查计算是否成功
    if (result.isError()) {
        // 如果有错误，显示错误消息
        QJSValue errorObject = result.property("value");
        QString errorMessage = errorObject.property("message").toString();
        QMessageBox::warning(this, "错误！", errorMessage);
    } else {

        ui->lineEdit->setText(result.toString()); // 这里假设表达式返回的是可以直接转换为字符串的值
    }
}

void MainWindow::clear()
{
    ui->lineEdit->clear();
}

void MainWindow::backspace()
{
    QString text = ui->lineEdit->text();
    if (!text.isEmpty()) {
        text.chop(1); // 删除最后一个字符
        ui->lineEdit->setText(text);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // 检查按下的键
    switch (event->key()) {
    case Qt::Key_0: case Qt::Key_1: case Qt::Key_2: case Qt::Key_3:
    case Qt::Key_4: case Qt::Key_5: case Qt::Key_6: case Qt::Key_7:
    case Qt::Key_8: case Qt::Key_9:
        // 如果是数字键，则将其添加到 lineEdit 中
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(event->key() - Qt::Key_0));
        break;
    case Qt::Key_Plus:
        // 如果是加号键，则添加 "+" 到 lineEdit 中
        ui->lineEdit->setText(ui->lineEdit->text() + " + ");
        break;
    case Qt::Key_Minus:
        // 如果是减号键，则添加 "-" 到 lineEdit 中
        ui->lineEdit->setText(ui->lineEdit->text() + " - ");
        break;
    case Qt::Key_Asterisk:
        // 如果是乘号键（*），则添加 "*" 到 lineEdit 中
        // 注意：Qt 中没有直接的 Qt::Key_Multiply，但可以使用 Qt::Key_Asterisk
        ui->lineEdit->setText(ui->lineEdit->text() + " * ");
        break;
    case Qt::Key_Slash:
        // 如果是除号键，则添加 "/" 到 lineEdit 中
        ui->lineEdit->setText(ui->lineEdit->text() + " / ");
        break;
    case Qt::Key_Enter: case Qt::Key_Return:
        // 如果是回车键，则计算表达式
        calculateResult();
        break;
    case Qt::Key_Backspace:
        // 如果是退格键，则删除 lineEdit 中的最后一个字符
        backspace();
        break;
    case Qt::Key_Clear:
        // 注意：Qt 没有直接的 Qt::Key_Clear 键，这通常是一个特殊的按键（如计算器上的 "C" 键）
        // 如果你想要一个清除所有内容的快捷键，你可能需要选择一个不同的键并手动处理它
        // 例如，你可以使用 Ctrl+C 作为组合键来清除内容（但这需要额外的代码来处理）
        // 这里不处理 Qt::Key_Clear，因为它不是标准键盘上的键
        break;
    default:
        // 对于其他键，不执行任何操作或可以选择性地处理它们
        break;
    }

    // 默认情况下，调用基类的 keyPressEvent 方法以处理未在此处处理的键
    QMainWindow::keyPressEvent(event);
}

