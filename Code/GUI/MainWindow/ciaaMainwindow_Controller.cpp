#include "ciaaMainWindow_Controller.h"
#include "ui_ciaaMainwindow_View.h"

ciaaMainWindow_Controller::ciaaMainWindow_Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ciaaMainWindow_Controller)
{
    ui->setupUi(this);
}

ciaaMainWindow_Controller::~ciaaMainWindow_Controller()
{
    delete ui;
}
