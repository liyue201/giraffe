#ifndef __RESPHEADERWIDGET_H_
#define __RESPHEADERWIDGET_H_

#include "global.h"

class RespHeaderWidget : public QWidget
{
    Q_OBJECT
public:
    RespHeaderWidget(QWidget *parent = 0);
    ~RespHeaderWidget();
  
    void SetText(const QString& text);
  
private:
    QTextEdit*  mpHeader;
};

#endif