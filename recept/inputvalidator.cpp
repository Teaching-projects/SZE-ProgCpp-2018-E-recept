#include "inputvalidator.h"

InputValidator::InputValidator()
{

}

bool InputValidator::onlyChars(QString s)
{
    if (s.length() == 0) {
        return false;
    }
    for(int i = 0; i < (s.length()-1); i++){
        if(!s.at(i).isLetter()){
            return false;
        }
    }
    return true;
}

bool InputValidator::onlyNums(QString s)
{
    if (s.length() == 0) {
        return false;
    }
    for(int i = 0; i < (s.length()-1); i++){
        if(!s.at(i).isDigit()){
            return false;
        }
    }
    return true;
}

bool InputValidator::onlyNumsOrChars(QString s)
{
    if (s.length() == 0) {
        return false;
    }
    for(int i = 0; i < (s.length()-1); i++){
        if(!s.at(i).isLetterOrNumber()){
            return false;
        }
    }
    return true;
}

bool InputValidator::checkMin(QString min)
{
    if (min.length() == 0) {
        return true;
    }
    for(int i = 0; i < (min.length()-1); i++){
        if(!min.at(i).isDigit()){
            return false;
        }
    }
    return true;
}
