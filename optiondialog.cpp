#include "optiondialog.h"
#include "ui_optiondialog.h"

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    Database *db = new Database();
    items = db->getDrugs();

    for(int i = 0; i < items.size(); i++){
        ui->drugsList->addItem(items.at(i));
    }
    delete db;
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_drugsList_currentRowChanged(int currentRow)
{
    Database *db = new Database();
    qDebug() << items.at(currentRow);

    Drug drug = db->getDrugByName(items.at(currentRow));

    ui->nameEdit->setText(drug.getName());
    ui->codeEdit->setText(drug.getCode());
    ui->descEdit->setPlainText(drug.getDesc());
    drug.getPaper()? ui->paperBox->setCurrentIndex(0): ui->paperBox->setCurrentIndex(1);
    ui->minEdit->setText(QString::number(drug.getMin()));
    ui->priceEdit->setText(QString::number(drug.getPrice()));
    ui->countEdit->setText(QString::number(drug.getCount()));

    old_min = drug.getMin();

    delete db;
}

void OptionDialog::on_pushButton_clicked()
{
    Database *db = new Database();
    bool succ = db->changeDrugPrefs(ui->drugsList->currentItem()->text(),
                        ui->descEdit->toPlainText(),
                        ui->paperBox->itemData(ui->paperBox->currentIndex()) == "Igen"? true: false,
                        ui->minEdit->text().toInt(),
                        ui->minEdit->text().toInt() == old_min? false: true,
                        ui->priceEdit->text().toInt());

    if(succ){
        QMessageBox::critical(this, "Mentve", "Adatok sikeresen elmentve!");
    }else{
        QMessageBox::critical(this, "Hiba", db->getHumanErrorMessage());
    }

    delete db;
}
