#include "drug.h"

Drug::Drug()
{

}

int Drug::getId() const
{
    return id;
}

void Drug::setId(int value)
{
    id = value;
}

QString Drug::getName() const
{
    return name;
}

void Drug::setName(const QString &value)
{
    name = value;
}

QString Drug::getCode() const
{
    return code;
}

void Drug::setCode(const QString &value)
{
    code = value;
}

QString Drug::getDesc() const
{
    return desc;
}

void Drug::setDesc(const QString &value)
{
    desc = value;
}

bool Drug::getPaper() const
{
    return paper;
}

void Drug::setPaper(bool value)
{
    paper = value;
}

int Drug::getMin() const
{
    return min;
}

void Drug::setMin(int value)
{
    min = value;
}

bool Drug::getMinEdit() const
{
    return minEdit;
}

void Drug::setMinEdit(bool value)
{
    minEdit = value;
}

int Drug::getPrice() const
{
    return price;
}

void Drug::setPrice(int value)
{
    price = value;
}

int Drug::getCount() const
{
    return count;
}

void Drug::setCount(int value)
{
    count = value;
}
