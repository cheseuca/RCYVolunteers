#include "addrcyvolunteers.h"
#include "ui_addrcyvolunteers.h"

AddRCYVolunteers::AddRCYVolunteers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRCYVolunteers)
{
    ui->setupUi(this);
}

AddRCYVolunteers::~AddRCYVolunteers()
{
    delete ui;
}
