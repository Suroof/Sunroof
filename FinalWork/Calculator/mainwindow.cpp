#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QRegularExpression>
#include <QToolBar>
#include <QActionGroup>
#include <QStatusBar>
#include <QInputDialog>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QComboBox>
#include <QTranslator>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建核心组件
    calcCore = new CalculatorCore();
    unitConverter = new UnitConverter(this);
    settings = new SettingsManager(this);

    // 设置窗口属性
    setWindowTitle(tr("多功能计算器"));
    resize(800, 600);

    // 创建界面
    setupUI();
    createConnections();

    // 加载设置
    loadSettings();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    // 设置窗口标题和大小
    setWindowTitle(tr("多功能计算器"));
    resize(800, 600);  // 调整为更大的尺寸以适应侧边栏

    // 创建主布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    // 创建模式堆栈窗口
    modeStack = new QStackedWidget;
    mainLayout->addWidget(modeStack);

    // 创建标准计算器页面
    QWidget *standardPage = new QWidget;
    setupStandardUI(standardPage);
    modeStack->addWidget(standardPage);

    // 创建科学计算器页面
    QWidget *scientificPage = new QWidget;
    setupScientificUI(scientificPage);
    modeStack->addWidget(scientificPage);

    // 创建程序员计算器页面
    QWidget *programmerPage = new QWidget;
    setupProgrammerUI(programmerPage);
    modeStack->addWidget(programmerPage);

    // 创建日期计算器页面
    QWidget *datePage = new QWidget;
    setupDateCalculatorUI(datePage);
    modeStack->addWidget(datePage);

    // 创建单位转换页面
    QWidget *converterPage = new QWidget;
    setupConverterUI(converterPage);
    modeStack->addWidget(converterPage);

    // 创建历史记录面板
    setupHistoryPanel();

    // 添加工具栏
    QToolBar *toolBar = addToolBar(tr("模式"));
    toolBar->setMovable(false);

    // 添加模式切换按钮
    QAction *actionStandard = toolBar->addAction(tr("标准型"));
    actionStandard->setObjectName("actionStandard");
    actionStandard->setCheckable(true);
    actionStandard->setChecked(true);

    QAction *actionScientific = toolBar->addAction(tr("科学型"));
    actionScientific->setObjectName("actionScientific");
    actionScientific->setCheckable(true);

    QAction *actionProgrammer = toolBar->addAction(tr("程序员"));
    actionProgrammer->setObjectName("actionProgrammer");
    actionProgrammer->setCheckable(true);

    QAction *actionDate = toolBar->addAction(tr("日期计算"));
    actionDate->setObjectName("actionDate");
    actionDate->setCheckable(true);

    QAction *actionConverter = toolBar->addAction(tr("单位转换"));
    actionConverter->setObjectName("actionConverter");
    actionConverter->setCheckable(true);

    // 创建动作组，确保只有一个模式被选中
    modeGroup = new QActionGroup(this);
    modeGroup->addAction(actionStandard);
    modeGroup->addAction(actionScientific);
    modeGroup->addAction(actionProgrammer);
    modeGroup->addAction(actionDate);
    modeGroup->addAction(actionConverter);

    // 添加状态栏
    QStatusBar *statusBar = this->statusBar();
    statusBar->setSizeGripEnabled(false);  // 禁用右下角的大小调整控件

    // 添加当前模式标签
    modeLabel = new QLabel(tr("当前模式: 标准型"));
    statusBar->addWidget(modeLabel);

    // 添加语言切换按钮
    QPushButton *langButton = new QPushButton(tr("中文/EN"));
    langButton->setObjectName("langButton");  // 添加对象名
    statusBar->addPermanentWidget(langButton);

    // 添加主题切换按钮
    QPushButton *themeButton = new QPushButton(tr("日间/夜间"));
    themeButton->setObjectName("themeButton");  // 添加对象名
    statusBar->addPermanentWidget(themeButton);
}

void MainWindow::setupStandardUI(QWidget *standardPage)
{
    QVBoxLayout *standardLayout = new QVBoxLayout(standardPage);

    // 添加显示屏
    QLineEdit *display = new QLineEdit;
    display->setObjectName("displayEdit");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(50);
    standardLayout->addWidget(display);

    // 添加按钮网格
    QGridLayout *buttonGrid = new QGridLayout;

    // 第一行：内存操作
    const char* row1[] = {"MC", "MR", "M+", "M-", "MS"};
    for(int i = 0; i < 5; i++) {
        QPushButton *btn = new QPushButton(row1[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 0, i);
    }

    // 第二行：特殊功能
    const char* row2[] = {"←", "CE", "C", "±", "√"};
    for(int i = 0; i < 5; i++) {
        QPushButton *btn = new QPushButton(row2[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 1, i);
        if(row2[i] == QString("C")) {
            btn->setObjectName("clearButton");
            connect(btn, &QPushButton::clicked, this, &MainWindow::clearDisplay);
        }
    }

    // 数字和运算符
    const char* buttons[] = {
        "7", "8", "9", "/", "%",
        "4", "5", "6", "*", "1/x",
        "1", "2", "3", "-", "=",
        "0", ".", "=", "+"
    };

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            if(i*5 + j < static_cast<int>(sizeof(buttons)/sizeof(buttons[0]))) {
                QPushButton *btn = new QPushButton(buttons[i*5 + j]);
                btn->setMinimumSize(50, 40);
                buttonGrid->addWidget(btn, i+2, j);
                QString btnText = buttons[i*5 + j];
                if(btnText.contains(QRegularExpression("[0-9]"))) {
                    connect(btn, &QPushButton::clicked, this, &MainWindow::digitClicked);
                } else if(btnText != "=") {
                    connect(btn, &QPushButton::clicked, this, &MainWindow::operatorClicked);
                } else {
                    connect(btn, &QPushButton::clicked, this, &MainWindow::equalClicked);
                }
            }
        }
    }

    standardLayout->addLayout(buttonGrid);
}

void MainWindow::createConnections()
{
    // 连接工具栏动作
    QAction *actionStandard = findChild<QAction*>("actionStandard");
    if(actionStandard) {
        connect(actionStandard, &QAction::triggered, this, [this]() { switchCalculatorMode(Standard); });
    }

    QAction *actionScientific = findChild<QAction*>("actionScientific");
    if(actionScientific) {
        connect(actionScientific, &QAction::triggered, this, [this]() { switchCalculatorMode(Scientific); });
    }

    QAction *actionProgrammer = findChild<QAction*>("actionProgrammer");
    if(actionProgrammer) {
        connect(actionProgrammer, &QAction::triggered, this, [this]() { switchCalculatorMode(Programmer); });
    }

    QAction *actionDate = findChild<QAction*>("actionDate");
    if(actionDate) {
        connect(actionDate, &QAction::triggered, this, [this]() { switchCalculatorMode(DateCalculator); });
    }

    QAction *actionConverter = findChild<QAction*>("actionConverter");
    if(actionConverter) {
        connect(actionConverter, &QAction::triggered, this, [this]() {
            modeStack->setCurrentIndex(4);  // 切换到单位转换页面
            modeLabel->setText(tr("当前模式: 单位转换"));
        });
    }

    // 连接状态栏按钮
    QPushButton *langButton = findChild<QPushButton*>("langButton");
    if(langButton) {
        connect(langButton, &QPushButton::clicked, this, [this]() {
            bool isChinese = settings->getLanguage() == "zh_CN";
            switchLanguage(isChinese ? "en_US" : "zh_CN");
        });
    }

    QPushButton *themeButton = findChild<QPushButton*>("themeButton");
    if(themeButton) {
        connect(themeButton, &QPushButton::clicked, this, &MainWindow::toggleTheme);
    }

    // 连接历史记录点击信号
    connect(historyList, &QListWidget::itemClicked,
            this, &MainWindow::historyItemClicked);
}

void MainWindow::loadSettings()
{
    // 加载用户设置
}

void MainWindow::saveSettings()
{
    // 保存用户设置
}

void MainWindow::switchCalculatorMode(CalculatorMode mode)
{
    modeStack->setCurrentIndex(mode);
    calcCore->clear();  // 切换模式时清除计算器状态

    // 更新状态栏显示
    QString modeName;
    switch(mode) {
        case Standard: modeName = tr("标准型"); break;
        case Scientific: modeName = tr("科学型"); break;
        case Programmer: modeName = tr("程序员"); break;
        case DateCalculator: modeName = tr("日期计算"); break;
        default: modeName = tr("单位转换");
    }
    modeLabel->setText(tr("当前模式: ") + modeName);

    // 更新相应显示屏
    QLineEdit *display = nullptr;
    if (mode == Scientific) {
        display = findChild<QLineEdit*>("scientificDisplay");
    } else {
        display = findChild<QLineEdit*>("displayEdit");
    }
    if (display) {
        display->setText("0");
    }
}

void MainWindow::digitClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button) {
        calcCore->inputDigit(button->text());
        updateDisplay();
    }
}

void MainWindow::operatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button) {
        calcCore->inputOperator(button->text());
        updateDisplay();
    }
}

void MainWindow::equalClicked()
{
    calcCore->calculate();
    QString expression = calcCore->getLastExpression();
    QString result = calcCore->getCurrentDisplay();
    updateDisplay();

    // 添加到历史记录
    if (!expression.isEmpty() && !result.isEmpty()) {
        addToHistory(expression, result);
    }
}

void MainWindow::updateDisplay()
{
    QLineEdit *display = nullptr;
    if (modeStack->currentIndex() == Scientific) {
        display = findChild<QLineEdit*>("scientificDisplay");
    } else {
        display = findChild<QLineEdit*>("displayEdit");
    }

    if(display) {
        QString currentText = calcCore->getCurrentDisplay();
        display->setText(currentText);
    }
}

void MainWindow::toggleTheme()
{
    bool isDark = settings->getTheme() == "dark";
    QString newTheme = isDark ? "light" : "dark";
    settings->setTheme(newTheme);

    // 应用主题样式
    QString styleSheet;
    if (newTheme == "dark") {
        styleSheet = R"(
            QMainWindow, QWidget { background-color: #2b2b2b; color: #ffffff; }
            QLineEdit { background-color: #3b3b3b; color: #ffffff; border: 1px solid #555555; padding: 5px; }
            QPushButton { background-color: #3b3b3b; color: #ffffff; border: 1px solid #555555; padding: 5px; }
            QPushButton:hover { background-color: #4b4b4b; }
            QPushButton:pressed { background-color: #555555; }
            QGroupBox { border: 1px solid #555555; margin-top: 5px; }
            QGroupBox::title { color: #ffffff; }
            QComboBox { background-color: #3b3b3b; color: #ffffff; border: 1px solid #555555; padding: 5px; }
            QComboBox::drop-down { border: none; }
            QComboBox::down-arrow { image: url(:/icons/down_arrow_white.png); }
            QListWidget { background-color: #3b3b3b; color: #ffffff; border: 1px solid #555555; }
            QRadioButton { color: #ffffff; }
            QLabel { color: #ffffff; }
        )";
    } else {
        styleSheet = R"(
            QMainWindow, QWidget { background-color: #f0f0f0; color: #000000; }
            QLineEdit { background-color: #ffffff; color: #000000; border: 1px solid #cccccc; padding: 5px; }
            QPushButton { background-color: #ffffff; color: #000000; border: 1px solid #cccccc; padding: 5px; }
            QPushButton:hover { background-color: #e6e6e6; }
            QPushButton:pressed { background-color: #d9d9d9; }
            QGroupBox { border: 1px solid #cccccc; margin-top: 5px; }
            QGroupBox::title { color: #000000; }
            QComboBox { background-color: #ffffff; color: #000000; border: 1px solid #cccccc; padding: 5px; }
            QComboBox::drop-down { border: none; }
            QComboBox::down-arrow { image: url(:/icons/down_arrow_black.png); }
            QListWidget { background-color: #ffffff; color: #000000; border: 1px solid #cccccc; }
            QRadioButton { color: #000000; }
            QLabel { color: #000000; }
        )";
    }

    qApp->setStyleSheet(styleSheet);

    // 更新主题按钮文本
    QPushButton *themeButton = findChild<QPushButton*>("themeButton");
    if (themeButton) {
        themeButton->setText(isDark ? tr("日间模式") : tr("夜间模式"));
    }
}

void MainWindow::switchLanguage(const QString& locale)
{
    settings->setLanguage(locale);

    // 加载翻译文件
    static QTranslator translator;
    qApp->removeTranslator(&translator);

    if (translator.load(QString(":/translations/calculator_%1").arg(locale))) {
        qApp->installTranslator(&translator);
    }

    // 更新界面文本
    retranslateUI();

    // 更新语言按钮文本
    QPushButton *langButton = findChild<QPushButton*>("langButton");
    if (langButton) {
        langButton->setText(locale == "zh_CN" ? tr("English") : tr("中文"));
    }
}

void MainWindow::retranslateUI()
{
    // 更新窗口标题
    setWindowTitle(tr("多功能计算器"));

    // 更新工具栏按钮文本
    QAction *actionStandard = findChild<QAction*>("actionStandard");
    if (actionStandard) actionStandard->setText(tr("标准型"));

    QAction *actionScientific = findChild<QAction*>("actionScientific");
    if (actionScientific) actionScientific->setText(tr("科学型"));

    QAction *actionProgrammer = findChild<QAction*>("actionProgrammer");
    if (actionProgrammer) actionProgrammer->setText(tr("程序员"));

    QAction *actionDate = findChild<QAction*>("actionDate");
    if (actionDate) actionDate->setText(tr("日期计算"));

    QAction *actionConverter = findChild<QAction*>("actionConverter");
    if (actionConverter) actionConverter->setText(tr("单位转换"));

    // 更新历史记录面板
    QDockWidget *historyDock = findChild<QDockWidget*>();
    if (historyDock) historyDock->setWindowTitle(tr("历史记录"));

    QPushButton *clearHistoryBtn = findChild<QPushButton*>("clearHistoryBtn");
    if (clearHistoryBtn) clearHistoryBtn->setText(tr("清除历史"));

    // 更新状态栏
    QString currentMode = modeLabel->text().split(":").last().trimmed();
    modeLabel->setText(tr("当前模式: ") + currentMode);

    // 更新单位转换界面
    if (unitTypeCombo) {
        int currentIndex = unitTypeCombo->currentIndex();
        unitTypeCombo->clear();
        unitTypeCombo->addItems(unitConverter->getUnitTypes());
        unitTypeCombo->setCurrentIndex(currentIndex);
    }

    // 更新其他按钮文本
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for (QPushButton* btn : buttons) {
        QString text = btn->text();
        if (text == "MC") btn->setText(tr("MC"));
        else if (text == "MR") btn->setText(tr("MR"));
        else if (text == "M+") btn->setText(tr("M+"));
        else if (text == "M-") btn->setText(tr("M-"));
        else if (text == "MS") btn->setText(tr("MS"));
        else if (text == "CE") btn->setText(tr("CE"));
        else if (text == "C") btn->setText(tr("C"));
        else if (text == "<-") btn->setText(tr("←"));
        else if (text == "=") btn->setText(tr("="));
        else if (text == "±") btn->setText(tr("±"));
        else if (text == "1/x") btn->setText(tr("1/x"));
        else if (text == "%") btn->setText(tr("%"));
        else if (text == "√") btn->setText(tr("√"));
    }
}

void MainWindow::clearDisplay()
{
    calcCore->clear();
    updateDisplay();
}

void MainWindow::addToHistory(const QString &expression, const QString &result)
{
    QString historyItem = QString("%1 = %2").arg(expression, result);
    if (historyList) {
        historyList->addItem(historyItem);
        historyList->scrollToBottom();
    }
}

void MainWindow::clearHistory()
{
    if (historyList) {
        historyList->clear();
    }
}

void MainWindow::historyItemClicked(QListWidgetItem *item)
{
    if (!item) return;

    QString historyText = item->text();
    QStringList parts = historyText.split("=");
    if (parts.size() != 2) return;

    QString result = parts[1].trimmed();

    // 根据当前模式设置显示
    QLineEdit *display = nullptr;
    if (modeStack->currentIndex() == Scientific) {
        display = findChild<QLineEdit*>("scientificDisplay");
    } else {
        display = findChild<QLineEdit*>("displayEdit");
    }

    if (display) {
        display->setText(result);
        calcCore->setCurrentDisplay(result);  // 使用setCurrentDisplay而不是setLastResult
    }
}

void MainWindow::setupScientificUI(QWidget *scientificPage)
{
    QVBoxLayout *scientificLayout = new QVBoxLayout(scientificPage);

    // 添加显示屏
    QLineEdit *display = new QLineEdit;
    display->setObjectName("scientificDisplay");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(50);
    scientificLayout->addWidget(display);

    // 创建按钮网格
    QGridLayout *buttonGrid = new QGridLayout;

    // 第一行：三角函数和基本函数
    const char* row1[] = {"sin", "cos", "tan", "ln", "log"};
    for(int i = 0; i < 5; i++) {
        QPushButton *btn = new QPushButton(row1[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 0, i);
        connect(btn, &QPushButton::clicked, this, &MainWindow::scientificButtonClicked);
    }

    // 第二行：幂运算和常数
    const char* row2[] = {"x²", "x^y", "e^x", "π", "n!"};
    for(int i = 0; i < 5; i++) {
        QPushButton *btn = new QPushButton(row2[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 1, i);
        connect(btn, &QPushButton::clicked, this, &MainWindow::scientificButtonClicked);
    }

    // 第三行：内存操作
    const char* row3[] = {"MC", "MR", "M+", "M-", "MS"};
    for(int i = 0; i < 5; i++) {
        QPushButton *btn = new QPushButton(row3[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 2, i);
    }

    // 第四行：特殊功能
    const char* row4[] = {"←", "CE", "C", "±", "√"};
    for(int i = 0; i < 5; i++) {
        QPushButton *btn = new QPushButton(row4[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 3, i);
        if(row4[i] == QString("C")) {
            btn->setObjectName("scientificClearButton");
            connect(btn, &QPushButton::clicked, this, &MainWindow::clearDisplay);
        }
    }

    // 数字和基本运算符
    const char* buttons[] = {
        "7", "8", "9", "/", "(",
        "4", "5", "6", "*", ")",
        "1", "2", "3", "-", "=",
        "0", ".", "e", "+"
    };

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            if(i*5 + j < static_cast<int>(sizeof(buttons)/sizeof(buttons[0]))) {
                QPushButton *btn = new QPushButton(buttons[i*5 + j]);
                btn->setMinimumSize(50, 40);
                buttonGrid->addWidget(btn, i+4, j);
                QString btnText = buttons[i*5 + j];
                if(btnText.contains(QRegularExpression("[0-9]"))) {
                    connect(btn, &QPushButton::clicked, this, &MainWindow::digitClicked);
                } else if(btnText != "=") {
                    connect(btn, &QPushButton::clicked, this, &MainWindow::operatorClicked);
                } else {
                    btn->setObjectName("scientificEqualButton");
                    connect(btn, &QPushButton::clicked, this, &MainWindow::equalClicked);
                }
            }
        }
    }

    scientificLayout->addLayout(buttonGrid);
}

void MainWindow::scientificButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString function = button->text();
    double value = calcCore->getCurrentDisplay().toDouble();
    double result = 0;

    if (function == "sin") {
        result = calcCore->sin(value);
    } else if (function == "cos") {
        result = calcCore->cos(value);
    } else if (function == "tan") {
        result = calcCore->tan(value);
    } else if (function == "ln") {
        result = calcCore->ln(value);
    } else if (function == "log") {
        result = calcCore->log(value);
    } else if (function == "x²") {
        result = calcCore->power(value, 2);
    } else if (function == "e^x") {
        result = calcCore->exp(value);
    } else if (function == "n!") {
        result = calcCore->factorial(value);
    } else if (function == "π") {
        result = M_PI;
    } else if (function == "x^y") {
        calcCore->inputOperator("^");
        updateDisplay();
        return;
    }

    // 更新显示
    QLineEdit *display = findChild<QLineEdit*>("scientificDisplay");
    if (display) {
        display->setText(QString::number(result, 'g', 12));
        // 添加到历史记录
        if (function != "x^y") {
            addToHistory(QString("%1(%2)").arg(function).arg(value), QString::number(result));
        }
    }
}

void MainWindow::setupProgrammerUI(QWidget *programmerPage)
{
    QVBoxLayout *layout = new QVBoxLayout(programmerPage);

    // 添加显示屏
    QLineEdit *display = new QLineEdit;
    display->setObjectName("programmerDisplay");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(50);
    display->setText("0");
    layout->addWidget(display);

    // 添加进制选择按钮组
    QHBoxLayout *baseLayout = new QHBoxLayout;
    baseButtonGroup = new QButtonGroup(this);

    // 创建进制选择按钮
    QRadioButton *hexBtn = new QRadioButton("HEX");
    QRadioButton *decBtn = new QRadioButton("DEC");
    QRadioButton *octBtn = new QRadioButton("OCT");
    QRadioButton *binBtn = new QRadioButton("BIN");

    // 设置按钮的数据值
    baseButtonGroup->addButton(hexBtn, 16);
    baseButtonGroup->addButton(decBtn, 10);
    baseButtonGroup->addButton(octBtn, 8);
    baseButtonGroup->addButton(binBtn, 2);

    // 默认选择十六进制
    hexBtn->setChecked(true);
    currentBase = CalculatorCore::Hexadecimal;

    // 添加按钮到布局
    baseLayout->addWidget(hexBtn);
    baseLayout->addWidget(decBtn);
    baseLayout->addWidget(octBtn);
    baseLayout->addWidget(binBtn);
    layout->addLayout(baseLayout);

    // 创建按钮网格
    QGridLayout *buttonGrid = new QGridLayout;

    // 位运算按钮
    const char* bitOps[] = {"AND", "OR", "XOR", "NOT", "<<", ">>"};
    for(int i = 0; i < 6; i++) {
        QPushButton *btn = new QPushButton(bitOps[i]);
        btn->setMinimumSize(50, 40);
        buttonGrid->addWidget(btn, 0, i);
        connect(btn, &QPushButton::clicked, this, &MainWindow::programmerButtonClicked);
    }

    // 数字和基本运算符
    const char* buttons[] = {
        "7", "8", "9", "D", "E", "F",
        "4", "5", "6", "A", "B", "C",
        "1", "2", "3", "+", "-", "=",
        "0", ".", "←", "*", "/", "C"
    };

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 6; j++) {
            QPushButton *btn = new QPushButton(buttons[i*6 + j]);
            btn->setMinimumSize(50, 40);
            buttonGrid->addWidget(btn, i+1, j);
            connect(btn, &QPushButton::clicked, this, &MainWindow::programmerButtonClicked);
        }
    }

    layout->addLayout(buttonGrid);

    // 连接进制切换信号
    connect(baseButtonGroup, QOverload<int>::of(&QButtonGroup::idClicked),
            this, &MainWindow::baseChanged);

    // 初始化按钮状态
    baseChanged(16); // 默认为十六进制
}

void MainWindow::setupDateCalculatorUI(QWidget *datePage)
{
    QVBoxLayout *layout = new QVBoxLayout(datePage);

    // 添加日期选择器
    QGroupBox *dateGroup = new QGroupBox(tr("日期计算"));
    QGridLayout *dateLayout = new QGridLayout;

    dateLayout->addWidget(new QLabel(tr("起始日期:")), 0, 0);
    startDateEdit = new QDateEdit(QDate::currentDate());
    startDateEdit->setCalendarPopup(true);
    dateLayout->addWidget(startDateEdit, 0, 1);

    dateLayout->addWidget(new QLabel(tr("结束日期:")), 1, 0);
    endDateEdit = new QDateEdit(QDate::currentDate());
    endDateEdit->setCalendarPopup(true);
    dateLayout->addWidget(endDateEdit, 1, 1);

    QPushButton *calculateBtn = new QPushButton(tr("计算日期差"));
    dateLayout->addWidget(calculateBtn, 2, 0, 1, 2);

    dateGroup->setLayout(dateLayout);
    layout->addWidget(dateGroup);

    // 添加日期加减运算
    QGroupBox *addSubGroup = new QGroupBox(tr("日期加减"));
    QGridLayout *addSubLayout = new QGridLayout;

    QSpinBox *daysSpinBox = new QSpinBox;
    daysSpinBox->setRange(-999999, 999999);
    addSubLayout->addWidget(new QLabel(tr("天数:")), 0, 0);
    addSubLayout->addWidget(daysSpinBox, 0, 1);

    QPushButton *addBtn = new QPushButton(tr("添加天数"));
    QPushButton *subBtn = new QPushButton(tr("减少天数"));
    addSubLayout->addWidget(addBtn, 1, 0);
    addSubLayout->addWidget(subBtn, 1, 1);

    addSubGroup->setLayout(addSubLayout);
    layout->addWidget(addSubGroup);

    // 添加结果显示
    QLineEdit *resultDisplay = new QLineEdit;
    resultDisplay->setObjectName("dateResultDisplay");
    resultDisplay->setReadOnly(true);
    resultDisplay->setAlignment(Qt::AlignCenter);
    layout->addWidget(resultDisplay);

    // 连接信号
    connect(calculateBtn, &QPushButton::clicked, this, &MainWindow::dateCalculateClicked);
    connect(addBtn, &QPushButton::clicked, this, [=]() {
        QDate startDate = startDateEdit->date();
        int days = daysSpinBox->value();
        QDate result = calcCore->addDaysToDate(startDate, days);
        resultDisplay->setText(result.toString("yyyy-MM-dd"));
        // Add to history
        addToHistory(
            QString("%1 + %2 days = %3")
                .arg(startDate.toString("yyyy-MM-dd"))
                .arg(days)
                .arg(result.toString("yyyy-MM-dd")),
            result.toString("yyyy-MM-dd")
        );
    });
    connect(subBtn, &QPushButton::clicked, this, [=]() {
        QDate startDate = startDateEdit->date();
        int days = daysSpinBox->value();
        QDate result = calcCore->subtractDaysFromDate(startDate, days);
        resultDisplay->setText(result.toString("yyyy-MM-dd"));
        // Add to history
        addToHistory(
            QString("%1 - %2 days = %3")
                .arg(startDate.toString("yyyy-MM-dd"))
                .arg(days)
                .arg(result.toString("yyyy-MM-dd")),
            result.toString("yyyy-MM-dd")
        );
    });
}

void MainWindow::programmerButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString operation = button->text();
    QLineEdit *display = findChild<QLineEdit*>("programmerDisplay");
    if (!display) return;

    QString currentValue = display->text();

    // 处理数字输入
    if (operation.contains(QRegularExpression("[0-9A-F]"))) {
        if (display->text() == "0") {
            display->setText(operation);
        } else {
            display->setText(display->text() + operation);
        }
        return;  // 添加return确保不会继续执行
    }

    // 处理运算符
    if (operation == "+" || operation == "-" || operation == "*" || operation == "/") {
        firstOperand = currentValue;
        currentOperation = operation;
        display->setText("0");
        return;  // 添加return确保不会继续执行
    }

    // 处理等号
    if (operation == "=") {
        qDebug() << "Equal clicked"; // 添加调试输出
        qDebug() << "First operand:" << firstOperand; // 添加调试输出
        qDebug() << "Current operation:" << currentOperation; // 添加调试输出

        if (firstOperand.isEmpty() || currentOperation.isEmpty()) {
            qDebug() << "Missing operand or operation"; // 添加调试输出
            return;
        }

        bool ok1, ok2;
        int base = (currentBase == CalculatorCore::Hexadecimal) ? 16 :
                  (currentBase == CalculatorCore::Decimal) ? 10 :
                  (currentBase == CalculatorCore::Octal) ? 8 : 2;

        qlonglong val1 = firstOperand.toLongLong(&ok1, base);
        qlonglong val2 = currentValue.toLongLong(&ok2, base);

        qDebug() << "Val1:" << val1 << "Val2:" << val2; // 添加调试输出

        if (ok1 && ok2) {
            qlonglong result = 0;
            bool validOperation = true;

            if (currentOperation == "+") {
                result = val1 + val2;
            } else if (currentOperation == "-") {
                result = val1 - val2;
            } else if (currentOperation == "*") {
                result = val1 * val2;
            } else if (currentOperation == "/") {
                if (val2 != 0) {
                    result = val1 / val2;
                } else {
                    display->setText("Error");
                    validOperation = false;
                }
            } else if (currentOperation == "AND") {
                result = val1 & val2;
            } else if (currentOperation == "OR") {
                result = val1 | val2;
            } else if (currentOperation == "XOR") {
                result = val1 ^ val2;
            }

            if (validOperation) {
                QString resultStr = formatNumberForBase(result, base);
                display->setText(resultStr);

                // 添加到历史记录
                QString historyEntry = QString("%1 %2 %3 = %4")
                                     .arg(formatNumberForBase(val1, base))
                                     .arg(currentOperation)
                                     .arg(formatNumberForBase(val2, base))
                                     .arg(resultStr);
                addToHistory(historyEntry, resultStr);
            }
        }

        firstOperand.clear();
        currentOperation.clear();
        return;
    }

    // 处理位运算
    if (operation == "AND" || operation == "OR" || operation == "XOR") {
        firstOperand = currentValue;
        currentOperation = operation;
        display->setText("0");
        return;
    }

    // 处理清除
    if (operation == "C") {
        display->setText("0");
        firstOperand.clear();
        currentOperation.clear();
        return;
    }

    // 处理退格
    if (operation == "←") {
        QString text = display->text();
        if (!text.isEmpty() && text != "0") {
            text.chop(1);
            display->setText(text.isEmpty() ? "0" : text);
        }
        return;
    }
}

void MainWindow::baseChanged(int base)
{
    QLineEdit *display = findChild<QLineEdit*>("programmerDisplay");
    if (!display) return;

    QString currentText = display->text();
    bool ok;
    qlonglong value;

    // 从当前进制转换为十进制
    switch (currentBase) {
        case CalculatorCore::Hexadecimal:
            currentText.replace("0x", "", Qt::CaseInsensitive);
            value = currentText.toLongLong(&ok, 16);
            break;
        case CalculatorCore::Decimal:
            value = currentText.toLongLong(&ok, 10);
            break;
        case CalculatorCore::Octal:
            value = currentText.toLongLong(&ok, 8);
            break;
        case CalculatorCore::Binary:
            currentText.remove(' ');
            value = currentText.toLongLong(&ok, 2);
            break;
        default:
            ok = false;
    }

    if (!ok) {
        display->setText("0");
        return;
    }

    // 设置新的进制
    currentBase = static_cast<CalculatorCore::NumberBase>(base);

    // 使用格式化函数显示结果
    display->setText(formatNumberForBase(value, base));

    // 更新按钮状态
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for (QPushButton *btn : buttons) {
        QString text = btn->text();
        if (text.length() == 1 && text[0].isLetterOrNumber()) {
            bool isHexDigit = text[0].isLetter() && text[0].toUpper() <= 'F';
            bool isOctalDigit = text[0].isDigit() && text[0] < '8';
            bool isBinaryDigit = text[0] == '0' || text[0] == '1';

            btn->setEnabled(
                (base == 16) ||
                (base == 10 && !isHexDigit) ||
                (base == 8 && isOctalDigit) ||
                (base == 2 && isBinaryDigit)
            );
        }
    }
}

void MainWindow::dateCalculateClicked()
{
    QDate date1 = startDateEdit->date();
    QDate date2 = endDateEdit->date();
    QString result = calcCore->calculateDateDifference(date1, date2);

    QLineEdit *display = findChild<QLineEdit*>("dateResultDisplay");
    if (display) {
        display->setText(tr("相差 %1 天").arg(result));
        // Add to history
        addToHistory(
            QString("%1 to %2 = %3 days")
                .arg(date1.toString("yyyy-MM-dd"))
                .arg(date2.toString("yyyy-MM-dd"))
                .arg(result),
            result
        );
    }
}

void MainWindow::setupConverterUI(QWidget *converterPage)
{
    QVBoxLayout *layout = new QVBoxLayout(converterPage);

    // 单位类型选择
    QGroupBox *typeGroup = new QGroupBox(tr("单位类型"));
    QVBoxLayout *typeLayout = new QVBoxLayout;
    unitTypeCombo = new QComboBox;
    unitTypeCombo->addItems(unitConverter->getUnitTypes());
    typeLayout->addWidget(unitTypeCombo);
    typeGroup->setLayout(typeLayout);
    layout->addWidget(typeGroup);

    // 源单位输入
    QGroupBox *fromGroup = new QGroupBox(tr("转换自"));
    QVBoxLayout *fromLayout = new QVBoxLayout;
    fromUnitCombo = new QComboBox;
    fromValueEdit = new QLineEdit;
    fromValueEdit->setPlaceholderText(tr("输入值"));
    fromLayout->addWidget(fromUnitCombo);
    fromLayout->addWidget(fromValueEdit);
    fromGroup->setLayout(fromLayout);
    layout->addWidget(fromGroup);

    // 目标单位输入
    QGroupBox *toGroup = new QGroupBox(tr("转换到"));
    QVBoxLayout *toLayout = new QVBoxLayout;
    toUnitCombo = new QComboBox;
    resultValueEdit = new QLineEdit;
    resultValueEdit->setReadOnly(true);
    toLayout->addWidget(toUnitCombo);
    toLayout->addWidget(resultValueEdit);
    toGroup->setLayout(toLayout);
    layout->addWidget(toGroup);

    // 转换按钮
    QPushButton *convertBtn = new QPushButton(tr("转换"));
    layout->addWidget(convertBtn);

    // 添加弹簧
    layout->addStretch();

    // 连接信号
    connect(unitTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::unitTypeChanged);
    connect(convertBtn, &QPushButton::clicked,
            this, &MainWindow::convertUnit);
    connect(fromValueEdit, &QLineEdit::returnPressed,
            this, &MainWindow::convertUnit);

    // 初始化单位列表
    unitTypeChanged(0);
}

void MainWindow::unitTypeChanged(int index)
{
    UnitConverter::UnitType type = static_cast<UnitConverter::UnitType>(index);
    QStringList units = unitConverter->getUnits(type);

    fromUnitCombo->clear();
    toUnitCombo->clear();

    fromUnitCombo->addItems(units);
    toUnitCombo->addItems(units);

    if (units.size() > 1) {
        toUnitCombo->setCurrentIndex(1);
    }

    // 清除之前的转换结果
    fromValueEdit->clear();
    resultValueEdit->clear();
}

void MainWindow::convertUnit()
{
    bool ok;
    double value = fromValueEdit->text().toDouble(&ok);
    if (!ok) {
        resultValueEdit->setText(tr("无效输入"));
        return;
    }

    UnitConverter::UnitType type = static_cast<UnitConverter::UnitType>(unitTypeCombo->currentIndex());
    QString fromUnit = fromUnitCombo->currentText();
    QString toUnit = toUnitCombo->currentText();

    double result = unitConverter->convert(value, fromUnit, toUnit, type);
    resultValueEdit->setText(QString::number(result, 'g', 6));

    // 添加到历史记录
    addToHistory(
        QString("%1 %2 = %3 %4")
            .arg(value)
            .arg(fromUnit)
            .arg(result)
            .arg(toUnit),
        QString::number(result)
    );
}

void MainWindow::setupHistoryPanel()
{
    // 创建历史记录面板
    QDockWidget *historyDock = new QDockWidget(tr("历史记录"), this);
    historyDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    historyDock->setFeatures(QDockWidget::DockWidgetFloatable |
                            QDockWidget::DockWidgetMovable);

    QWidget *historyWidget = new QWidget(historyDock);
    QVBoxLayout *historyLayout = new QVBoxLayout(historyWidget);

    historyList = new QListWidget(historyWidget);
    historyLayout->addWidget(historyList);

    clearHistoryBtn = new QPushButton(tr("清除历史"), historyWidget);
    clearHistoryBtn->setObjectName("clearHistoryBtn");
    historyLayout->addWidget(clearHistoryBtn);

    historyDock->setWidget(historyWidget);
    addDockWidget(Qt::RightDockWidgetArea, historyDock);

    // 连接信号和槽
    connect(clearHistoryBtn, &QPushButton::clicked, this, &MainWindow::clearHistory);
    connect(historyList, &QListWidget::itemClicked, this, &MainWindow::historyItemClicked);
}

// 添加一个辅助函数来格式化数字显示
QString MainWindow::formatNumberForBase(qlonglong number, int base)
{
    QString result = QString::number(number, base).toUpper();

    // 为二进制添加分隔符
    if (base == 2 && result.length() > 4) {
        QString formatted;
        int count = 0;
        for (int i = result.length() - 1; i >= 0; i--) {
            if (count > 0 && count % 4 == 0) {
                formatted.prepend(' ');
            }
            formatted.prepend(result[i]);
            count++;
        }
        return formatted;
    }

    // 为十六进制添加0x前缀
    if (base == 16) {
        return "0x" + result;
    }

    return result;
}
