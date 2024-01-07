#ifndef MAINRCYVOLUNTEERS_H
#define MAINRCYVOLUNTEERS_H

#include <QMainWindow>

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

private:
    Ui::MainRCYVolunteers *ui;
};

#endif // MAINRCYVOLUNTEERS_H
