#ifndef RCYVOLUNTEERS_H
#define RCYVOLUNTEERS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RCYVolunteers;
}
QT_END_NAMESPACE

class RCYVolunteers : public QMainWindow
{
    Q_OBJECT

public:
    RCYVolunteers(QWidget *parent = nullptr);
    ~RCYVolunteers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RCYVolunteers *ui;
};
#endif // RCYVOLUNTEERS_H
