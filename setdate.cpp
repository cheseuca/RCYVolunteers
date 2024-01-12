#include "setdate.h"
#include "ui_setdate.h"

SetDate::SetDate(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetDate),
    database(db)
{
    ui->setupUi(this);

    if (!db.open()) {
        qWarning() << "Database connection failed!";
    }
    QSqlQuery query;
    query.exec("SELECT Volunteers_FN, Volunteers_SN FROM VolunteersInfo");

    ui->comboBox_Name->clear();

    while (query.next()) {
        QString combinedText = query.value(0).toString() + " " + query.value(1).toString();
        ui->comboBox_Name->addItem(combinedText);
    }
}

SetDate::~SetDate()
{
    delete ui;
}

void SetDate::setDate(const QDate &date){
    ui->label_Date->setText(date.toString("yyyy-MM-dd"));
}


void SetDate::on_pushButton_clicked()
{
    QSqlQuery query;

    QString insertQuery = "INSERT INTO VolunteerActivityDates(Date, School, Assigned_Volunteer) VALUES (:date, :school, :assign)";
    query.prepare(insertQuery);

    query.bindValue(":date", ui->label_Date->text());
    query.bindValue(":school", ui->lineEdit_School->text());
    query.bindValue(":assign", ui->comboBox_Name->currentText());

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error: Unable to execute query";
    } else {
        qDebug() << "Data inserted successfully";
    }

    QMessageBox::information(this, "Message", "New Activity Assigned Successfully");
}

