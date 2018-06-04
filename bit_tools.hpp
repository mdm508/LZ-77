//bit_tools.hpp
//Because of the use of template funciton
//I have put definitions in .h
#include <bitset>
#include <vector>
#include <string>
#include "token_triple.hpp"
#ifndef bittools_hpp
#define bittools_hpp

//@:bset is a binary str of 8 bits long
//#:convert bset into its character representation 
char bset_to_chr(std::bitset<8> bstr){
    return bstr.to_ulong();
}

//@:chr is a character literal
//#:convert chr to its 8 bit binary representation
std::bitset<8> chr_to_bset(char chr){
    return std::bitset<8>(chr);
}

//@:bset is a 16 bit binary set representing an index into search buf
//#:convert bset into its intger representation
unsigned int bset_to_int(std::bitset<16> bset){
    return bset.to_ulong();
}

//Implicit Parameters
//@:sizeJoin the size of the joined bit set
//@:sizeA the size of bitsetA
//@:sizeB the size of bitset B
//Paramaters
//@:bsetA
//@:bsetB
//#: returns a new bitset where bsetB is appened
//#: to the end of bsetA 
template <size_t sizeA, size_t sizeB, size_t sizeAB>
std::bitset<sizeAB> join2(std::bitset<sizeA> bsetA, std::bitset<sizeB> bsetB){
    return std::bitset<sizeAB>(bsetA.to_string() + bsetB.to_string());
}

//Implicit Parameters
//@:sizeA,sizeB,sizeC,sizeABC 
//Paramaters
//@:bsetA,bsetB,bsetC
//#: returns new bset of the form bsetA bsetB bsetC
//#: no spaces in between. New bitset as size A + B + C
template <size_t sizeA, size_t sizeB,size_t sizeC,size_t sizeABC>
std::bitset<sizeABC> join3(std::bitset<sizeA> bsetA,\
                           std::bitset<sizeB> bsetB,\
                           std::bitset<sizeC> bsetC)
{
    return std::bitset<sizeABC>(bsetA.to_string() + \
                                bsetB.to_string() + \
                                bsetC.to_string());
 }

//@: pA is a pointer to a biset of sizeA
//@: pB is a pointer to a biset of sizeB
//@: bset is a bitset of sizeAB that will be split
//#:copies A high order bits and stores in pA
//#: and stores remaining bits in pB
template <size_t sizeA, size_t sizeB, size_t sizeAB>
void split2(std::bitset<sizeA>* pA,\
            std::bitset<sizeB>* pB,
            std::bitset<sizeAB> bset);

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
template <size_t sizeA, size_t sizeB, size_t sizeC, size_t sizeABC>
void split3(std::bitset<sizeA>* pA,\
            std::bitset<sizeB>* pB,\
            std::bitset<sizeC>* pC,\
            std::bitset<sizeABC> bset);


//Paramaters L,S are implicit. They are passed into size
//@:L is nuumber of bits to use in the encoding of (0)
//@:S is number of bits to use in encoding (0)
//#:produces a special pair (0,0) which denotes the end of file
//#:the binary str produced will be of length L + S
template <size_t size>
std::bitset<size> encode_eof();

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
std::bitset<size> make_token_double( \
                                    unsigned int L,\
                                    unsigned int matchlen,\
                                    unsigned int N,\
                                    unsigned long offsetindex);


//@:token_triple is a tokenTriple that holds the data neccessary
//@:    to construct a token triple
//#:encodes a triple of the form (code,strlen,chars) pair
//#: get a L + S + len(str) binary/char str 
template <size_t size>
std::bitset<size> make_token_triple(tokenTriple token_triple);


//@:bset is the bitset to be slicesk
//@:L is is the starting left most index
//@:U is the ending right most index
//#: returns a subset of the bitset between [i,j]
template<size_t sizeA,size_t sizeB>
std::bitset<sizeA> slice(std::bitset<sizeB> bset,\
                         unsigned int L, unsigned int U)
{
    if (U-L+1 != sizeA){
        throw("Error in slice, incorrect slice size");
    }

    std::bitset<sizeA> new_bset;
    unsigned int new_bset_index = 0;
    for (int i = L; i <= U; ++i){
        new_bset[new_bset_index] = bset[i];
    }
    return new_bset;
}


//DELETE MAYBE??
/*
//? not sure if this one is needed 
template <size_t size>
std::bitset<size> int_to_bset(unsigned int i);
//@:i is the integer to be transformed into a bset
//#:transform offset_len into its bit representation  
*/
#endif //