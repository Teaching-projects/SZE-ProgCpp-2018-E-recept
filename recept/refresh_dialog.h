#ifndef REFRESH_DIALOG_H
#define REFRESH_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "inputvalidator.h"
#include "database.h"

namespace Ui {
class Refresh_dialog;
}

class Refresh_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Refresh_dialog(QWidget *parent = 0);
    ~Refresh_dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Refresh_dialog *ui;
};

#endif // REFRESH_DIALOG_H
