#include "mainrcyvolunteers.h"
#include "ui_mainrcyvolunteers.h"
//#include "logoutpanel.h"

MainRCYVolunteers::MainRCYVolunteers(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainRCYVolunteers)
{
    ui->setupUi(this);
}

MainRCYVolunteers::~MainRCYVolunteers()
{
    delete ui;
}



void MainRCYVolunteers::on_pushButton_Logout_clicked()
{
    //LogoutPanel *logoutpanel = new LogoutPanel;
    //logoutpanel->show();
}

