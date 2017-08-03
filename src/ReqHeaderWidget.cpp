#include "ReqHeaderWidget.h"

HeaderItem::HeaderItem(QWidget *parent)
: QWidget(parent)
{
    mpKeyEdit = new QLineEdit(this);
    mpValEdit = new QLineEdit(this);
    mpKeyEdit->setPlaceholderText("Key");
    mpValEdit->setPlaceholderText("Value");

    mpDelBtn = new QPushButton(tr("Delete"), this);

    QHBoxLayout* mainLy = new QHBoxLayout(this);
    mainLy->addWidget(mpKeyEdit, 10);
    mainLy->addWidget(mpValEdit, 20);
    mainLy->addWidget(mpDelBtn, 1);

    connect(mpDelBtn, SIGNAL(clicked()), this, SLOT(OnDelete()));
}

HeaderItem::~HeaderItem()
{

}

void HeaderItem::OnDelete()
{
    emit Delete(this);
}

QString HeaderItem::GetKey()
{
    return mpKeyEdit->text();
}

QString HeaderItem::GetValue()
{
    return mpValEdit->text();
}

//////////////////////////////////////////////////////////////////////////
ReqHeaderWidget::ReqHeaderWidget(QWidget *parent)
: QWidget(parent)
{
    mpItemLayout = new QVBoxLayout();
    mpAddBtn = new QPushButton(tr("Add"), this);
    QVBoxLayout* mainLy = new QVBoxLayout(this);
    QHBoxLayout* hLy = new QHBoxLayout;
    hLy->addWidget(mpAddBtn);
    hLy->addStretch();
    mainLy->addLayout(mpItemLayout);
    mainLy->addLayout(hLy);
    mainLy->addStretch();

    connect(mpAddBtn, SIGNAL(clicked()), this, SLOT(OnAdd()));
}

ReqHeaderWidget::~ReqHeaderWidget()
{

}

void ReqHeaderWidget::OnAdd()
{
    HeaderItem* item = new HeaderItem(this);
    mpItemLayout->addWidget(item);
    connect(item, SIGNAL(Delete(QWidget*)), this, SLOT(OnDelete(QWidget*)));
}

void ReqHeaderWidget::OnDelete(QWidget* w)
{
    mpItemLayout->removeWidget(w);
    delete w;
}

QList<QNetworkReply::RawHeaderPair> ReqHeaderWidget::GetHeaders()
{
    QList<QNetworkReply::RawHeaderPair> headers;
    for (int i = 0; i < mpItemLayout->count(); i++)
    {
        HeaderItem* item = static_cast<HeaderItem*>(mpItemLayout->itemAt(i)->widget());
        QString key = item->GetKey();
        QString val = item->GetValue();
        if (!key.isEmpty() && !val.isEmpty())
        {
            QNetworkReply::RawHeaderPair pair;
            pair.first = key.toUtf8();
            pair.second = val.toUtf8();
            headers.append(pair);
        }
    }
    return headers;
}










