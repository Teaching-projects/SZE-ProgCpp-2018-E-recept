#ifndef ADD_DIALOG_H
#define ADD_DIALOG_H

#include <QDialog>
#include "database.h"
#include "inputvalidator.h"
#include <QMessageBox>

namespace Ui {
class add_dialog;
}

class add_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_dialog(QWidget *parent = 0);
    ~add_dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::add_dialog *ui;
};

#endif // ADD_DIALOG_H
