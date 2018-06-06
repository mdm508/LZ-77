#include "misc.hpp"
#include "bits.hpp"
#include <bitset>
#include <sstream>
#include <fstream>
#include <iostream>

std::string create_input_str(std::string infile)
{
    std::ifstream in(infile);
    std::stringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

size_t calc_relative_offset(size_t buf_index,size_t LAB_index)
{
    return LAB_index - buf_index;
}

unsigned char str_to_byte(std::string s){
    std::bitset<8> b(s);
    return static_cast<unsigned char> (b.to_ulong());
}


void write(std::string s,std::ostream& out)
{
    size_t len = s.length();
    std::string tstring;
    unsigned char c;
    if (len < 8){
        tstring = pad_string(s, 8,false);
        c = str_to_byte(tstring);
        //std::cout << tstring << std::endl;
        out << c;
        return;
    }
    size_t i = 0 ;
    for (; i+7 < len; i+=8){
        tstring = s.substr(i,8);
        //std::cout << tstring << std::endl;
        c = str_to_byte(tstring);
        out << c;
    }
    if (i < len){
        //pads right 
        //std::cout << tstring << std::endl;
        tstring = pad_string(s.substr(i,8),8,false);
        c = str_to_byte(tstring);
        out << c;
    }

}

//These functions help with decoding



