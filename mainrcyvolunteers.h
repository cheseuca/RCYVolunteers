#ifndef MAINRCYVOLUNTEERS_H
#define MAINRCYVOLUNTEERS_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlDatabase>

namespace Ui {
class MainRCYVolunteers;
}

class MainRCYVolunteers : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainRCYVolunteers(QWidget *parent = nullptr);
    ~MainRCYVolunteers();

private slots:


    void on_pushButton_Logout_clicked();

    void on_pushButton_Schedules_clicked();

    void on_pushButton_SaveNPrint_clicked();

    void on_pushButton_Volunteers_2_clicked();

    void on_pushButton_SaveNPrint_2_clicked();

    void on_pushButton_Schedules_3_clicked();

    void on_pushButton_Volunteers_3_clicked();

    void closeMainWindow();

    void on_pushButton_AddVolunteer_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainRCYVolunteers *ui;
    QSqlDatabase db;
};

#endif // MAINRCYVOLUNTEERS_H
