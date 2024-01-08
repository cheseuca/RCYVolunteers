#include "mainrcyvolunteers.h"
#include "ui_mainrcyvolunteers.h"
#include "logoutpanel.h"
#include "addrcyvolunteers.h"

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
    LogoutPanel *logoutPanel = new LogoutPanel(this);

    connect(logoutPanel, &LogoutPanel::requestMainWindowClose, this, &MainRCYVolunteers::closeMainWindow);

    logoutPanel->exec();
}

void MainRCYVolunteers::closeMainWindow()
{

    this->close();
}


void MainRCYVolunteers::on_pushButton_Schedules_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainRCYVolunteers::on_pushButton_SaveNPrint_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainRCYVolunteers::on_pushButton_Volunteers_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainRCYVolunteers::on_pushButton_SaveNPrint_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainRCYVolunteers::on_pushButton_Schedules_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainRCYVolunteers::on_pushButton_Volunteers_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainRCYVolunteers::on_pushButton_clicked()
{

}


void MainRCYVolunteers::on_pushButton_AddVolunteer_clicked()
{
    AddRCYVolunteers *addrcyvolunteers = new AddRCYVolunteers;
    addrcyvolunteers->show();
}

