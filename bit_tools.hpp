#include <bitset>
#include <vector>
#include <string>
#include "token_triple.hpp"

#ifndef bittools_hpp
#define bittools_hpp
char bset_to_chr(std::bitset<8> bstr);
//@:bset is a binary str of 8 bits long
//#:convert bset into its character representation 

std::bitset<8> chr_to_bset(char chr);
//@:chr is a character literal
//#:convert chr to its 8 bit binary representation

//! replaced encode_offset_with more general function
//? not sure if this one is needed 
template <size_t size>
std::bitset<size> int_to_bset(unsigned int i);
//@:i is the integer to be transformed into a bset
//#:transform offset_len into its bit representation  

unsigned int bset_to_int(std::bitset<16> bset);
//@:bset is a 16 bit binary set representing an index into search buf
//#:convert bset into its intger representation


template <size_t sizeA, size_t sizeB, size_t sizeAB>
std::bitset<sizeAB> join2(std::bitset<sizeA> bsetA,\
                           std::bitset<sizeB> bsetB);
//Implicit Parameters
//@:sizeJoin the size of the joined bit set
//@:sizeA the size of bitsetA
//@:sizeB the size of bitset B
//Paramaters
//@:bsetA
//@:bsetB
//#: returns a new bitset where bsetB is appened
//#: to the end of bsetA 


template <size_t sizeA, size_t sizeB,size_t sizeC,size_t sizeABC>
std::bitset<sizeABC> join3(std::bitset<sizeA> bsetA,\
                           std::bitset<sizeB> bsetB,\
                           std::bitset<sizeC> bsetC);
//Implicit Parameters
//@:sizeA,sizeB,sizeC,sizeABC 
//Paramaters
//@:bsetA,bsetB,bsetC
//#: returns new bset of the form bsetA bsetB bsetC
//#: no spaces in between. New bitset as size A + B + C

template <size_t sizeA, size_t sizeB, size_t sizeAB>
void split2(std::bitset<sizeA>* pA,\
            std::bitset<sizeB>* pB,
            std::bitset<sizeAB> bset);
//@: pA is a pointer to a biset of sizeA
//@: pB is a pointer to a biset of sizeB
//@: bset is a bitset of sizeAB that will be split
//#:copies A high order bits and stores in pA
//#: and stores remaining bits in pB
 
template <size_t sizeA, size_t sizeB, size_t sizeC, size_t sizeABC>
void split3(std::bitset<sizeA>* pA,\
            std::bitset<sizeB>* pB,\
            std::bitset<sizeC>* pC,\
            std::bitset<sizeABC> bset);
//Implicit Paramaters
//@:sizeA,sizeB,sizeC,sizeABC
//Paramaters
//@: pA is a pointer to a biset of sizeA
//@: pB is a pointer to a biset of sizeB
//@: pC is a pointer to a biset of sizeC
//@: bset is a bitset of sizeABC that will be split
//#:copies A high order bits and stores in pA
//#:copies next highest remaining B bits stores in pB
//#:copies reamining C bits and stores in pC
//#:In effect bset is split into three new bit sets

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
                                        unsigned int L,\
                                        unsigned int matchlen,\
                                        unsigned int N,\
                                        unsigned long offsetindex);

//Paramaets N,L are implicit. They are passed into size
//@:L number of bits to use in encoding match
//@:match is int specifying length of the match
//@:N number of bits to use in encoding offset
//@:offset is int specifying offset into the window
//@: with respect to current window configuration
//#: return N + L bit binary string of emulating (len,offset)
//#: recall that if len = i then binary string to represnt i
//#: will be actually representing i-1. If len = 1 then 0001 would be
//#: the representation

template <size_t size>
std::bitset<size> make_token_triple(tokenTriple token_triple);
//@:token_triple is a tokenTriple that holds the data neccessary
//@:    to construct a token triple
//#:encodes a triple of the form (code,strlen,chars) pair
//#: get a L + S + len(str) binary/char str 


//todo: implement output token triple vector
//@:token_triple is the token triple to be output
//#:encodes the triple token and outputs it
//#:to standard output

#endif //