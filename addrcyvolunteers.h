#ifndef ADDRCYVOLUNTEERS_H
#define ADDRCYVOLUNTEERS_H

#include <QBuffer>
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>

namespace Ui {
class AddRCYVolunteers;
}

class AddRCYVolunteers : public QDialog
{
    Q_OBJECT

public:
    explicit AddRCYVolunteers(QSqlDatabase db, QWidget *parent = nullptr);
    ~AddRCYVolunteers();

private slots:
    void on_pushButton_AddVolunteer_clicked();

    void on_pushButton_InsertPhoto_clicked();

private:
    Ui::AddRCYVolunteers *ui;
    QSqlDatabase database;
};

#endif // ADDRCYVOLUNTEERS_H
