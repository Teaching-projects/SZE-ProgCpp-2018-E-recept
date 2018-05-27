#include "expenditem.h"

ExpendItem::ExpendItem()
{

}

int ExpendItem::getId() const
{
    return id;
}

void ExpendItem::setId(int value)
{
    id = value;
}

int ExpendItem::getCount() const
{
    return count;
}

void ExpendItem::setCount(int value)
{
    count = value;
}

QString ExpendItem::getCode() const
{
    return code;
}

void ExpendItem::setCode(const QString &value)
{
    code = value;
}

int ExpendItem::getDate() const
{
    return date;
}

void ExpendItem::setDate(int value)
{
    date = value;
}
