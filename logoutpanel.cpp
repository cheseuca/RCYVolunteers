#include "logoutpanel.h"
#include "ui_logoutpanel.h"
#include "rcyvolunteers.h"
#include "mainrcyvolunteers.h"

LogoutPanel::LogoutPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogoutPanel)
{
    ui->setupUi(this);

}

LogoutPanel::~LogoutPanel()
{
    delete ui;

}

void LogoutPanel::on_pushButton_Logout_clicked()
{
    emit requestMainWindowClose();
    close();
    RCYVolunteers *rcyvolunteers = new RCYVolunteers;
    rcyvolunteers->show();
}


void LogoutPanel::on_pushButton_CancelLogout_clicked()
{
    close();
}

