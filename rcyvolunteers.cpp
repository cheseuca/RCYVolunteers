#include "rcyvolunteers.h"
#include "ui_rcyvolunteers.h"

RCYVolunteers::RCYVolunteers(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RCYVolunteers)
{
    ui->setupUi(this);
}

RCYVolunteers::~RCYVolunteers()
{
    delete ui;
}
