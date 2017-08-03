#ifndef __MAINWINDOW_H_
#define __MAINWINDOW_H_

#include "global.h"

class ReqBodyWidget;
class ReqCookieWidget;
class ReqHeaderWidget;
class RespBodyWidget;
class RespCookieWidget;
class RespHeaderWidget;

class MainWindow : public QDialog
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init();

private slots:
    void OnSumit();
    void OnNetFinished();
    void OnNetError(QNetworkReply::NetworkError);

private:
 

private:
    QComboBox*          mpMethodBox;
    QTextEdit*          mpUrlEdit;
    QPushButton*        mpSubmitBtn;
    QTabWidget*         mpReqTab;
    ReqBodyWidget*      mpReqBodyWidget;
    ReqCookieWidget*    mpRepCookieWidget;
    ReqHeaderWidget*    mpReqHeaderWidget;
    QTabWidget*         mpRespTab;
    RespBodyWidget*     mpRespBodyWidget;
    RespCookieWidget*   mpRespCookieWidget;
    RespHeaderWidget*   mpRespHeaderWidget;

    QNetworkAccessManager*  mpNetMgr;
    QNetworkReply*          mpReply;
};

#endif