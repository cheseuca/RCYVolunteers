#ifndef MAINRCYVOLUNTEERS_H
#define MAINRCYVOLUNTEERS_H

#include <QDateTime>
#include <QDebug>
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QSqlTableModel>
#include <QTableView>

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

    void on_pushButton_Next_clicked();

    void on_pushButton_Previous_clicked();

private:
    Ui::MainRCYVolunteers *ui;
    QSqlDatabase db;
    QSqlQueryModel queryModel;
    void loadNext();
    void loadPrevious();
    void moveDatabase();
    int currentRow;
};

#endif // MAINRCYVOLUNTEERS_H
