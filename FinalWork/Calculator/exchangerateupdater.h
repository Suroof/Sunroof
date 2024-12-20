#ifndef EXCHANGERATEUPDATER_H
#define EXCHANGERATEUPDATER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

class ExchangeRateUpdater : public QObject
{
    Q_OBJECT
public:
    explicit ExchangeRateUpdater(QObject *parent = nullptr);

    void startAutoUpdate(int intervalMinutes = 60);
    void stopAutoUpdate();
    void updateNow();

signals:
    void updateFinished(const QMap<QString, double> &rates);
    void updateError(const QString &error);

private slots:
    void handleNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    QTimer *updateTimer;
    QString apiKey;  // 你需要从汇率API提供商获取一个API密钥
};

#endif // EXCHANGERATEUPDATER_H