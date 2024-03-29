#include "rcyvolunteers.h"
#include <QMessageBox>
#include "mainrcyvolunteers.h"
#include "ui_rcyvolunteers.h"

RCYVolunteers::RCYVolunteers(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RCYVolunteers)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
}

RCYVolunteers::~RCYVolunteers()
{
    delete ui;
}

void RCYVolunteers::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (username == "admin" && password == "admin123") {
        QMessageBox::information(this, "Sign In", "Username and Password are Correct");

        close();

        MainRCYVolunteers *mainrcyvolunteers = new MainRCYVolunteers;
        mainrcyvolunteers->show();

    } else {
        QMessageBox::warning(this, "Sign In", "Username or Password is incorrect");
    }
}
