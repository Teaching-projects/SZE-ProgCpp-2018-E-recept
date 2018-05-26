/********************************************************************************
** Form generated from reading UI file 'add_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_DIALOG_H
#define UI_ADD_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_add_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *add_dialog)
    {
        if (add_dialog->objectName().isEmpty())
            add_dialog->setObjectName(QStringLiteral("add_dialog"));
        add_dialog->resize(409, 274);
        buttonBox = new QDialogButtonBox(add_dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        label = new QLabel(add_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        lineEdit = new QLineEdit(add_dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 10, 221, 20));
        label_2 = new QLabel(add_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 101, 16));
        plainTextEdit = new QPlainTextEdit(add_dialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(110, 60, 104, 64));
        label_3 = new QLabel(add_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 101, 21));
        comboBox = new QComboBox(add_dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 130, 55, 22));
        label_4 = new QLabel(add_dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 101, 21));
        lineEdit_2 = new QLineEdit(add_dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 160, 113, 20));
        label_5 = new QLabel(add_dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 190, 101, 21));
        lineEdit_3 = new QLineEdit(add_dialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 190, 113, 20));
        label_6 = new QLabel(add_dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 35, 21));
        lineEdit_4 = new QLineEdit(add_dialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 30, 113, 20));

        retranslateUi(add_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), add_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), add_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(add_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_dialog)
    {
        add_dialog->setWindowTitle(QApplication::translate("add_dialog", "\303\232j gy\303\263gyszer hozz\303\241ad\303\241sa", nullptr));
        label->setText(QApplication::translate("add_dialog", "N\303\251v:", nullptr));
        label_2->setText(QApplication::translate("add_dialog", "Le\303\255r\303\241s:", nullptr));
        label_3->setText(QApplication::translate("add_dialog", "Recept k\303\266teles:", nullptr));
        comboBox->setItemText(0, QApplication::translate("add_dialog", "Igen", nullptr));
        comboBox->setItemText(1, QApplication::translate("add_dialog", "Nem", nullptr));

        label_4->setText(QApplication::translate("add_dialog", "Be\303\251rkezett mennyis\303\251g:", nullptr));
        label_5->setText(QApplication::translate("add_dialog", "\303\201r:", nullptr));
        label_6->setText(QApplication::translate("add_dialog", "K\303\263d:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_dialog: public Ui_add_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_DIALOG_H
