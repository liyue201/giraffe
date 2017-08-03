#ifndef __REQHEADERWIDGET_H_
#define __REQHEADERWIDGET_H_

#include "global.h"

class HeaderItem : public QWidget
{
    Q_OBJECT
public:
    HeaderItem(QWidget *parent = 0);
    ~HeaderItem();

    QString GetKey();
    QString GetValue();

private slots:
    void OnDelete();

signals:
    void Delete(QWidget*);

private:
    QLineEdit*   mpKeyEdit;
    QLineEdit*   mpValEdit;
    QPushButton* mpDelBtn;
};

class ReqHeaderWidget : public QWidget
{
    Q_OBJECT
public:
    ReqHeaderWidget(QWidget *parent = 0);
    ~ReqHeaderWidget();

    QList<QNetworkReply::RawHeaderPair> GetHeaders();

private slots:
    void OnAdd();
    void OnDelete(QWidget*);

private:
    QVBoxLayout* mpItemLayout;
    QPushButton* mpAddBtn;
};

#endif