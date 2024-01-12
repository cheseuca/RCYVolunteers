#include "mainrcyvolunteers.h"
#include "addrcyvolunteers.h"
#include "logoutpanel.h"
#include "ui_mainrcyvolunteers.h"
#include "setdate.h"

MainRCYVolunteers::MainRCYVolunteers(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainRCYVolunteers)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    currentRow = 0;

    //Connecting the Database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Windows 10/Desktop/RCYVolunteers.db");
    //See if the database is working
    if (!db.open()) {
        qDebug() << "Error: Database is not connected";
    } else {
        qDebug() << "Database is now connected";
    }

    queryModel.setQuery("SELECT * FROM VolunteersInfo");

    if (queryModel.lastError().isValid()) {
        qDebug() << "Query error: " << queryModel.lastError().text();
        return;
    }

    qDebug() << "Number of rows in query result: " << queryModel.rowCount();

    if (queryModel.rowCount() > 0) {
        moveDatabase();
    } else {
        qDebug() << "No records in the query result";
    }

    if (!queryModel.rowCount()) {
        qDebug() << "No more data";
        return;
    } else {
        qDebug() << "Perform select operation";
        queryModel.setData(queryModel.index(0, 0), QVariant()); // Move to the first record

    }
    moveDatabase();
}


MainRCYVolunteers::~MainRCYVolunteers()
{
    delete ui;
}

void MainRCYVolunteers::moveDatabase()
{
    QSqlRecord record = queryModel.record(currentRow);

    int volunteer_MAAB = record.value("Volunteers_MAAB").toInt();
    QString volunteer_FN = record.value("Volunteers_FN").toString();
    QString volunteer_MN = record.value("Volunteers_MN").toString();
    QString volunteer_SN = record.value("Volunteers_SN").toString();
    int volunteer_Mobile = record.value("Volunteers_MobileNo").toInt();
    QString volunteer_Pro = record.value("Volunteers_Profession").toString();
    QString volunteer_Type = record.value("Volunteers_Type").toString();

    QByteArray photoData = record.value("Volunteers_IMG").toByteArray();

    ui->label_ID->setText(QString::number(volunteer_MAAB));
    ui->label_FN->setText(volunteer_FN);
    ui->label_MN->setText(volunteer_MN);
    ui->label_LN->setText(volunteer_SN);
    ui->label_Mobile->setText(QString::number(volunteer_Mobile));
    ui->label_Pro->setText(volunteer_Pro);
    ui->label_Type->setText(volunteer_Type);

    // Display photo
    QPixmap pixmap;
    if (photoData.isEmpty()) {
        // Handle the case when there is no photo data
        qDebug() << "No photo data for volunteer MAAB: " << volunteer_MAAB;
        ui->label_IMG->clear();
    } else if (pixmap.loadFromData(photoData)) {
        ui->label_IMG->setPixmap(pixmap.scaled(ui->label_IMG->size(), Qt::KeepAspectRatio));
    } else {
        // Handle the case when there is an error loading the photo
        qDebug() << "Error loading photo for volunteer MAAB: " << volunteer_MAAB;
        ui->label_IMG->clear(); // Clear the QLabel if photo loading fails
    }
}

void MainRCYVolunteers::loadNext(){
    if (currentRow < queryModel.rowCount() - 1) {
        currentRow++;
        queryModel.setData(queryModel.index(currentRow, 0), QVariant());
        moveDatabase();
    } else {
        qDebug() << "No more data";
    }
}

void MainRCYVolunteers::loadPrevious(){
    if (currentRow > 0) {
        currentRow--;
        queryModel.setData(queryModel.index(currentRow, 0), QVariant());
        moveDatabase();
    } else {
        qDebug() << "No more data";
    }
}

void MainRCYVolunteers::on_pushButton_Logout_clicked()
{
    LogoutPanel *logoutPanel = new LogoutPanel(this);
    logoutPanel->setModal(true);

    connect(logoutPanel,
            &LogoutPanel::requestMainWindowClose,
            this,
            &MainRCYVolunteers::closeMainWindow);

    logoutPanel->exec();
}

void MainRCYVolunteers::closeMainWindow()
{
    this->close();
}

void MainRCYVolunteers::on_pushButton_Schedules_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainRCYVolunteers::on_pushButton_SaveNPrint_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);


    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("VolunteerActivityDates");
    model->select();

    ui->tableView_Records->setModel(model);
    ui->tableView_Records->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_Records->verticalHeader()->setVisible(false);
    ui->tableView_Records->hideColumn(0);
}

void MainRCYVolunteers::on_pushButton_Volunteers_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainRCYVolunteers::on_pushButton_SaveNPrint_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("VolunteerActivityDates");
    model->select();

    ui->tableView_Records->setModel(model);
    ui->tableView_Records->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_Records->verticalHeader()->setVisible(false);
    ui->tableView_Records->hideColumn(0);
}

void MainRCYVolunteers::on_pushButton_Schedules_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainRCYVolunteers::on_pushButton_Volunteers_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainRCYVolunteers::on_pushButton_AddVolunteer_clicked()
{
    AddRCYVolunteers *addrcyvolunteers = new AddRCYVolunteers(db, this);
    addrcyvolunteers->setModal(true);
    addrcyvolunteers->exec();
}

void MainRCYVolunteers::on_calendarWidget_clicked(const QDate &date) {
    SetDate *setDate = new SetDate(db, this);
    setDate->setDate(date);
    setDate->setModal(true);
    setDate->exec();
}

void MainRCYVolunteers::on_pushButton_Next_clicked()
{
    loadNext();
}


void MainRCYVolunteers::on_pushButton_Previous_clicked()
{
    loadPrevious();
}

