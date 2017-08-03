#ifndef __REQBODYWIDGET_H_
#define __REQBODYWIDGET_H_

#include "global.h"

class ReqBodyWidget : public QWidget
{
    Q_OBJECT
public:
    ReqBodyWidget(QWidget *parent = 0);
    ~ReqBodyWidget();

    QString GetText();
  
private:
    QTextEdit*       mpBodyEdit;
};

#endif