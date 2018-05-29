#include "database.h"

Database::Database(){
   db = QSqlDatabase::database("recept_db");
   //Auth error megoldás (MySQL script):
   //ALTER USER 'yourusername'@'localhost' IDENTIFIED WITH mysql_native_password BY 'youpassword';
    setHumanErrorMessage("Ajaj, itt valami baj van, ha ezt látod!");
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

QString Database::getHumanErrorMessage() const
{
    return humanErrorMessage;
}

void Database::setHumanErrorMessage(QString value)
{
    humanErrorMessage = value;
}

int Database::checkCountAndRemove(QString code, int count)
{
    QString selectQuery;
    selectQuery.append("SELECT Mennyiseg FROM recept.raktar WHERE kod = :code;");

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare(selectQuery);
    query->bindValue(":code", code);
    query->exec();

    if(query->lastError().text() != " "){
        qDebug() << query->lastError().text();
        setHumanErrorMessage("Adatbázishiba lépett fel!");
        delete query;
        return 0;
    }

    bool available;
    int old_value;

    while(query->next()){
        old_value = query->value(0).toInt();
        available = (old_value >= count);
    }

    delete query;
    if(!available){
        setHumanErrorMessage("Nincs elegendő mennyiség!");
        return 0;
    }

    QString updateQuery;
    updateQuery.append("UPDATE recept.raktar SET `Mennyiseg` = :new_count WHERE `kod` = :code;");

    query = new QSqlQuery(db);
    query->prepare(updateQuery);
    query->bindValue(":new_count", (old_value - count));
    query->bindValue(":code", code);
    query->exec();

    if(query->lastError().text() != " "){
        qDebug() << query->lastError().text();
        setHumanErrorMessage("Adatbázishiba lépett fel!");
        delete query;
        return 0;
    }
    delete query;

    selectQuery.clear();
    selectQuery.append("SELECT Raktar_Minimum_Keszlet FROM recept.gyogyszer WHERE kod = :code;");

    query = new QSqlQuery(db);
    query->prepare(selectQuery);
    query->bindValue(":code", code);
    query->exec();

    if(query->lastError().text() != " "){
        qDebug() << query->lastError().text();
        setHumanErrorMessage("Adatbázishiba lépett fel!");
        delete query;
        return 0;
    }

    int min;

    while(query->next()){
        min = query->value(0).toInt();
    }
    delete query;

    if((old_value - count) <= min){
        setHumanErrorMessage("Sikeresen kiadva!\nElérte a minimum mennyiséget!");
        return 1;
    }else{
        return 2;
    }

}

QStringList Database::getDrugs()
{
    QStringList items;

    QString queryString;
    queryString.append("SELECT Nev FROM recept.gyogyszer");

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare(queryString);
    query->exec();

    while (query->next()) {
        items.append(query->value(0).toString());
    }

    delete query;
    return items;
}

int Database::getStorageCountByCode(QString code)
{
    QString queryString;
    queryString.append("SELECT Mennyiseg FROM recept.raktar WHERE kod = :code");

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare(queryString);
    query->bindValue(":code", code);
    query->exec();

    qDebug() << query->lastError().text();

    while (query->next()) {
        qDebug() << query->value(0).toInt();
        return query->value(0).toInt();
    }
}

Drug Database::getDrugByName(QString name)
{
    QString queryString;
    queryString.append("SELECT * FROM recept.gyogyszer WHERE Nev = :name");

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare(queryString);
    query->bindValue(":name", name);
    query->exec();

    while(query->next()){
        Drug drug;

        drug.setName(query->value(1).toString());
        drug.setCode(query->value(2).toString());
        drug.setDesc(query->value(3).toString());
        drug.setPaper(query->value(4).toBool());
        drug.setMin(query->value(5).toInt());
        drug.setMinEdit(query->value(6).toBool());
        drug.setPrice(query->value(7).toInt());
        drug.setCount(getStorageCountByCode(drug.getCode()));

        return drug;
    }
}

bool Database::changeDrugPrefs(QString name, QString desc, bool paper, int min, bool minEdit,int price)
{
    QString updateString;
    updateString.append("UPDATE recept.gyogyszer SET `Leiras` = :desc, "
                        "`Recept_Koteles` = :paper, `Raktar_Minimum_Keszlet` = :min, "
                        "`raktar_minimum_szerk` = :min_edit, "
                        "`Ar` = :price WHERE `Nev` = :name;");

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare(updateString);
    query->bindValue(":desc", desc);
    query->bindValue(":paper", paper);
    query->bindValue(":min", min);
    query->bindValue(":min_edit", minEdit);
    query->bindValue(":price", price);
    query->bindValue(":name", name);
    query->exec();

    if(query->lastError().text() != " "){
        qDebug() << query->lastError().text();
        setHumanErrorMessage("Adatbázishiba történt!");
        delete query;
        return false;
    }

    delete query;
    return true;
}

bool Database::changeNotChangedDrugMin(int count)
{
    qDebug() << "change min";

}

bool Database::exists(QString name, QString code)
{
    if (connnectIfNeccessary()) {
        QString queryString;
        queryString.append("SELECT * FROM recept.gyogyszer ");
        if(name.length() != 0){
            queryString.append("WHERE `Nev` = :name;");
        }else{
            queryString.append("WHERE `Kod` = :code;");
        }

        QSqlQuery *query = new QSqlQuery(db);
        query->prepare(queryString);
        if(name.length() != 0){
            query->bindValue(":name", name);
        }else{
            query->bindValue(":code", code);
        }

        query->exec();

        if(query->lastError().text() != " "){
            qDebug() << query->lastError().text();
            setHumanErrorMessage("Adatbázis hiba lépett fel!");
            delete query;
            return true;
        }

        if(query->size() != 0){
            setHumanErrorMessage("Már létezik ilyen nevű gyógyszer!");
            delete query;
            return true;
        }else {
            delete query;
            return false;
        }
    }else {
        setHumanErrorMessage("Nem sikerült csatlakozni az adatbázishoz!");
        return true;
    }
}

bool Database::saveExpand(QString code, int count)
{
    if(connnectIfNeccessary()){
        if(!exists("", code)){
            setHumanErrorMessage("Nem létezik ilyen gyógyszer!");
            return false;
        }

        int result = checkCountAndRemove(code, count);
        if(result == 0){
            return false;
        }

        QString insertQuery;
        insertQuery.append("INSERT INTO recept.kiadott(`Mennyiseg`, `kod`) VALUES (:count, :code)");

        QSqlQuery *query = new QSqlQuery(db);
        query->prepare(insertQuery);
        query->bindValue(":count", count);
        query->bindValue(":code", code);
        query->exec();

        if(query->lastError().text() != " "){
            qDebug() << query->lastError().text();
            setHumanErrorMessage("Adatbázis hiba lépett fel!");
            delete query;
            return false;
        }
        if(result == 1){
            delete query;
            return false;
        }else{
            delete query;
            return true;
        }
    }else {
        setHumanErrorMessage("Nem sikerült csatlakozni az adatbázishoz!");
        return false;
    }
}

bool Database::addNewDrug(QString name, QString code, QString desc, bool paper, int price, int min)
{
    if(connnectIfNeccessary()){
        if(exists(name, "") || exists("", code)){
            return false;
        }

        QString queryString;
        queryString.append(
                    "INSERT INTO recept.gyogyszer ( `Nev`, `kod`, `Leiras`, `Ar`");
        if(paper){
            queryString.append(", `Recept_Koteles`");
        }
        if(min > 0){
            queryString.append(", `Raktar_Minimum_Keszlet`, `raktar_minimum_szerk`");
        }
        queryString.append(") VALUES ( :name, :code, :desc, :price");
        if(paper){
            queryString.append(", :paper");
        }
        if(min > 0){
            queryString.append(", :min, 1");
        }
        queryString.append(");");

        QSqlQuery *query = new QSqlQuery(db);
        query->prepare(queryString);
        query->bindValue(":name", name);
        query->bindValue(":code", code);
        query->bindValue(":desc", desc);
        query->bindValue(":price", price);

        if(paper){
            query->bindValue(":paper", paper? 1:0);
        }
        if(min > 0){
            query->bindValue(":min", min);
        }

        qDebug() << query->executedQuery();

        query->exec();
        if(query->lastError().text() == " "){
            delete query;
            return true;
        }else {
            delete query;
            setHumanErrorMessage("Adatbázis hiba lépett fel!");
            return false;
        }
    }else{
        setHumanErrorMessage("Nem sikerült csatlakozni az adatbázishoz!");
        return false;
    }
}

bool Database::saveToStorage(int count, QString code)
{
    if (connnectIfNeccessary()) {

        if(!exists("", code)){
            setHumanErrorMessage("Nem létezik ilyen gyógyszer!");
            return false;
        }

        QString queryString;
        queryString.append("SELECT Mennyiseg FROM recept.raktar WHERE raktar.kod = :code");

        QSqlQuery *query = new QSqlQuery(db);
        query->prepare(queryString);
        query->bindValue(":code", code);
        query->exec();

        if (query->lastError().text() != " ") {
            setHumanErrorMessage("Adatbázis hiba lépett fel!");
            qDebug() << query->lastError().text();
            delete query;
            return false;
        }

        if(query->size() <= 0){
            QString insertString;
            insertString.append("INSERT INTO recept.raktar(`Mennyiseg`,`kod`) "
                               "VALUES (:count, :code);");

            QSqlQuery *insertQuery = new QSqlQuery(db);
            insertQuery->prepare(insertString);
            insertQuery->bindValue(":count", count);
            insertQuery->bindValue(":code", code);
            insertQuery->exec();

            if (insertQuery->lastError().text() != " ") {
                setHumanErrorMessage("Adatbázis hiba lépett fel!");
                qDebug() << insertQuery->lastError().text();
                delete insertQuery;
                return false;
            }else {
                delete insertQuery;
                return true;
            }
        }else {
            query->next();
            int oldCount = query->value(0).toInt();
            int newCount = oldCount + count;

            QString updateString;
            updateString.append("UPDATE recept.raktar "
                                "SET `Mennyiseg` = :new_count "
                                "WHERE `Kod` = :code;");

            QSqlQuery *updateQuery = new QSqlQuery(db);
            updateQuery->prepare(updateString);
            updateQuery->bindValue(":new_count", newCount);
            updateQuery->bindValue(":code", code);
            updateQuery->exec();

            if (updateQuery->lastError().text() != " ") {
                setHumanErrorMessage("Adatbázis hiba lépett fel!");
                qDebug() << updateQuery->lastError().text();
                delete updateQuery;
                return false;
            }else {
                delete updateQuery;
                return true;
            }
        }
    }else {
        setHumanErrorMessage("Nem sikerült csatlakozni az adatbázishoz!");
        return false;
    }
}








