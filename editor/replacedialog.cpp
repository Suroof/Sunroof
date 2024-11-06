#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog),
    pTextEdit(nullptr)
{
    ui->setupUi(this);
    setWindowTitle(tr("替换"));
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

bool ReplaceDialog::findText(bool showMessage)
{
    if (!pTextEdit) return false;

    QString target = ui->findText->text();

    if (target.isEmpty()) {
        if (showMessage) {
            QMessageBox::warning(this, tr("替换"), tr("请输入要查找的内容！"));
        }
        return false;
    }

    QTextDocument::FindFlags flags;
    if (ui->checkCase->isChecked())
        flags |= QTextDocument::FindCaseSensitively;
    if (ui->rbUp->isChecked())
        flags |= QTextDocument::FindBackward;

    bool found = pTextEdit->find(target, flags);

    if (!found && showMessage) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("替换"),
                                      tr("已到达文档末尾，是否从头开始查找？"),
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            QTextCursor cursor = pTextEdit->textCursor();
            cursor.movePosition(flags & QTextDocument::FindBackward ?
                                    QTextCursor::End : QTextCursor::Start);
            pTextEdit->setTextCursor(cursor);

            found = pTextEdit->find(target, flags);

            if (!found) {
                QMessageBox::information(this, tr("替换"),
                                         tr("找不到\"%1\"").arg(target));
            }
        }
    }
    return found;
}

void ReplaceDialog::on_btFind_clicked()
{
    findText(true);
}

void ReplaceDialog::on_btReplace_clicked()
{
    if (!pTextEdit) return;

    QString searchText = ui->findText->text();
    QString replaceText = ui->replaceText->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, tr("替换"), tr("请输入要查找的内容！"));
        return;
    }

    QTextCursor cursor = pTextEdit->textCursor();
    if (cursor.hasSelection() &&
        cursor.selectedText() == (ui->checkCase->isChecked() ? searchText : searchText.toLower())) {
        cursor.insertText(replaceText);
        findText(true);  // 替换后继续查找下一个
    } else {
        findText(true);  // 如果没有选中文本，直接查找下一个
    }
}

void ReplaceDialog::on_btReplaceAll_clicked()
{
    if (!pTextEdit) return;

    QString searchText = ui->findText->text();
    QString replaceText = ui->replaceText->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, tr("替换"), tr("请输入要查找的内容！"));
        return;
    }

    QTextCursor originalCursor = pTextEdit->textCursor();
    pTextEdit->moveCursor(QTextCursor::Start);

    int count = 0;
    while (findText(false)) {
        QTextCursor cursor = pTextEdit->textCursor();
        cursor.insertText(replaceText);
        count++;
    }

    QMessageBox::information(this, tr("替换"),
                             tr("完成替换，共替换了 %1 处").arg(count));

    pTextEdit->setTextCursor(originalCursor);
}
