#ifndef REFRESH_DIALOG_H
#define REFRESH_DIALOG_H

#include <QDialog>

namespace Ui {
class Refresh_dialog;
}

class Refresh_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Refresh_dialog(QWidget *parent = 0);
    ~Refresh_dialog();

private:
    Ui::Refresh_dialog *ui;
};

#endif // REFRESH_DIALOG_H
