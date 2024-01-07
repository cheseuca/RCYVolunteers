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

private:
    Ui::MainRCYVolunteers *ui;
};

#endif // MAINRCYVOLUNTEERS_H
