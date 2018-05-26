/********************************************************************************
** Form generated from reading UI file 'expenddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENDDIALOG_H
#define UI_EXPENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ExpendDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ExpendDialog)
    {
        if (ExpendDialog->objectName().isEmpty())
            ExpendDialog->setObjectName(QStringLiteral("ExpendDialog"));
        ExpendDialog->resize(400, 123);
        buttonBox = new QDialogButtonBox(ExpendDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        label = new QLabel(ExpendDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 31));
        lineEdit_2 = new QLineEdit(ExpendDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 50, 171, 21));
        label_2 = new QLabel(ExpendDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 31));
        lineEdit = new QLineEdit(ExpendDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 10, 171, 21));

        retranslateUi(ExpendDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExpendDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExpendDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExpendDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpendDialog)
    {
        ExpendDialog->setWindowTitle(QApplication::translate("ExpendDialog", "Gy\303\263gyszer kiad\303\241sa", nullptr));
        label->setText(QApplication::translate("ExpendDialog", "K\303\263d:", nullptr));
        label_2->setText(QApplication::translate("ExpendDialog", "Mennyis\303\251g:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpendDialog: public Ui_ExpendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENDDIALOG_H
