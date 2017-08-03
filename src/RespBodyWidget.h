#ifndef __RESPBODYWIDEGT_H_
#define __RESPBODYWIDEGT_H_

#include "global.h"

class RespBodyWidget : public QWidget
{
    Q_OBJECT
public:
    RespBodyWidget(QWidget *parent = 0);
    ~RespBodyWidget();
    
    void SetText(const QString& text);

private:
    QTextEdit*       mpBodyEdit;
};

#endif