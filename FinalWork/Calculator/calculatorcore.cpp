#include "calculatorcore.h"
#include <cmath>

CalculatorCore::CalculatorCore()
    : currentDisplay("0")
    , newNumber(true)
    , numberBase(Decimal)
{
}

void CalculatorCore::inputDigit(const QString &digit)
{
    if (newNumber) {
        currentDisplay = digit;
        newNumber = false;
    } else {
        currentDisplay += digit;
    }
}

void CalculatorCore::inputOperator(const QString &op)
{
    if (!currentDisplay.isEmpty()) {
        if (!firstOperand.isEmpty()) {
            calculate();
        }
        firstOperand = currentDisplay;
        currentOperator = op;
        newNumber = true;
        updateLastExpression();
    }
}

void CalculatorCore::calculate()
{
    if (!firstOperand.isEmpty() && !currentDisplay.isEmpty() && !currentOperator.isEmpty()) {
        bool ok1, ok2;
        double num1 = firstOperand.toDouble(&ok1);
        double num2 = currentDisplay.toDouble(&ok2);

        if (ok1 && ok2) {
            double result = 0;
            if (currentOperator == "+") result = num1 + num2;
            else if (currentOperator == "-") result = num1 - num2;
            else if (currentOperator == "*") result = num1 * num2;
            else if (currentOperator == "/") result = num2 != 0 ? num1 / num2 : 0;
            else if (currentOperator == "^") result = std::pow(num1, num2);

            updateLastExpression();
            currentDisplay = QString::number(result, 'g', 12);
            firstOperand.clear();
            currentOperator.clear();
            newNumber = true;
        }
    }
}

void CalculatorCore::clear()
{
    currentDisplay = "0";
    firstOperand.clear();
    currentOperator.clear();
    lastExpression.clear();
    newNumber = true;
}

QString CalculatorCore::getCurrentDisplay() const
{
    return currentDisplay;
}

void CalculatorCore::setCurrentDisplay(const QString &value)
{
    currentDisplay = value;
    newNumber = true;
}

QString CalculatorCore::getLastExpression() const
{
    return lastExpression;
}

void CalculatorCore::updateLastExpression()
{
    if (!firstOperand.isEmpty() && !currentOperator.isEmpty() && !currentDisplay.isEmpty()) {
        lastExpression = QString("%1 %2 %3").arg(firstOperand, currentOperator, currentDisplay);
    }
}

// 科学计算器功能
double CalculatorCore::sin(double value)
{
    return std::sin(value);
}

double CalculatorCore::cos(double value)
{
    return std::cos(value);
}

double CalculatorCore::tan(double value)
{
    return std::tan(value);
}

double CalculatorCore::ln(double value)
{
    return std::log(value);
}

double CalculatorCore::log(double value)
{
    return std::log10(value);
}

double CalculatorCore::power(double base, double exponent)
{
    return std::pow(base, exponent);
}

double CalculatorCore::exp(double value)
{
    return std::exp(value);
}

double CalculatorCore::factorial(double value)
{
    if (value < 0) return 0;
    if (value == 0 || value == 1) return 1;
    return value * factorial(value - 1);
}

// 日期计算功能
QString CalculatorCore::calculateDateDifference(const QDate &date1, const QDate &date2)
{
    return QString::number(date1.daysTo(date2));
}

QDate CalculatorCore::addDaysToDate(const QDate &date, int days)
{
    return date.addDays(days);
}

QDate CalculatorCore::subtractDaysFromDate(const QDate &date, int days)
{
    return date.addDays(-days);
}

// 程序员计算器功能
void CalculatorCore::setNumberBase(NumberBase base)
{
    numberBase = base;
    bool ok;
    qlonglong value;

    // 从当前进制转换为十进制
    switch (numberBase) {
        case Hexadecimal:
            value = currentDisplay.toLongLong(&ok, 16);
            break;
        case Decimal:
            value = currentDisplay.toLongLong(&ok, 10);
            break;
        case Octal:
            value = currentDisplay.toLongLong(&ok, 8);
            break;
        case Binary:
            value = currentDisplay.toLongLong(&ok, 2);
            break;
    }

    if (!ok) {
        currentDisplay = "0";
        return;
    }

    // 转换为新进制
    switch (base) {
        case Hexadecimal:
            currentDisplay = QString::number(value, 16).toUpper();
            break;
        case Decimal:
            currentDisplay = QString::number(value, 10);
            break;
        case Octal:
            currentDisplay = QString::number(value, 8);
            break;
        case Binary:
            currentDisplay = QString::number(value, 2);
            break;
    }
}

CalculatorCore::NumberBase CalculatorCore::getNumberBase() const
{
    return numberBase;
}