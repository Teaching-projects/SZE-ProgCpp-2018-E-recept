#ifndef EXPENDDIALOG_H
#define EXPENDDIALOG_H

#include <QDialog>

namespace Ui {
class ExpendDialog;
}

class ExpendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExpendDialog(QWidget *parent = 0);
    ~ExpendDialog();

private:
    Ui::ExpendDialog *ui;
};

#endif // EXPENDDIALOG_H
