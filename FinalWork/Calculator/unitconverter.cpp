#include "unitconverter.h"

UnitConverter::UnitConverter(QObject *parent)
    : QObject(parent)
{
    initializeConversionRates();
}

void UnitConverter::initializeConversionRates()
{
    // 长度单位（基准：米）
    QList<ConversionRate> lengthRates = {
        {"米", 1.0, "m"},
        {"厘米", 100.0, "cm"},
        {"千米", 0.001, "km"},
        {"英寸", 39.3701, "in"},
        {"英尺", 3.28084, "ft"},
        {"码", 1.09361, "yd"}
    };
    conversionRates[Length] = lengthRates;

    // 重量单位（基准：千克）
    QList<ConversionRate> weightRates = {
        {"千克", 1.0, "kg"},
        {"克", 1000.0, "g"},
        {"磅", 2.20462, "lb"},
        {"盎司", 35.274, "oz"},
        {"吨", 0.001, "t"}
    };
    conversionRates[Weight] = weightRates;

    // 体积单位（基准：立方米）
    QList<ConversionRate> volumeRates = {
        {"立方米", 1.0, "m³"},
        {"立方厘米", 1000000.0, "cm³"},
        {"立方毫米", 1000000000.0, "mm³"},
        {"升", 1000.0, "L"},
        {"毫升", 1000000.0, "mL"},
        {"加仑(美)", 264.172, "gal"},
        {"品脱(美)", 2113.38, "pt"},
        {"夸脱(美)", 1056.69, "qt"},
        {"立方英尺", 35.3147, "ft³"},
        {"立方英寸", 61023.7, "in³"}
    };
    conversionRates[Volume] = volumeRates;

    // 添加面积单位（基准：平方米）
    QList<ConversionRate> areaRates = {
        {"平方米", 1.0, "m²"},
        {"平方厘米", 10000.0, "cm²"},
        {"平方毫米", 1000000.0, "mm²"},
        {"平方千米", 0.000001, "km²"},
        {"公顷", 0.0001, "ha"},
        {"亩", 0.0015, "亩"},
        {"平方英尺", 10.7639, "ft²"},
        {"平方英寸", 1550.0, "in²"},
        {"平方码", 1.19599, "yd²"},
        {"英亩", 0.000247105, "acre"}
    };
    conversionRates[Area] = areaRates;

    // 温度单位需要特殊处理
    QList<ConversionRate> tempRates = {
        {"摄氏度", 1.0, "°C"},
        {"华氏度", 1.0, "°F"},
        {"开尔文", 1.0, "K"}
    };
    conversionRates[Temperature] = tempRates;

    // 货币单位（基准：美元）
    QList<ConversionRate> currencyRates = {
        {"美元", 1.0, "$"},
        {"人民币", 7.2, "¥"},
        {"欧元", 0.92, "€"},
        {"英镑", 0.79, "£"},
        {"日元", 148.0, "¥"},
        {"韩元", 1330.0, "₩"},
        {"港币", 7.82, "HK$"},
        {"加拿大元", 1.35, "C$"}
    };
    conversionRates[Currency] = currencyRates;

    // 初始化汇率
    initializeExchangeRates();
}

void UnitConverter::initializeExchangeRates()
{
    // 初始化默认汇率（相对于美元）
    for (const auto &rate : conversionRates[Currency]) {
        exchangeRates[rate.unit] = rate.rate;
    }

    // 尝试从API更新汇率
    updateExchangeRatesFromAPI();
}

bool UnitConverter::updateExchangeRatesFromAPI()
{
    // TODO: 实现从外部API获取实时汇率
    // 这里可以使用 QNetworkAccessManager 从免费的汇率API获取数据
    // 例如：https://exchangeratesapi.io/ 或 https://www.exchangerate-api.com/

    return false;  // 暂时返回false
}

void UnitConverter::updateExchangeRate(const QString &currency, double rate)
{
    exchangeRates[currency] = rate;

    // 更新转换率列表
    for (auto &rateList : conversionRates) {
        for (auto &r : rateList) {
            if (r.unit == currency) {
                r.rate = rate;
                break;
            }
        }
    }
}

QMap<QString, double> UnitConverter::getExchangeRates() const
{
    return exchangeRates;
}

QStringList UnitConverter::getUnitTypes() const
{
    return {
        tr("长度"),
        tr("重量"),
        tr("体积"),
        tr("温度"),
        tr("面积"),
        tr("货币")
    };
}

QStringList UnitConverter::getUnits(UnitType type) const
{
    QStringList units;
    if (conversionRates.contains(type)) {
        for (const auto &rate : conversionRates[type]) {
            units << rate.unit;
        }
    }
    return units;
}

double UnitConverter::convert(double value, const QString &fromUnit, const QString &toUnit, UnitType type)
{
    if (type == Currency) {
        // 使用最新的汇率进行转换
        if (!exchangeRates.contains(fromUnit) || !exchangeRates.contains(toUnit)) {
            return value;
        }

        // 先转换为美元，再转换为目标货币
        double usdAmount = value / exchangeRates[fromUnit];
        return usdAmount * exchangeRates[toUnit];
    }

    if (type == Temperature) {
        // 温度转换需要特殊处理
        if (fromUnit == "摄氏度") {
            if (toUnit == "华氏度") {
                return value * 9/5 + 32;
            } else if (toUnit == "开尔文") {
                return value + 273.15;
            }
        } else if (fromUnit == "华氏度") {
            if (toUnit == "摄氏度") {
                return (value - 32) * 5/9;
            } else if (toUnit == "开尔文") {
                return (value - 32) * 5/9 + 273.15;
            }
        } else if (fromUnit == "开尔文") {
            if (toUnit == "摄氏度") {
                return value - 273.15;
            } else if (toUnit == "华氏度") {
                return (value - 273.15) * 9/5 + 32;
            }
        }
        return value;
    }

    // 其他单位转换
    if (!conversionRates.contains(type)) return value;

    const auto &rates = conversionRates[type];
    double fromRate = 1.0, toRate = 1.0;

    for (const auto &rate : rates) {
        if (rate.unit == fromUnit) fromRate = rate.rate;
        if (rate.unit == toUnit) toRate = rate.rate;
    }

    return value * toRate / fromRate;
}