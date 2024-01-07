#include "mainrcyvolunteers.h"
#include "ui_mainrcyvolunteers.h"

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
