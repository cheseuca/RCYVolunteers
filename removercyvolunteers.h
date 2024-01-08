#ifndef REMOVERCYVOLUNTEERS_H
#define REMOVERCYVOLUNTEERS_H

#include <QDialog>

namespace Ui {
class RemoveRCYVolunteers;
}

class RemoveRCYVolunteers : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveRCYVolunteers(QWidget *parent = nullptr);
    ~RemoveRCYVolunteers();

private:
    Ui::RemoveRCYVolunteers *ui;
};

#endif // REMOVERCYVOLUNTEERS_H
