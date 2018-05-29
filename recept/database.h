#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>
#include <QSqlQuery>
#include <chrono>
#include <QStringList>
#include "drug.h"

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
        bool saveExpand(QString code, int count);
        int checkCountAndRemove(QString code, int count);
        QStringList getDrugs();
        int getStorageCountByCode(QString code);
        Drug getDrugByName(QString name);
        bool changeDrugPrefs(QString name, QString desc, bool paper, int min, bool minEdit, int price);


        QString getHumanErrorMessage() const;

private:
        QSqlDatabase db;
        QString humanErrorMessage;

        void setHumanErrorMessage(QString value);

};

#endif // DATABASE_H
