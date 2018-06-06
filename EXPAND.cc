#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <fstream>
#include <bitset>
#include "bits.hpp"
#include "misc.hpp"

const size_t L = 4;
const size_t N = 11;
const size_t S = 3;

using namespace std;

//function delcarations
size_t get_len(std::string str, size_t T);
size_t get_offset(std::string str,size_t N);
size_t write_using_offset(size_t matchlen, size_t offset, std::string& outstr, ostream& out);

//TODO: am i managing OSI correctly does it correspond to encoding?
int main(){
    const size_t L = 4;
        //@:offset encoding length
    const size_t N = 11;
        //@:encode strlen
    const size_t S = 3;
    
    std::string filename = "outfile"; //this is the encoded thing
    std::string original_name = "original";
    std::ofstream original;
    original.open(original_name);
    std::string outstr("");
    std::string window = str_to_binary(create_input_str(filename));
    //outstring index always points to front character
    size_t i = 0;
    size_t matchlen = 0;
    size_t slen = 0;
    size_t offset = 0;
    std::string s("1000000000000000");
    std::string s1("10000000");
    cout << get_offset(s,N) << endl;
    cout << get_len(s1,L) << endl;

    while (true){
        matchlen = get_len(window.substr(i,8),L);
        i += L;
        //Case1 there was a match
        if (matchlen >= 2){
            offset = get_offset(window.substr(i,16),N);
            i+= N;
            write_using_offset(matchlen,offset,window,original);
        }
        //Case2 there was not a match
        else{
            slen = get_len(window.substr(i,8),S);
            i+= S;
            if (slen == 0){
                //means we reached EOF token
                return;
            }





        }
    }
}


// Functions that are useful to decoding

//gets the length
//Recall that matchlen is always one greater tha
//what it was encoded in binary as
//so if it was 0 then its actually a 1
//thus only 2 or more indicate a match into the window
//can be used for match len or str len
///
//this function si called by both match len or str len
size_t get_len(std::string str, size_t T)
{
   std::bitset<8> B(str); 
   B =  B >> (8 - (T+1));
   return B.to_ullong() + 1;
}


//Assumes string passed in includes at least N letters
//Assume str starts at the first bit of N
size_t get_offset(std::string str,size_t N){
    std::bitset<16> B(str.substr(0,16));
    B = B >> (16- (N+1));
    cout << B << endl;
    return B.to_ullong();
}

size_t write_using_offset(size_t matchlen, size_t offset, std::string& window, ostream& out){
    //write to file as well as updating the window with new char
    size_t i = 0;
    unsigned char c;
    while (i < matchlen){
        c = window[offset + i];
        window.push_back(c);
        out << c;
        ++i;
    }
}

size_t write_using_slen(size_t slen, size_t &i , std::string& window, ostream& out){
    //valid bit is a bit that is part of a character
    size_t num_valid_bits = slen * 8;
    size_t num_ignore_bits = (slen + 1) * 8 - num_valid_bits;

}