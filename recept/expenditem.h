#ifndef EXPENDITEM_H
#define EXPENDITEM_H

#include <QString>

class ExpendItem
{
public:
    ExpendItem();

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

#endif // EXPENDITEM_H
