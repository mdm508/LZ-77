#include "list.hpp"
#include <iostream>

list::list()
{
    head = nullptr;
    tail = nullptr;
    len = 0;
}

list::~list()
{
    listNode* temp = head;
    std::cout << "____" << std::endl;
    std::cout << temp->index << std::endl;
    while (temp != nullptr){
        listNode* node = temp;
        temp = temp->next;
    //    std::cout << temp->next->index << std::endl;
        delete node;
    }
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

const listNode* list::getHead()
{
    return head;
}

std::pair<size_t,size_t> list::get_longest_match(size_t LAB_index,\
                                           size_t max_match,\
                                           const std::string& \
                                           input_buf)
{
    std::pair<size_t,size_t> match_pair(0,0), canidate_match;
    //Case1 no match
    if (head == nullptr)
        return match_pair;
    listNode* temp = head;
    while (temp != nullptr){
        canidate_match = matchindex(temp->index,\
                            LAB_index,max_match,input_buf);
        if (canidate_match.second > match_pair.second)
            match_pair = canidate_match;
        temp = temp->next;
    }
    return match_pair;
}

//SECTION: Helper Functions

std::pair<size_t,size_t> matchindex(size_t index,\
          size_t LAB_index,size_t max_match, const std::string& input_buf)
{
    std::pair<size_t,size_t> match_pair;
    size_t matchlength = 2;
    while (matchlength < max_match){
        if (input_buf[index] == input_buf[LAB_index]){
            ++matchlength;
            ++index;
            ++LAB_index;
        }
        else
            break;
    }
    match_pair = std::make_pair(index,matchlength);
    return match_pair;
}
