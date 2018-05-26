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
