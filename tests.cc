//sandbox.cc
//this file is for playing around with idea and modules
#include <iostream>
#include <string>
#include "bit_tools.hpp"
std::string E("error");

using namespace std;
void log(){}

//allows printing aribtrary items
template<typename First, typename ...Rest>
void log(First && first, Rest && ...rest)
{
    std::cout << std::forward<First>(first);
    std::cout << endl;
    log(std::forward<Rest>(rest)...);
} 


/*
void t_make_token_triple(){
}


void t_join2(){
    bitset<3> bA (string("000"));
    bitset<4> bB (string("1011"));
    bitset<4+3> AB(string("0001011"));
    bitset<4+3> ab = join2<3,4,4+3>(bA,bB); 
    if (ab != AB){
        cout << ab << endl;
        throw(E);
    }
}

void t_join3(){
    bitset<3> bA (string("111"));
    bitset<4> bB (string("0101"));
    bitset<2> bC (string("00"));
    bitset<9> AB(string("111010100"));
    bitset<9> ab = join3<3,4,2,9>(bA,bB,bC); 
    if (ab != AB){
        cout << ab << endl;
        throw(E);
    }
}



void t_slice(){
   //Section: Bitset Tests
    std::bitset<8> b (string("11110000"));
    //cout << b.size() << endl;
    bitset<4> b1 = slice<4,b.size()>(b,4,7);
   // /cout << b1 << endl;
}    

*/
void t_bset_to_chr(){
    bitset<8> bs (0x78);
    char c = bset_to_chr(bs);
    if (c != 'x'){
        log(c);
        throw(E) ;
    }
}

void t_chr_to_bset(){
    char c = 'x';
    bitset<8> b(0x78);
    if (chr_to_bset(c) != b ){
        log(chr_to_bset(c));
        throw(E);
    }
}


void t_bset_to_int(){
    bitset<16> b(0xA112);
    int d = bset_to_int(b);
    if (d != 41234){
        log(d);
        throw(E);
    }
}

void t_encode_eof(){
    const int L=3, S=3;
    const int theSum = L + S;
    bitset<theSum> b;
    //cout << b << endl;
    if (encode_eof<theSum>() != b){
        cout << "error encode_eof" << endl;
    }
}

void t_split2(){
    bitset<4+3> AB(string("0001011")); 
    bitset<4>a(string("0001"));
    bitset<3>b(string("011"));

    bitset<4> pA; 
    bitset<3> pB; 
    split2<4,3,4+3>(pA,pB,AB);
    if (pA != a || pB != b){
        log(pA,pB);
        throw(E);
    }
}

void t_split3(){
    bitset<4>a(string("0000")); 
    bitset<1>b(string("1"));
    bitset<5>c(string("10101"));
    bitset<10>abc(string("0000110101"));

    bitset<4> pA; 
    bitset<1> pB;
    bitset<5> pC;
    
    split3<4,1,5,10>(pA,pB,pC,abc);
    log(pA,pB,pC);
    if (pA != a || pB != b || pC != c){
        log(pA,pB,pC);
        throw(E);
    }
}

void t_make_token_double(){
    const unsigned int N=5;
    const unsigned int L=4;
    unsigned int matchlen = 3;
    unsigned int offset = 10;
    std::bitset<N+L> b = make_token_double<L,N,(N+L)>(matchlen,offset);
    //instead of encoding offset as 10 we do encode 10-1 aka 9
    std::bitset<9>expB (string("001101001"));
    if (b != expB){
        log(b,"expected",expB);
        throw(E);
    }
}

void test_bit_tools(){
    //t_bset_to_chr();
    //t_chr_to_bset();
    //t_bset_to_int();
    //t_split2();
    //t_join2();
 //   t_join3();
     /*
    //t_encode_eof();
    t_make_token_double();
    t_make_token_triple();
    t_split3();
    */
}


int main(int argc, char** argv)
{
//t_split2();
//    t_split3();
    //t_encode_eof();
//    t_make_token_double();
    tokenTriple t = tokenTriple(S,"cat");
    t.updateTriple("s");
    bitset<LSB> b =  make_token_triple<L,S,B,LSB>(t);
    cout << b << endl;
    
    return 0;
}
