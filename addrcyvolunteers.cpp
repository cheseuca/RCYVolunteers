#include "addrcyvolunteers.h"
#include "ui_addrcyvolunteers.h"

AddRCYVolunteers::AddRCYVolunteers(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRCYVolunteers),
    database(db)
{
    ui->setupUi(this);

    //Professions Choices
    ui->comboBox_Profession->addItem("Student");
    ui->comboBox_Profession->addItem("Teacher");
    ui->comboBox_Profession->addItem("Office Worker");

    //Volunteer Type Choices
    ui->comboBox_VolunteerType->addItem("Instructor");
    ui->comboBox_VolunteerType->addItem("First Aider");
    ui->comboBox_VolunteerType->addItem("Officers");
    ui->comboBox_VolunteerType->addItem("Representative");

}

AddRCYVolunteers::~AddRCYVolunteers()
{
    delete ui;
}

void AddRCYVolunteers::on_pushButton_AddVolunteer_clicked()
{

}


void AddRCYVolunteers::on_pushButton_InsertPhoto_clicked()
{

}

