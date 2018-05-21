#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("recept");
    db.setHostName("localhost");
    db.setPassword("0000");
    db.setPort(8585);
    db.setUserName("root");
    if(!db.open()){
        QMessageBox::critical(this, "Error", "Nem megy!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
