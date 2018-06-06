#include "token_triple.hpp" 
#include <math.h>
#include <iostream>

tokenTriple::tokenTriple(size_t S,std::string s)
    : str(s)
{
    max_strlen = pow(2,S) - 1;
    if (s.length() > max_strlen)
        std::cout << "error init tokenTriple" << std::endl;
}

std::string tokenTriple::updateTriple(std::string s)
{
    //TODO: change this to standard error
    str += s;
    size_t length = str.length();
    if (length >= max_strlen){
        std::string tstr;
        tstr = str.substr(0,max_strlen);
        //update str to be remaning portion not returned
        if (max_strlen <  length){
            str = str.substr(max_strlen,length-1);
        }
        else{
            //thre was nothing left
            reset();
        }
        return tstr;
    }
    //if we reached here it means we were able to
    //accomodate the string
    return "";
}
 
void tokenTriple::reset()
{
    str = "";
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

bool tokenTriple::isEmpty()
{
    if (str == "")
        return true;
    else
        return false;
}

