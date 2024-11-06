#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QMessageBox>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();
    void setTextEdit(QPlainTextEdit *textEdit) { pTextEdit = textEdit; }

private slots:
    void on_btFind_clicked();
    void on_btReplace_clicked();
    void on_btReplaceAll_clicked();
    void on_btCancel_clicked() { reject(); }

private:
    Ui::ReplaceDialog *ui;
    QPlainTextEdit *pTextEdit;
    bool findText(bool showMessage = true);
};

#endif // REPLACEDIALOG_H
