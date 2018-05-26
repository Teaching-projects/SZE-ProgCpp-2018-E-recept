#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>

class Database{
    public:
        Database();
        ~Database();
        bool connnectIfNeccessary();
        QString getError();

    private:
        QSqlDatabase db;

};

#endif // DATABASE_H
