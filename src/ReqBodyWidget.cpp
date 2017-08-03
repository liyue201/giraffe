#include "ReqBodyWidget.h"

ReqBodyWidget::ReqBodyWidget(QWidget *parent)
: QWidget(parent)
{
    mpBodyEdit = new QTextEdit(this);
    QVBoxLayout* mainLy = new QVBoxLayout(this);
    mainLy->addWidget(mpBodyEdit);
}

ReqBodyWidget::~ReqBodyWidget()
{

}

QString ReqBodyWidget::GetText()
{
    return mpBodyEdit->toPlainText();
}






