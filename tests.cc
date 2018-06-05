//sandbox.cc
//this file is for playing around with idea and modules
#include <iostream>
#include <string>
#include "bits.hpp"
#include "list.hpp"
#include "search_buffer.hpp"

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


void print_list( const list& L){
    const listNode* temp = L.getHead();
    std::cout << "printing" <<  std::endl;
    while (temp != nullptr){
        cout << temp->index << endl;
        temp = temp->next;
    }
    std::cout << "done printing" <<  std::endl << std::endl;
}

int main(int argc, char** argv)
{
  //log(chr_to_binary('c'));   
  //log(strip_lead_zeros(s));
  //log(str_to_binary("cat house"));
  ///              0123456789
  std::string buf("AABAABBBBCABBBBBBD");
  size_t LAB_index = 10;
  size_t max_match = 4;
  size_t N = 5;
  searchBuffer s(N);

  /*
  list ll; 
  //all matches ar for AB
  ll.insert(1); //match
  ll.insert(4);
  print_list(ll);
  std::pair<size_t,size_t> p;
  p = ll.get_longest_match(LAB_index,\
                            max_match,\
                            buf,\
                            buf.length());
  log(p.first,p.second);
  log(buf[p.first]);
  */

  return 0;
}
