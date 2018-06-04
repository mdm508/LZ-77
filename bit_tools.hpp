//TODO: implement a read function that takes a binary string
//and reads the characters. 

//bit_tools.hpp
//Because of the use of template funciton
//I have put definitions in .h

#ifndef bittools_hpp
#define bittools_hpp

#include <bitset>
#include <ostream>
#include <vector>
#include <string>
#include "token_triple.hpp"

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
        new_bset_index++;
    }
    return new_bset;
}

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

//@:sizeA specifies the size of the bitset being copied into
//@:bset is the bitset being copied into
//@:c is the character that will be copied into bset
//@:index tells us where to start copying c into, we proceed
//@: from there to the next 7 higher indices
//#: copy c into bset starting at index and moving to righ
template<size_t size>
void copy_char(std::bitset<size>& bset, char c, size_t index)
{
    std::bitset<8> chr = chr_to_bset(c);
    size_t U = index + 7, chr_index = 0;
    for (; index <= U; ++index){
        bset[index] = chr[chr_index++];
    }
}

//@:size will be how large bset will be
//@: size will always be 8*strleng
//@:str is the string being converted to a bset
//#: result is a binary representation of the string
//#: note that the string will be stored in what is
//#:equiv of left to right. so cat is stored as
//#:[binary(t),binary(a),binary(c)]
template<size_t size>
std::bitset<size> str_to_bset(std::string str)
{
    std::bitset<size> bset;
    size_t i = 0, str_index = 0;
    for ( ; i < size; i+= 8){
        copy_char<size>(bset,str[str_index++],i);
    }
    return bset;
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

//@: A is bitset 
//@: B is bitset 
//@: bset is a bitset of sizeAB that will be split
//#:sizeA highest bit of bset copied into A
//#:sizeB low bits copied into B
template <size_t sizeA, size_t sizeB, size_t sizeAB>
void split2(std::bitset<sizeA>& A,\
            std::bitset<sizeB>& B,
            std::bitset<sizeAB> bset)
{
    size_t L,U;
    //Set B indices
    L = 0; U = sizeB - 1;
    B = slice<sizeB,sizeAB>(bset,L,U);
    //Set A indices
    L = U + 1; U = L + sizeA - 1;
    A = slice<sizeA,sizeAB>(bset,L,U);
}

//Paramaters
//@: A,B,C are all bit sets
//@: bset is a bitset of sizeABC that will be split
//#:copies A high order bits and stores in A
//#:copies next highest remaining sizeB bits stores in B
//#:copies reamining low order bits and stores in C
//#:In effect bset is split into three new bit sets
template <size_t sizeA, size_t sizeB, size_t sizeC, size_t sizeABC>
void split3(std::bitset<sizeA>& A,\
            std::bitset<sizeB>& B,\
            std::bitset<sizeC>& C,\
            std::bitset<sizeABC> bset)
{
    size_t L,U;
    //Set C indices
    L = 0; U = sizeC - 1;
    C = slice<sizeC,sizeABC>(bset,L,U);
    //Set B indices
    L = U + 1; U = L + sizeB - 1;
    B = slice<sizeB,sizeABC>(bset,L,U);
    //Set A indices
    L = U + 1; U = L + sizeA - 1;
    A = slice<sizeA,sizeABC>(bset,L,U);
}


//Paramaters L,S are implicit. They are passed into size as a sum
//@:L is nuumber of bits to use in the encoding of (0)
//@:S is number of bits to use in encoding (0)
//#:produces a special pair (0,0) which denotes the end of file
//#:the binary str produced will be of length L + S
template <size_t sizeLS>
std::bitset<sizeLS> encode_eof()
{
   return std::bitset<sizeLS>();

}

//Paramaets N,L are implicit. They are passed into size
//@:L number of bits to use in encoding match
//@:match is int specifying length of the match
//@:N number of bits to use in encoding offset
//@:offset is int specifying offset into the window
//@: with respect to current window configuration
//#: return N + L bit binary string of emulating (len,offset)
//#: recall that if matchlen = i then binary string to represnt i
//#: will be actually representing i-1. If matchlen = 2 then 0001 would be
//#: the representation
template <size_t L,size_t N, size_t LN>
std::bitset<LN> make_token_double( \
                                    size_t matchlen,\
                                    size_t offsetindex)
{
    std::bitset<LN> bset;
    std::bitset<L> Lset(matchlen);
    std::bitset<N> Nset(offsetindex - 1);
    bset = join2<L,N,LN>(Lset,Nset);
    return bset;
}

//@:L is number of bits to use when encoding mathc (note L is going to be 0 here)
//@:S is number of bits to use to encode length of str literal
//@:B is the number of bytes required to represent the string
//@:LSB is the sum of L S B (the total bits needed for the bitset)
//@:token_triple is a tokenTriple that holds the data neccessary
//@:    to construct a token triple
//#:encodes a triple of the form (code,strlen,chars) pair
//#: get a L + S + len(str) binary/char str 
//Assume: that token_triple holds a valid string
template <size_t L, size_t S, size_t B, size_t LSB>
std::bitset<LSB> make_token_triple(tokenTriple token_triple)
{
    std::bitset<L> L_bset;
    std::bitset<S> S_bset(token_triple.getString().length());  
    std::bitset<B> str_bset = str_to_bset<B>(token_triple.getString());
    return join3<L,S,B,LSB>(L_bset,S_bset,str_bset);

}

#endif //
