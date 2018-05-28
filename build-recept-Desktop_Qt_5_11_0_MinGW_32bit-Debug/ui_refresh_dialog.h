/********************************************************************************
** Form generated from reading UI file 'refresh_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFRESH_DIALOG_H
#define UI_REFRESH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Refresh_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *Refresh_dialog)
    {
        if (Refresh_dialog->objectName().isEmpty())
            Refresh_dialog->setObjectName(QStringLiteral("Refresh_dialog"));
        Refresh_dialog->resize(376, 119);
        buttonBox = new QDialogButtonBox(Refresh_dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        label = new QLabel(Refresh_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 31));
        lineEdit = new QLineEdit(Refresh_dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 10, 171, 21));
        label_2 = new QLabel(Refresh_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 31));
        lineEdit_2 = new QLineEdit(Refresh_dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 50, 171, 21));

        retranslateUi(Refresh_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Refresh_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Refresh_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Refresh_dialog);
    } // setupUi

    void retranslateUi(QDialog *Refresh_dialog)
    {
        Refresh_dialog->setWindowTitle(QApplication::translate("Refresh_dialog", "Megl\303\251v\305\221 gy\303\263gyszer bevitele", nullptr));
        label->setText(QApplication::translate("Refresh_dialog", "K\303\263d:", nullptr));
        label_2->setText(QApplication::translate("Refresh_dialog", "Mennyis\303\251g:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Refresh_dialog: public Ui_Refresh_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFRESH_DIALOG_H
