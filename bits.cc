//bits.cpp
#include <iostream>
#include <bitset>
#include "bits.hpp"




std::string strip_lead_zeros(std::string s)
{
    size_t len = s.length();
    size_t i = 0;
    //first find the range to delete
    for ( ; i < len ; ++i){
        if (s[i] == '1')
            break;
    }
    //determine if there are leading zeroes to delete
    if (i > 0)
        return s.erase(0,i);
    return s;
}


std::string chr_to_binary(char c,bool remove_lead_zeros=false)
{
    std::bitset<8> bset(c);
    std::string s = bset.to_string();
    if (remove_lead_zeros){
        s = strip_lead_zeros(s);
    }
    return s;
}


std::string str_to_binary(std::string s)
{
    std::string t("");
    for (int i = 0; i < s.length(); ++i){
        t += chr_to_binary(s[i]);
    }
    return t;
}

size_t chrs_to_number(char c1, char c2)
{
    std::string s({c1,c2});
    s = str_to_binary(s);
    std::bitset<16> bset(s);
    return bset.to_ulong();
}

std::string make_zero_string(unsigned int x){
    std::string s;
    for (size_t i = 0; i < x; ++i){
        s.push_back('0');
    }
    return s;
}

std::string pad_string(std::string s,unsigned int total, bool left)
{
    unsigned int length = s.length();
    if (length < total){
        unsigned int diff = total - length;
        std::string zerostr = make_zero_string(diff);
        if (left == true){
            zerostr = zerostr + s;
        }
        else{
            zerostr = s + zerostr;
        }
        return zerostr;
    }
   return s; 
}


std::string make_token_eof(size_t L, size_t S)
{
    return make_zero_string(L) + \
        make_zero_string(S);
}

std::string make_token_double(size_t L, \
                              size_t N, \
                              size_t matchlen,\
                              size_t offsetindex)
{
    std::string match_str = chr_to_binary(matchlen - 1,true);
    if (match_str.length() < L)
        match_str = pad_string(match_str,L,true);
    std::string offset_str = chr_to_binary(offsetindex,true);
    if (offset_str.length() < N)
        offset_str = pad_string(offset_str,N,true);
    return match_str + offset_str;
}

std::string make_token_triple(std::string chars,
                              size_t L,\
                              size_t S,
                              size_t num_chars)
{
    std::string L_str, strlen_str, chars_str;
    L_str = make_zero_string(L);
    //create <strlen,chars>
    strlen_str = std::to_string(num_chars); //convert integer to str
    strlen_str = str_to_binary(strlen_str);
    strlen_str = pad_string(strlen_str, S,true);
    chars_str = str_to_binary(chars);
    return L_str + strlen_str + chars_str;

}


