#include "storage.h"

Storage::Storage()
{

}

int Storage::getId() const
{
    return id;
}

void Storage::setId(int value)
{
    id = value;
}

int Storage::getCount() const
{
    return count;
}

void Storage::setCount(int value)
{
    count = value;
}

QString Storage::getCode() const
{
    return code;
}

void Storage::setCode(const QString &value)
{
    code = value;
}

int Storage::getDate() const
{
    return date;
}

void Storage::setDate(int value)
{
    date = value;
}
