#include <bitset>
#include <string>
#include "token_triple.hpp"


template <size_t size>
char bset_to_chr(std::bitset<size> bstr);
//@:bset is a binary str of 8 bits long
//#:convert bset into its character representation 

template <size_t size>
std::bitset<size> chr_to_bset(char chr);
//@:chr is a character literal
//#:convert chr to its 8 bit binary representation

//! replaced encode_offset_with more general function
template <size_t size>
std::bitset<size> int_to_bset(int I);
//@:I is the integer to be transformed into a bset
//#:transform offset_len into its bit representation  

//! special case of int_to_bset
//encode_matchlen
//@:match_len an integer representing match length
//@:L number of bits to use in encoding 
//#:transform match_len to bit representation of (match_len - 1)

//! special case of int_
//encode_strlen
//@:str_len is an integer representing length of unmatched characters
//@:S is the number of bits to use in encoding, (longest match is 2^(S) - 1)

//encode_eof
template <size_t size>
std::bitset<size> encode_eof();
//Paramaters L,S are implicit. They are passed into size
//@:L is nuumber of bits to use in the encoding of (0)
//@:S is number of bits to use in encoding (0)
//#:produces a special pair (0,0) which denotes the end of file
//#:the binary str produced will be of length L + S
 
//! join bits removed and replaced 
template <size_t size>
std::bitset<size> make_token_double( \
                                        int L,\
                                        int match,\
                                        int N,\
                                        int offset);

//Paramaets N,L are implicit. They are passed into size
//@:L number of bits to use in encoding match
//@:match is int specifying length of the match
//@:N number of bits to use in encoding offset
//@:offset is int specifying offset into the window
//#: return N + L bit binary string of emulating (len,offset)


//! use token_triple vector now
//instead of encode triple vector
//@:bit_code_len is an L bit binary represntation of 0
//@:bit_str_len: is an S bit string denonting the number of characters 
//@: that were not matched in the look ahead buffer. (usally 1)
//@:str is a string literal of up to S characters terminated by null character
//#:join bit_code_len,bit_str_len, and str to emulate (code,strlen,chars) pair
//#: get a L + S + len(str) binary/char str 


//todo: implement output token triple vector
//@:token_triple is the token triple to be output
//#:encodes the triple token and outputs it
//#:to standard output
