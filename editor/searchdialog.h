#if !defined(SEARCHDIALOG_H)
#define SEARCHDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QMessageBox>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog {
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr, QPlainTextEdit *textEdit = nullptr);
    ~SearchDialog();


private slots:
    void on_btFindNext_clicked();
    void on_btCancel_clicked() { reject(); }  // 添加取消按钮实现

private:
    Ui::SearchDialog *ui;
    QPlainTextEdit *pTextEdit;  // 添加文本编辑器指针
};

#endif // SEARCHDIALOG_H
