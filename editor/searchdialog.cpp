#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent, QPlainTextEdit *textEdit)
    : QDialog(parent), ui(new Ui::SearchDialog) {
    ui->setupUi(this);
    pTextEdit = textEdit;
}

SearchDialog::~SearchDialog() {
    delete ui;
}

void SearchDialog::on_btFindNext_clicked()
{
    QString target = ui->searchText->text();

    // 检查搜索文本是否为空
    if (target.isEmpty()) {
        QMessageBox::warning(this, tr("查找"), tr("请输入要查找的内容！"));
        return;
    }

    // 设置查找选项
    QTextDocument::FindFlags flags;
    if (ui->checkBox->isChecked())
        flags |= QTextDocument::FindCaseSensitively;
    if (ui->rbUp->isChecked())
        flags |= QTextDocument::FindBackward;

    // 执行查找
    bool found = pTextEdit->find(target, flags);

    // 如果没找到，显示消息框
    if (!found) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("查找"),
                                      tr("已到达文档末尾，是否从头开始查找？"),
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // 将光标移到文档开始或结束位置
            QTextCursor cursor = pTextEdit->textCursor();
            cursor.movePosition(flags & QTextDocument::FindBackward ?
                                    QTextCursor::End : QTextCursor::Start);
            pTextEdit->setTextCursor(cursor);

            // 再次查找
            found = pTextEdit->find(target, flags);

            if (!found) {
                // 修正这一行
                QMessageBox::information(this, tr("查找"),
                                         tr("找不到\"%1\"").arg(target));
            }
        }
    }
}
