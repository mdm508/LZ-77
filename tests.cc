//sandbox.cc
//this file is for playing around with idea and modules
#include <iostream>
#include <string>
#include "bits.hpp"
#include "list.hpp"

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


void print_list(list L){
    const listNode* temp = L.getHead();
    while (temp != nullptr){
        cout << temp->index << endl;
        temp = temp->next;
    }
}

int main(int argc, char** argv)
{
  //log(chr_to_binary('c'));   
  //log(strip_lead_zeros(s));
  //log(str_to_binary("cat house"));
  ///              0123456789
  std::string buf("AABAABBBBCABBBBBBD");
  size_t LAB_index = 10;
  size_t max_match = 5;

  list ll = list(); 
  //all matches ar for AB
  ll.insert(1); //match
  ll.insert(4);

  print_list(ll);

  return 0;
}
