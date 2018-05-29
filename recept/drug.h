#ifndef DRUG_H
#define DRUG_H

#include <QString>


class Drug
{
public:
    Drug();
    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getCode() const;
    void setCode(const QString &value);

    QString getDesc() const;
    void setDesc(const QString &value);

    bool getPaper() const;
    void setPaper(bool value);

    int getMin() const;
    void setMin(int value);

    bool getMinEdit() const;
    void setMinEdit(bool value);

    int getPrice() const;
    void setPrice(int value);

    int getCount() const;
    void setCount(int value);

private:
    int id;
    QString name;
    QString code;
    QString desc;
    bool paper;
    int min;
    bool minEdit;
    int price;
    int count;


};

#endif // DRUG_H
