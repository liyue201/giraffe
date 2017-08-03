#include "RespHeaderWidget.h"

RespHeaderWidget::RespHeaderWidget(QWidget *parent)
: QWidget(parent)
{
    mpHeader = new QTextEdit(this);
    QVBoxLayout* mainLy = new QVBoxLayout(this);
    mainLy->addWidget(mpHeader);
}

RespHeaderWidget::~RespHeaderWidget()
{

}

void RespHeaderWidget::SetText(const QString& text)
{
    mpHeader->setText(text);
}







