#include "list.hpp"
#include <iostream>

list::list()
{
    head = nullptr;
    tail = nullptr;
    len = 0;
}

//TODO: implement this make sure it isnt invoked for now

list::list(list& that)
{
    std::cout << "invoked CC" << std::endl;
    
}

list& list::operator=(const list& that)
{
    std::cout << "invoked AC" << std::endl;
//    if (this != & that){ 
        this->~list();
        this->head = that.head;
        this->tail = that.tail;
        this->len = that.len;
        return *this;
 //   }
}

list::~list()
{
    listNode* temp = head ;
//    std::cout << "____" << std::endl;
    while (temp != nullptr){
        listNode* node = temp->next;
        std::cout << temp->index << std::endl;
        delete temp;
        temp = node;
    }
    head = nullptr;
}

void list::insert(size_t i){
    if (head == nullptr){
        head = new listNode{nullptr,i};
        tail = head;
        ++len;
    }
    else{
        listNode* new_node = new listNode{nullptr,i};
        tail->next = new_node;
        tail = new_node;
    }
}

void list::remove()
{
    if (head != nullptr){
        listNode* new_head = head->next;
        delete head;
        head = new_head;
        --len;
    }
}

const listNode* list::getHead() const
{
    return head;
}

std::pair<size_t,size_t> list::get_longest_match(size_t LAB_index,\
                                   size_t max_match,\
                                   const std::string& input_buf, \
                                   size_t buf_size)
{
    std::pair<size_t,size_t> match_pair(0,0), canidate_match;
    //Case1 no match
    if (head == nullptr)
        return match_pair;
    listNode* temp = head;
    while (temp != nullptr){
        canidate_match = matchindex(temp->index,\
                                   LAB_index,\
                                   max_match,\
                                   input_buf,\
                                   buf_size);

        if (canidate_match.second > match_pair.second)
            match_pair = canidate_match;
        temp = temp->next;
    }
    return match_pair;
}

//SECTION: Helper Functions

std::pair<size_t,size_t> matchindex(size_t index,\
          size_t buf_index,\
          size_t max_match,\
          const std::string& input_buf,\
          size_t buf_size)
{
    //the fact that this function calls mean there was at least
    //a match length of two so we adjust indices accordingly
    size_t matchlength = 2;
    size_t i = index + 2;
    size_t bi = buf_index + 2;
    while (matchlength < max_match && bi < buf_size){
        if (input_buf[i++] == input_buf[bi++])
            ++matchlength;
        else
            break;
    }
    std::pair<size_t,size_t> match_pair(index,matchlength);
    return match_pair;
}
