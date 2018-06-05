//sandbox.cc
//this file is for playing around with idea and modules
#include <iostream>
#include <string>
#include <fstream>
#include "bits.hpp"
#include "list.hpp"
#include "search_buffer.hpp"
#include "cody.hpp"

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
  size_t li = 0;
  size_t low = 0;
  Cody c = Cody(li,low,"example.txt");
  c.write("100001");
  c.write("0000001");
  c.closeFile();

  return 0;
}
