#ifndef ADDRCYVOLUNTEERS_H
#define ADDRCYVOLUNTEERS_H

#include <QDialog>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QBuffer>

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
    QSqlQuery addquery;
};

#endif // ADDRCYVOLUNTEERS_H
