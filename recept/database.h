#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>
#include <QSqlQuery>
#include <chrono>

class Database{
    public:
        Database();
        ~Database();
        bool connnectIfNeccessary();
        QString getError();
        bool changeNotChangedDrugMin(int count);
        bool addNewDrug(QString name, QString code, QString desc, bool paper, int price, int min);
        bool saveToStorage(int count, QString code);
        bool exists(QString name, QString code);

        QString getHumanErrorMessage() const;

private:
        QSqlDatabase db;
        QString humanErrorMessage;

        void setHumanErrorMessage(QString value);

};

#endif // DATABASE_H
