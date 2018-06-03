//sandbox.cc
//this file is for playing around with idea and modules
#include <iostream>
#include <string>

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

template<int i>
void modify(){ 
    std::cout << "modify<"<<i<<">"<< std::endl;
}

int main(int argc, char** argv)
{
    /*
    Section: Reading and writing 
    reading and writing files example
    cout << "You have entered " << argc
         << " arguments:" << "\n";
 
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";
    */
   //Section: Bitset 
   std::bitset<8> s ('%');
   unsigned char c = s.to_ulong();
   log(c);
   //log(s1&s2);
    char b = 'a';
   string str(1, b); 
   std::cout << str << std::endl;



    return 0;
}