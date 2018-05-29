#include "refresh_dialog.h"
#include "ui_refresh_dialog.h"

Refresh_dialog::Refresh_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Refresh_dialog)
{
    ui->setupUi(this);
}

Refresh_dialog::~Refresh_dialog()
{
    delete ui;
}

void Refresh_dialog::on_buttonBox_accepted()
{
    if (!InputValidator::onlyNumsOrChars(ui->codeEdit->text())) {
        QMessageBox::critical(this, "Hiba", "Hiba a kód megadásával!");
    }else if (!InputValidator::onlyNums(ui->countEdit->text())) {
        QMessageBox::critical(this, "Hiba", "Hiba a mennyiség megadásával!");
    }else{
        Database *db = new Database();
        bool succ = db->saveToStorage(ui->countEdit->text().toInt(),
                          ui->codeEdit->text());

        if(succ){
            QMessageBox::warning(this, "Bevitel", "Sikeres bevitel!");
        }else {
            QMessageBox::critical(this, "Hiba", db->getHumanErrorMessage());
            qDebug() << db->getError();
        }
    }
}
