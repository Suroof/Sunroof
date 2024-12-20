#ifndef CALCULATORCORE_H
#define CALCULATORCORE_H

#include <QString>
#include <QDate>
#include <cmath>

class CalculatorCore
{
public:
    enum NumberBase {
        Binary = 2,
        Octal = 8,
        Decimal = 10,
        Hexadecimal = 16
    };

    CalculatorCore();

    void inputDigit(const QString &digit);
    void inputOperator(const QString &op);
    void calculate();
    void clear();

    QString getCurrentDisplay() const;
    void setCurrentDisplay(const QString &value);
    QString getLastExpression() const;

    // 科学计算器功能
    double sin(double value);
    double cos(double value);
    double tan(double value);
    double ln(double value);
    double log(double value);
    double power(double base, double exponent);
    double exp(double value);
    double factorial(double value);

    // 日期计算功能
    QString calculateDateDifference(const QDate &date1, const QDate &date2);
    QDate addDaysToDate(const QDate &date, int days);
    QDate subtractDaysFromDate(const QDate &date, int days);

    // 程序员计算器功能
    void setNumberBase(NumberBase base);
    NumberBase getNumberBase() const;

private:
    QString currentDisplay;
    QString lastExpression;
    QString firstOperand;
    QString currentOperator;
    bool newNumber;
    NumberBase numberBase;

    void updateLastExpression();
};

#endif // CALCULATORCORE_H