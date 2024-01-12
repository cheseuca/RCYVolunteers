#ifndef SETDATE_H
#define SETDATE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class SetDate;
}

class SetDate : public QDialog
{
    Q_OBJECT

public:
    explicit SetDate(QSqlDatabase db, QWidget *parent = nullptr);
    ~SetDate();

    void setDate(const QDate &date);


private slots:
    void on_pushButton_clicked();

private:
    Ui::SetDate *ui;
    QSqlDatabase database;
};

#endif // SETDATE_H
