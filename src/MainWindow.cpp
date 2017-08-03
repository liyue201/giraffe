#include "MainWindow.h"
#include "ReqBodyWidget.h"
#include "ReqCookieWidget.h"
#include "ReqHeaderWidget.h"
#include "RespBodyWidget.h"
#include "RespCookieWidget.h"
#include "RespHeaderWidget.h"


MainWindow::MainWindow(QWidget *parent)
: QDialog(parent)
{
    setWindowFlags(windowFlags() &~Qt::WindowContextHelpButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    setMinimumSize(800, 600);

    mpMethodBox = new QComboBox(this);
    mpUrlEdit = new QTextEdit(this);
    mpUrlEdit->setFixedHeight(40);
    mpSubmitBtn = new QPushButton(tr("submit"), this);

    QHBoxLayout* hly1 = new QHBoxLayout;
    hly1->addWidget(mpMethodBox);
    hly1->addWidget(mpSubmitBtn);
    hly1->addStretch();

    mpReqTab = new QTabWidget(this);
    mpReqBodyWidget = new ReqBodyWidget(this);
    mpRespCookieWidget = new RespCookieWidget(this);
    mpReqHeaderWidget = new ReqHeaderWidget(this);
    mpReqTab->addTab(mpReqBodyWidget, "Body");
    mpReqTab->addTab(mpReqHeaderWidget, "Headers");
    mpReqTab->addTab(mpRespCookieWidget, "Cookies");
 
    mpRespTab = new QTabWidget(this);
    mpRespBodyWidget = new RespBodyWidget(this);
    mpRespCookieWidget = new RespCookieWidget(this);
    mpRespHeaderWidget = new RespHeaderWidget(this);
    mpRespTab->addTab(mpRespBodyWidget, "Body");
    mpRespTab->addTab(mpRespHeaderWidget, "Headers");
    mpRespTab->addTab(mpRespCookieWidget, "Cookies");

    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(mpReqTab);
    splitter->addWidget(mpRespTab);

    QVBoxLayout* mainLy = new QVBoxLayout(this);
    mainLy->addWidget(mpUrlEdit);
    mainLy->addLayout(hly1);
    mainLy->addWidget(splitter);

    mpNetMgr = new QNetworkAccessManager(this);

    Init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::Init()
{
    QStringList list;
    list << "GET" << "POST" << "HEAD" << "PUT" << "DELETE";
    mpMethodBox->addItems(list);
    mpUrlEdit->setPlaceholderText("http://");

    connect(mpSubmitBtn, SIGNAL(clicked()), this, SLOT(OnSumit()));
}

void MainWindow::OnSumit()
{
    mpSubmitBtn->setEnabled(false);
    QNetworkRequest req;
    req.setUrl(mpUrlEdit->toPlainText());

    QList<QNetworkReply::RawHeaderPair> headers = mpReqHeaderWidget->GetHeaders();
    for (int i = 0; i < headers.size(); i++) {
        req.setRawHeader(headers[i].first, headers[i].second);
    }

    if (mpMethodBox->currentText() == "GET") 
    {
        mpReply = mpNetMgr->get(req);
    }
    else if (mpMethodBox->currentText() == "POST")
    {
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QString data = mpReqBodyWidget->GetText();
        mpReply = mpNetMgr->post(req, data.toUtf8());
    }
    else
    {
        mpSubmitBtn->setEnabled(true);
    }
    connect(mpReply, SIGNAL(finished()), this, SLOT(OnNetFinished()));
    connect(mpReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(OnNetError(QNetworkReply::NetworkError)));
}

void MainWindow::OnNetFinished()
{
    mpSubmitBtn->setEnabled(true);
    QByteArray data = mpReply->readAll();

    QJsonParseError jsonErr;

    QJsonDocument doc = QJsonDocument::fromJson(data, &jsonErr);
    if (jsonErr.error == QJsonParseError::NoError)
    {
       mpRespBodyWidget->SetText(QString::fromUtf8(doc.toJson(QJsonDocument::Indented)));
    }
    else
    {
        mpRespBodyWidget->SetText(QString::fromUtf8(data));
    }
    
    const QList<QNetworkReply::RawHeaderPair>& headers = mpReply->rawHeaderPairs();
  
    QString strHeader;
    for (int i = 0; i < headers.size(); i++)
    {
        strHeader += QString::fromUtf8(headers[i].first) + ": " + QString::fromUtf8(headers[i].second);
        strHeader += "\n";
    }
    mpRespHeaderWidget->SetText(strHeader);
}

void MainWindow::OnNetError(QNetworkReply::NetworkError err)
{
    qDebug() <<  __FUNCTION__ << "error:" << err;
}






