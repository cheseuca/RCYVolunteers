#ifndef LOGOUTPANEL_H
#define LOGOUTPANEL_H

#include <QDialog>

namespace Ui {
class LogoutPanel;
}

class LogoutPanel : public QDialog
{
    Q_OBJECT

public:
    explicit LogoutPanel(QWidget *parent = nullptr);
    ~LogoutPanel();

private slots:

    void on_pushButton_Logout_clicked();

    void on_pushButton_CancelLogout_clicked();

signals:
    void requestMainWindowClose();

private:
    Ui::LogoutPanel *ui;
};

#endif // LOGOUTPANEL_H
