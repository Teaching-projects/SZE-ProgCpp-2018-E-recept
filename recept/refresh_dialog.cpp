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
