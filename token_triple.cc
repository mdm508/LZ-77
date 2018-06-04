#include "token_triple.hpp" 
#include <math.h>
#include <iostream>

tokenTriple::tokenTriple(size_t S,std::string s)
    : str(s)
{
    max_strlen = pow(2,S) - 1;
}

void tokenTriple::updateTriple(std::string s)
{
    //TODO: change this to standard error
    if (! hasCapacity(s)){
        std::cout << "tried to add string without enough capacity" \
            << std::endl;
        return;
    }
    str += s;
}

size_t tokenTriple::calcBytesNeeded(){
    return 8 * str.length();
}
 
//SECTION: Get Methods
std::string tokenTriple::getString()
{
    return str;
}

size_t tokenTriple::getMaxStrLength(){
    return max_strlen;
}

//SECTION: True/False Methods
bool tokenTriple::hasCapacity(std::string s){
    if (s.length() + str.length() < max_strlen)
        return true;
    else
        return false;
}


