#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "database.h"
#include "inputvalidator.h"
#include <QStringList>

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(QWidget *parent = 0);
    ~OptionDialog();

private slots:



    void on_drugsList_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

private:
    Ui::OptionDialog *ui;
    QStringList items;
    int old_min;
};

#endif // OPTIONDIALOG_H
