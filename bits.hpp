#ifndef BITS_HPP
#define BITS_HPP
#include <string>
#include "bits.hpp"
#include "token_triple.hpp"

//TODO: add sections for readability 


//removes all leading zeros from s
std::string strip_lead_zeros(std::string s);

//#: Converts a character into its binary representation
//as a string. 
std::string chr_to_binary(char c,bool remove_lead_zeros);

//# takes a string and converts it to its
//binary representation as a string
std::string str_to_binary(std::string s);

//# take 2 char string and convert it to the integral
//representation
size_t chrs_to_number(char c1, char c2);

//@: x is desired length of string
//#: make a zero string of size x
std::string make_zero_string(unsigned int x);

//@:s is the string to be padded
//@:total is the desired total length of str
//#:pads s with as many zeros as neccessary so
//that s's total lenth equal total
//left specifies whether to bad left or right true for yes fales for no
std::string pad_string(std::string s,unsigned int total,bool left);
    

//FUNCTIONS USEFUL TO ENCODING

//@:L is number of bits to encode matchlen
//@:S is number of str literals that can be
//be represented in a non match
//#:encodes a token of the form (code,strlen)
//where both code and strlen are zero in binary
//returns string of total length L + S
std::string make_token_eof(size_t L, size_t S);

//@:L number of bits to encode match size 
//@:N number of bits to encode offset index
//@:matchlen is length of the match found
//@:offsetindex
//#:returns an encoding of (len,offset) pair
//#:both len and offset represented in binary 
//NOTE that if matchlen = j we reprsent it
//as j-1 in binary
std::string make_token_double(size_t L, \
                              size_t N, \
                              size_t matchlen,\
                              size_t offsetindex);

//L,S are same as before
//#: t is a token triple that will be encodes
//
//to give a triple of the form (code,strlen,chars)
//where code is L bit binary rep of 0,
//strlen is #of chars being encoded
//chars is an encoding of strlen chars
std::string make_token_triple(std::string chars,\
                              size_t L,\
                              size_t S,
                              size_t num_chars);

#endif
