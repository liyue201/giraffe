#include "RespBodyWidget.h"

RespBodyWidget::RespBodyWidget(QWidget *parent)
: QWidget(parent)
{
    mpBodyEdit = new QTextEdit(this);
    QVBoxLayout* mainLy = new QVBoxLayout(this);
    mainLy->addWidget(mpBodyEdit);
}

RespBodyWidget::~RespBodyWidget()
{

}

void RespBodyWidget::SetText(const QString& text)
{
    mpBodyEdit->setText(text);
}





