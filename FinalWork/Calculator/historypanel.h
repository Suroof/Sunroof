#ifndef HISTORYPANEL_H
#define HISTORYPANEL_H

#include <QWidget>
#include <QListWidget>

class HistoryPanel : public QWidget
{
    Q_OBJECT
public:
    explicit HistoryPanel(QWidget *parent = nullptr);

    void addHistoryItem(const QString &expression, const QString &result);
    void clearHistory();

private:
    QListWidget *historyList;
};

#endif // HISTORYPANEL_H