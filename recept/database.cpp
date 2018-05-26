#include "database.h"

Database::Database(){
   db = QSqlDatabase::database("recept_db");
   //Auth error megoldás (MySQL script):
   //ALTER USER 'yourusername'@'localhost' IDENTIFIED WITH mysql_native_password BY 'youpassword';
}

Database::~Database(){
    db.close();
}

bool Database::connnectIfNeccessary(){
    if(!db.isOpen()){
        return db.open();
    }else {
        return true;
    }
}

QString Database::getError(){
    return db.lastError().text();
}




