#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QString>
#include "ctype.h"

class InputValidator
{
public:
    InputValidator();
    static bool onlyChars(QString s);
    static bool onlyNums(QString s);
    static bool onlyNumsOrChars(QString s);
    static bool checkMin(QString min);
};

#endif // INPUTVALIDATOR_H
