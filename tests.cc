//sandbox.cc
//this file is for playing around with idea and modules
#include <iostream>
#include <string>
#include "bits.hpp"

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




int main(int argc, char** argv)
{
  //log(chr_to_binary('c'));   
  //log(strip_lead_zeros(s));
  //log(str_to_binary("cat house"));
  //dd
    int S = 3, L = 5;
    string s("cat time");
    tokenTriple t(S,s);
    log(make_token_triple(t,L,S));
    log(str_to_binary(s));
  
  return 0;
}
