#include "addrcyvolunteers.h"
#include "ui_addrcyvolunteers.h"

AddRCYVolunteers::AddRCYVolunteers(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRCYVolunteers)
    , database(db)
{
    ui->setupUi(this);

    //Professions Choices
    ui->comboBox_Profession->addItem("Student");
    ui->comboBox_Profession->addItem("Teacher");
    ui->comboBox_Profession->addItem("Office Worker");

    //Volunteer Type Choices
    ui->comboBox_VolunteerType->addItem("Instructor");
    ui->comboBox_VolunteerType->addItem("First Aider");
    ui->comboBox_VolunteerType->addItem("Officer");
    ui->comboBox_VolunteerType->addItem("Representative");
}

AddRCYVolunteers::~AddRCYVolunteers()
{
    delete ui;
}

void AddRCYVolunteers::on_pushButton_AddVolunteer_clicked() {


    QSqlQuery query;

    QString insertQuery = "INSERT INTO VolunteersInfo "
                          "(Volunteers_MAAB, Volunteers_FN, Volunteers_MN, Volunteers_SN, "
                          "Volunteers_MobileNo, Volunteers_Profession, Volunteers_Type, Volunteers_IMG) "
                          "VALUES "
                          "(:maab, :fn, :mn, :sn, :mobileNo, :profession, :type, :img)";
    query.prepare(insertQuery);


    query.bindValue(":maab", ui->lineEdit_ID->text().toInt());
    query.bindValue(":fn", ui->lineEdit_FN->text());
    query.bindValue(":mn", ui->lineEdit_MN->text());
    query.bindValue(":sn", ui->lineEdit_SN->text());
    query.bindValue(":mobileNo", ui->lineEdit_MobileNo->text().toInt());
    query.bindValue(":profession", ui->comboBox_Profession->currentText());
    query.bindValue(":type", ui->comboBox_VolunteerType->currentText());

    QPixmap pixmap = ui->label_VolunteerPhoto->pixmap();
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "jpg");

    query.bindValue(":img", byteArray);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error: Unable to execute query" << query.lastError();
    } else {
        qDebug() << "Data inserted successfully";
    }

    QMessageBox::information(this, "Message", "New Volunteer Added Successfully");
    ui->lineEdit_ID->clear();
    ui->lineEdit_FN->clear();
    ui->lineEdit_MN->clear();
    ui->lineEdit_SN->clear();
    ui->lineEdit_MobileNo->clear();
    ui->label_VolunteerPhoto->clear();

}

void AddRCYVolunteers::on_pushButton_InsertPhoto_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.jpg)"));
    if (QString::compare(filename, QString()) != 0)
    {
        // Check if the selected file has a .jpg extension
        if (!filename.endsWith(".jpg", Qt::CaseInsensitive))
        {
            QMessageBox::critical(this, tr("Error"), tr("Please select a JPG file."), QMessageBox::Ok);
            return; // Exit the function if the file is not a JPG
        }

        QImage image;
        bool valid = image.load(filename);
        if (valid)
        {
            image = image.scaledToWidth(ui->label_VolunteerPhoto->width(), Qt::SmoothTransformation);
            ui->label_VolunteerPhoto->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            // Error loading image
            QMessageBox::critical(this, tr("Error"), tr("Failed to load the image."), QMessageBox::Ok);
        }
    }
}
