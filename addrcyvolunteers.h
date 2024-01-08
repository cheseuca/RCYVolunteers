#ifndef ADDRCYVOLUNTEERS_H
#define ADDRCYVOLUNTEERS_H

#include <QDialog>

namespace Ui {
class AddRCYVolunteers;
}

class AddRCYVolunteers : public QDialog
{
    Q_OBJECT

public:
    explicit AddRCYVolunteers(QWidget *parent = nullptr);
    ~AddRCYVolunteers();

private:
    Ui::AddRCYVolunteers *ui;
};

#endif // ADDRCYVOLUNTEERS_H
