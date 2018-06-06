#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <fstream>
#include <bitset>
#include "bits.hpp"
#include "misc.hpp"
using namespace std;

//function delcarations
size_t get_len(std::string str, size_t L);
size_t get_offset(std::string str,size_t N);

size_t get_slen(std::string str, size_t S);

void write_using_offset(size_t matchlen, size_t offset, std::string& window, ostream& out);

void write_using_slen(size_t num_valid_bits,std::string str,
                                    std::string& window,
                                    ostream& out);

//TODO: am i managing OSI correctly does it correspond to encoding?
//TODO: fix any mix ups between window and buf
int main(){
    const size_t L = 4;
        //@:offset encoding length
    const size_t N = 11;
        //@:encode strlen
    const size_t S = 3;
    
    std::string filename = "book"; //this is the encoded thing
    std::string original_name = "book_decompressed";
    std::ofstream original;
    original.open(original_name);
    //WINDOW IS A REPRESENTATION OF THE WINDOW THAT IS BEING CONSTRUCTED
    //BY THE DECODER
    std::string window("");

    //BUF IS THE SHORT FOR INPUT BUFFER ITS A REPRESENTATION OF FILE
    //AS A STRING
    std::string buf = str_to_binary(create_input_str(filename));
    
    ////////////
    //Bookeeping variables
    size_t i = 0; // index into the buffer
    size_t matchlen = 0; //var stores matchlens read
    size_t slen = 0; //var stores str lens read
    size_t offset = 0; //var stores offsets read
    std::string tstr; 
    //TODO REMOVE MAX CYCLE
    size_t max_cycle = 10*10*10*10;
    size_t count = 0;
    cout <<"yo" << endl;
    cout << buf << endl;

    //testing for decode functions
    
    
    while (count++ < max_cycle){
        cout << i << endl;
        cout << "get_len called by match" << endl;
        matchlen = get_len(buf.substr(i,8),L);
        i += L;
        cout << "adding L to i" << i << endl;
        //Case1 there was a match
        if (matchlen >= 2){
            offset = get_offset(buf.substr(i,16),N);
            i+= N;
            cout << "adding N to i: " << i << endl;
            write_using_offset(matchlen,offset,buf,original);
        }
        //Case2 there was not a match
        else{
            slen = get_slen(buf.substr(i,8),S);
            cout << slen << endl;
            i+= S;
            cout << "adding S to i " << i << endl;
            //Case 3 EOF exit
            if (slen == 0){
                //means we reached EOF token
                return 0;
            }
            else{
                //Determine which indices contain valid bits
                //valid bit is a bit that is part of a character
                size_t num_valid_bits = slen * 8;
                tstr = buf.substr(i,num_valid_bits);
                write_using_slen(num_valid_bits,tstr,window,original);
                i += num_valid_bits;
               cout << "shifting i to next valid index " << i << endl;
            }

        }
    }
        cout << "Broke out casue of max cycles" << endl;
        
}


// Functions that are useful to decoding

//gets the length
//Recall that matchlen is always one greater tha
//what it was encoded in binary as
//so if it was 0 then its actually a 1
//thus only 2 or more indicate a match into the buf
//can be used for match len or str len
///
size_t get_len(std::string str, size_t L)
{
   cout << str << endl << endl;
   std::bitset<8> B(str); 
   cout << B << endl << endl;
   B =  B >> (8 - L);
   cout << "made it" << endl;
   cout << B << endl << endl;
   return B.to_ullong() + 1;
}

size_t get_slen(std::string str, size_t S)
{
    cout << "get_slen called" << endl;
   cout << str << endl << endl;
   std::bitset<8> B(str); 
   cout << B << endl << endl;
   cout << "value of shift " << (8 - S) << endl;
   B =  B >> (8 - S);
   cout << "made it" << endl;
   cout << B << endl << endl;
   return B.to_ullong();
}



//Assumes string passed in includes at least N letters
//Assume str starts at the first bit of N
size_t get_offset(std::string str,size_t N){
   cout << "get_offset" << endl;
    std::bitset<16> B(str.substr(0,16));
    B = B >> (16- (N+1));
   cout << "made it" << endl;
    return B.to_ullong();
}

void write_using_offset(size_t matchlen, size_t offset, std::string& window, ostream& out){
    //write to file as well as updating the buf with new char
    //we grab offset into the window and append them to the end of the window
    //Also writes to the file each char
    cout << "write using off set called" << endl;
    size_t i = 0;
    unsigned char c;
    while (i < matchlen){
        c = window[offset + i];
        window.push_back(c);
        out << c;
        ++i;
    }
    cout << "made it out" << endl;
}

void write_using_slen(size_t num_valid_bits,std::string str,
                                    std::string& window,
                                    ostream& out){
    unsigned char c;
    std::bitset<8> B;
    cout << "write using slen called" << endl;
    for (size_t i = 0 ; i < num_valid_bits; i+=8){
        B = std::bitset<8>(str.substr(i,8));
        c = B.to_ullong();
        cout << c << endl;
        window.push_back(c);
        out << c;
    }
    cout << "made it out" << endl;

}
