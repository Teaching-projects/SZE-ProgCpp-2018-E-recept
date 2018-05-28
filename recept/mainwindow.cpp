#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db_init = QSqlDatabase::addDatabase("QMYSQL", "recept_db");
    db_init.setDatabaseName("recept");
    db_init.setHostName("localhost");
    db_init.setPassword("1234");
    db_init.setPort(3306);
    db_init.setUserName("root");
    db_init.close();
    if(!db_init.open()){
        QMessageBox::critical(this, "Error", "Unable to connect to the database!");
        QApplication::quit();
    }else {
        db_init.close();
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    db = Database();
//    if(db.connnectIfNeccessary()){
//        QMessageBox::critical(this, "State", "Opened");
//    }else {
//        QMessageBox::critical(this, "State", "Closed");
//    }
    add_dialog *dialog = new add_dialog();
    dialog->show();
    int result = dialog->exec();
    delete dialog;
}

void MainWindow::on_pushButton_2_clicked()
{
    Refresh_dialog *dialog = new Refresh_dialog();
    dialog->show();
    int result = dialog->exec();
    delete dialog;
}

void MainWindow::on_pushButton_3_clicked()
{
    ExpendDialog *dialog = new ExpendDialog();
    dialog->show();
    int result = dialog->exec();
    delete dialog;
}

void MainWindow::on_pushButton_4_clicked()
{
    OptionDialog *dialog = new OptionDialog();
        dialog->show();
        int result = dialog->exec();
        delete dialog;
}
