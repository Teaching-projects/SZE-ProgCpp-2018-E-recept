#include "expenddialog.h"
#include "ui_expenddialog.h"

ExpendDialog::ExpendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpendDialog)
{
    ui->setupUi(this);
}

ExpendDialog::~ExpendDialog()
{
    delete ui;
}

void ExpendDialog::on_buttonBox_accepted()
{
    if(!InputValidator::onlyNumsOrChars(ui->codeEdit->text())){
        QMessageBox::warning(this, "Hiba", "A megadott kód nem jó!");
    }else if (!InputValidator::onlyNums(ui->countEdit->text())) {
        QMessageBox::warning(this, "Hiba", "A megadott mennyiség nem helyes!");
    }else{
        Database *db = new Database();
        bool succ = db->saveExpand(ui->codeEdit->text(), ui->countEdit->text().toInt());
        if(succ){
            QMessageBox::warning(this, "Kiadás", "Kiadás sikeres!");
        }else{
            QMessageBox::critical(this, "Hiba", db->getHumanErrorMessage());
            qDebug() << db->getError();
        }
    }
}
