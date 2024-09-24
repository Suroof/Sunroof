#include "aboutdialog.h"
#include <QVBoxLayout>
#include <QLabel>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent) {

    // 创建垂直布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 创建标签
    QLabel *labelName = new QLabel("石润峰", this);
    QLabel *labelID = new QLabel("2022414040131", this);
    // 设置标签的样式
    labelName->setStyleSheet("font-size: 16px; color: black;");
    labelID->setStyleSheet("font-size: 16px; color: black;");

    // 设置标签对齐方式为居中
    labelName->setAlignment(Qt::AlignCenter);
    labelID->setAlignment(Qt::AlignCenter);

    // 将标签添加到布局中
    layout->addWidget(labelName);
    layout->addWidget(labelID);

    // 设置对话框的大小
    setFixedSize(400, 200); // 设置固定大小为400x200


    // 设置对话框的布局
    setLayout(layout);
    // 设置对话框的样式


}

AboutDialog::~AboutDialog() {
    // 不需要手动删除布局中的控件，QDialog会自动处理
}
