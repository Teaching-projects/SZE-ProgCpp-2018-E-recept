#ifndef EXPENDDIALOG_H
#define EXPENDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "database.h"
#include "inputvalidator.h"

namespace Ui {
class ExpendDialog;
}

class ExpendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExpendDialog(QWidget *parent = 0);
    ~ExpendDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ExpendDialog *ui;
};

#endif // EXPENDDIALOG_H
