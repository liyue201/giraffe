#include "KMainWindow.h"

KMainWindow::KMainWindow(QWidget *parent)
: QDialog(parent)
{
    setWindowFlags(windowFlags() &~Qt::WindowContextHelpButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    setMinimumSize(600, 500);

    mpTab = new QTabWidget(this);

    QVBoxLayout* mainLy = new QVBoxLayout(this);
    mainLy->addWidget(mpTab);
}

KMainWindow::~KMainWindow()
{

}






