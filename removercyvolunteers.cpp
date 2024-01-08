#include "removercyvolunteers.h"
#include "ui_removercyvolunteers.h"

RemoveRCYVolunteers::RemoveRCYVolunteers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveRCYVolunteers)
{
    ui->setupUi(this);
}

RemoveRCYVolunteers::~RemoveRCYVolunteers()
{
    delete ui;
}
