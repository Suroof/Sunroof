#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QDockWidget>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QComboBox>
#include <QTranslator>
#include <QApplication>
#include "calculatorcore.h"
#include "historypanel.h"
#include "unitconverter.h"
#include "settingsmanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum CalculatorMode {
        Standard,
        Scientific,
        Programmer,
        DateCalculator
    };

private slots:
    void switchCalculatorMode(CalculatorMode mode);
    void toggleTheme();
    void switchLanguage(const QString& locale);
    void updateDisplay();
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearDisplay();
    void addToHistory(const QString &expression, const QString &result);
    void clearHistory();
    void scientificButtonClicked();
    void programmerButtonClicked();
    void baseChanged(int base);
    void dateCalculateClicked();
    void unitTypeChanged(int index);
    void convertUnit();
    void historyItemClicked(QListWidgetItem *item);

private:
    QStackedWidget *modeStack;
    QListWidget *historyList;
    QPushButton *clearHistoryBtn;
    CalculatorCore *calcCore;
    UnitConverter *unitConverter;
    SettingsManager *settings;
    QLabel *modeLabel;        // 状态栏模式标签
    QActionGroup *modeGroup;  // 模式切换按钮组

    void setupUI();
    void createConnections();
    void loadSettings();
    void saveSettings();
    void setupStandardUI(QWidget *standardPage);
    void setupScientificUI(QWidget *scientificPage);
    void setupProgrammerUI(QWidget *programmerPage);
    void setupDateCalculatorUI(QWidget *datePage);
    void setupConverterUI(QWidget *converterPage);
    void setupHistoryPanel();

    QButtonGroup *baseButtonGroup;  // 用于进制选择按钮组
    QDateEdit *startDateEdit;       // 起始日期选择器
    QDateEdit *endDateEdit;         // 结束日期选择器
    QComboBox *unitTypeCombo;      // 单位类型选择
    QComboBox *fromUnitCombo;      // 源单位选择
    QComboBox *toUnitCombo;        // 目标单位选择
    QLineEdit *fromValueEdit;      // 源值输入
    QLineEdit *resultValueEdit;    // 结果显示
    QString firstOperand;        // 第一个操作数
    QString currentOperation;    // 当前操作
    CalculatorCore::NumberBase currentBase = CalculatorCore::Decimal;  // 当前进制

    void retranslateUI();
    QString formatNumberForBase(qlonglong number, int base);
};

#endif // MAINWINDOW_H
