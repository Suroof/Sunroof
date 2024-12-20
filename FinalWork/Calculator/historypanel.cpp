#include "historypanel.h"
#include <QVBoxLayout>
#include <QPushButton>

HistoryPanel::HistoryPanel(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    historyList = new QListWidget(this);
    layout->addWidget(historyList);

    QPushButton *clearButton = new QPushButton(tr("Clear History"), this);
    layout->addWidget(clearButton);

    connect(clearButton, &QPushButton::clicked, this, &HistoryPanel::clearHistory);
}

void HistoryPanel::addHistoryItem(const QString &expression, const QString &result)
{
    QString historyEntry = QString("%1 = %2").arg(expression, result);
    historyList->addItem(historyEntry);
}

void HistoryPanel::clearHistory()
{
    historyList->clear();
}