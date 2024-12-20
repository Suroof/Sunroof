#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent)
    : QObject(parent)
    , settings("Calculator", "Settings")
{
}

void SettingsManager::saveSettings()
{
    // 保存设置逻辑将在这里实现
}

void SettingsManager::loadSettings()
{
    // 加载设置逻辑将在这里实现
}

void SettingsManager::setTheme(const QString &theme)
{
    settings.setValue("theme", theme);
}

QString SettingsManager::getTheme() const
{
    return settings.value("theme", "light").toString();
}

void SettingsManager::setLanguage(const QString &language)
{
    settings.setValue("language", language);
}

QString SettingsManager::getLanguage() const
{
    return settings.value("language", "en").toString();
}