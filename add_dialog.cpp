#include "add_dialog.h"
#include "ui_add_dialog.h"

add_dialog::add_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_dialog)
{
    ui->setupUi(this);
}

add_dialog::~add_dialog()
{
    delete ui;
}

void add_dialog::on_buttonBox_accepted()
{

    if(!InputValidator::onlyChars(ui->nameEdit->text())){
        QMessageBox::warning(this, "Hiba", "Nem megfelelő nevet írt be!");
    }else if (!InputValidator::onlyNumsOrChars(ui->codeEdit->text())) {
        QMessageBox::warning(this, "Hiba", "Nem megfelelő kódot írt be!");
    }else if (!InputValidator::onlyNums(ui->countEdit->text())) {
        QMessageBox::warning(this, "Hiba", "Nem megfelelő mennyiséget írt be!");
    }else if (!InputValidator::onlyNums(ui->priceEdit->text())) {
        QMessageBox::warning(this, "Hiba", "Nem megfelelő árat írt be!");
    }else if (!InputValidator::checkMin(ui->minEdit->text())) {
        QMessageBox::warning(this, "Hiba", "Nem megfelelő minimumot írt be!");
    }else {
        Database *db = new Database();
        bool succ_add = db->addNewDrug(ui->nameEdit->text(),
                       ui->codeEdit->text(),
                       ui->descEdit->toPlainText(),
                       ui->paperBox->itemData(ui->paperBox->currentIndex()) == "Igen" ? true : false,
                       ui->priceEdit->text().toInt(),
                       ui->minEdit->text() == "" ? 0 : ui->minEdit->text().toInt()
                      );

        bool succ_store = db->saveToStorage(ui->countEdit->text().toInt(),
                                            ui->codeEdit->text());

        if(succ_add && succ_store){
            QMessageBox::warning(this, "Elmentve", "Sikeresen elmentve az adatbázisba!");
        }else {
            QMessageBox::critical(this, "Hiba", db->getHumanErrorMessage());
            qDebug() << db->getError();
        }
        delete db;
    }

}
