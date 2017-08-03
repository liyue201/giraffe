#ifndef __MAINWINDOW_H_
#define __MAINWINDOW_H_

#include "global.h"

class KMainWindow : public QDialog
{
    Q_OBJECT
public:
    KMainWindow(QWidget *parent = 0);
    ~KMainWindow();
  
private:
    QTabWidget*  mpTab;
};

#endif