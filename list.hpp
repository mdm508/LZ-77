//list.hpp
#ifndef LIST_HPP
#define LIST_HPP
#include <stddef.h> //for size_t
#include <utility> //for std::pair
#include <string>

//A listNode is the core component in a list. its primary 
//function is to store an index into the input buffer
struct listNode{
        ////@: index into the input buffer
        listNode* next;
        size_t index;
};

//A list is a linked list composed of listNodes. It will be used by search buffer
//for to track all the occurences of character sequences

class list{
    private:
        //@:tail a pointer to listNode that is the tail of the list
        listNode* tail;
        //@:head a pointer to a listNode that is the head of the list
        listNode* head;
        //@:len is number of listNodes in the list
        size_t len;
    public:
        //#: inits list with head and tail pointing to null
        list( );

        //#: deletes each node in the list
        ~list();


        //@:i is an integer reprsenting an index 
        //#:will create a new list node with key set to i
        //#:and insert it at the end of the list. tail
        //#:points to this new element. and len incremented by one 
        void insert(size_t i);

        //#:removes the listNode pointed to by head 
        //#:and makes head point to the next of the recently
        //#:deleted head. Deletes the recently removed node
        void remove();

        //returns the list node pointed to by head
        const listNode* getHead();
        
        //@:LAB_index is the index where match begins in the LAB
        //@:L is the match length 
        //@:input_buf& is a reference to the input string buffer
        //
        //#:search the entire list for the ListNode
        //#:whose index when scanend has the longest match
        //#:up to L.
        //#:returns a pair where first entry is match index 
        //and the second is the length of the match
        //return a pair (0,0) if no match found
        std::pair<size_t,size_t> get_longest_match(size_t LAB_index,\
                                            size_t max_match,\
                                            const std::string& input_buf);

                                                 
};

//SECTION: Helper Functions

//This function helps get_longest_match
//@:index specifies the index of the start of the match in the list
//@:L
//@:buf_index
//
//#:using brute force pattern matching, match as many characters
//#:as possible starting at matchindex+2 and buf_index+2 since
//#:these are assumed to have already been matched
//#:return the length of the match (include the two characters matched initially)
//#:thus lowest return value is 2
std::pair<size_t,size_t>  matchindex(size_t index,\
                   size_t LAB_index, size_t max_match,\
                   const std::string& input_buf);

#endif
