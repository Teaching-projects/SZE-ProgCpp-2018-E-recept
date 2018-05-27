#ifndef STORAGE_H
#define STORAGE_H

#include <QString>

class Storage
{
public:
    Storage();

    int getId() const;
    void setId(int value);

    int getCount() const;
    void setCount(int value);

    QString getCode() const;
    void setCode(const QString &value);

    int getDate() const;
    void setDate(int value);

private:
    int id;
    int count;
    QString code;
    int date;
};

#endif // STORAGE_H
