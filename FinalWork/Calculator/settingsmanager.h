#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>

class SettingsManager : public QObject
{
    Q_OBJECT
public:
    explicit SettingsManager(QObject *parent = nullptr);

    void saveSettings();
    void loadSettings();

    void setTheme(const QString &theme);
    QString getTheme() const;

    void setLanguage(const QString &language);
    QString getLanguage() const;

    void setFontSize(int size);
    void setCustomColors(const QMap<QString, QColor> &colors);
    void setCustomLayout(const QByteArray &layout);

    int getFontSize() const;
    QMap<QString, QColor> getCustomColors() const;
    QByteArray getCustomLayout() const;

private:
    QSettings settings;
};

#endif // SETTINGSMANAGER_H