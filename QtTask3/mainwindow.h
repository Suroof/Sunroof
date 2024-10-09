<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;


private slots:
    void onButtonClicked();
    void onOperatorClicked();
    void calculateResult();
    void clear();
    void backspace();
    void onDecimalClicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;


private slots:
    void onButtonClicked();
    void onOperatorClicked();
    void calculateResult();
    void clear();
    void backspace();
    void onDecimalClicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
>>>>>>> f8f427154cd2cb28f912abfce2b95a1a3b0fc219
