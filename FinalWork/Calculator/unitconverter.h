#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QDateTime>

class UnitConverter : public QObject
{
    Q_OBJECT
public:
    enum UnitType {
        Length,
        Weight,
        Volume,
        Temperature,
        Area,
        Currency
    };

    explicit UnitConverter(QObject *parent = nullptr);

    QStringList getUnitTypes() const;
    QStringList getUnits(UnitType type) const;
    double convert(double value, const QString &fromUnit, const QString &toUnit, UnitType type);

    void updateExchangeRate(const QString &currency, double rate);
    QMap<QString, double> getExchangeRates() const;

private:
    struct ConversionRate {
        QString unit;
        double rate;
        QString symbol;
    };

    QMap<UnitType, QList<ConversionRate>> conversionRates;
    QMap<QString, double> exchangeRates;
    QDateTime lastUpdateTime;

    void initializeConversionRates();
    void initializeExchangeRates();
    bool updateExchangeRatesFromAPI();
};

#endif // UNITCONVERTER_H