#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator appTranslator;

    if (appTranslator.load(qApp->applicationDirPath() + "/giraffe_CN.qm"))
    {
        app.installTranslator(&appTranslator);
        QTranslator* qtTranslator = new QTranslator(&app);
        if (qtTranslator->load(qApp->applicationDirPath() + "/qt_zh_CN.qm"))
        {
            app.installTranslator(qtTranslator);
        }
    }

    MainWindow window;
    window.show();
    return app.exec();
}


