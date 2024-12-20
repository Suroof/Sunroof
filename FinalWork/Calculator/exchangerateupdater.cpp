#include "exchangerateupdater.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ExchangeRateUpdater::ExchangeRateUpdater(QObject *parent)
    : QObject(parent)
    , networkManager(new QNetworkAccessManager(this))
    , updateTimer(new QTimer(this))
{
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &ExchangeRateUpdater::handleNetworkReply);
    connect(updateTimer, &QTimer::timeout,
            this, &ExchangeRateUpdater::updateNow);
}

void ExchangeRateUpdater::startAutoUpdate(int intervalMinutes)
{
    updateTimer->start(intervalMinutes * 60 * 1000);
    updateNow();
}

void ExchangeRateUpdater::stopAutoUpdate()
{
    updateTimer->stop();
}

void ExchangeRateUpdater::updateNow()
{
    // 使用 exchangerate-api.com 的API
    QString url = QString("https://v6.exchangerate-api.com/v6/%1/latest/USD")
                     .arg(apiKey);

    networkManager->get(QNetworkRequest(QUrl(url)));
}

void ExchangeRateUpdater::handleNetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);

        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            QJsonObject rates = obj["conversion_rates"].toObject();

            QMap<QString, double> exchangeRates;
            for (auto it = rates.begin(); it != rates.end(); ++it) {
                exchangeRates[it.key()] = it.value().toDouble();
            }

            emit updateFinished(exchangeRates);
        }
    } else {
        emit updateError(reply->errorString());
    }

    reply->deleteLater();
}