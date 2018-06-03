/*
The search-buffer is an array of linkedlists. The search buffer has size
W,where,                 W=2^{N} / 8
denoting the highest number of bytes that can be stored.

Each linked list corresponds to a 16 digit bstr. Note that 
the higher 8 bits and lower 8 bits are two different characters
so 0xXXYY constitute character corresponding to the byte XX in range 0 to 255
and symetrically for YY

we will use the integer representation of 0xXXYY to index the bufferthus each
16 bit seq gets a unique spot in the search bufffer. 

*/

#ifndef SEARCHBUFFER_HPP
#define SEARCHBUFFER_HPP
#include "list.hpp"
#include <bitset>


class searchBuffer{
    private:
        //@:buf is the search buffer
        list buf;

        //@:the maximum number of list nodes that
        //@:    buf can accomodate
        unsigned int buf_capacity;

        //@:tracks the total number of list nodes
        //@:    currently inside of buf
        unsigned long listnode_count;

    public:
        //#: Initalizes buf to size W, where
        //#: W = 2^{N} / 8 since this nummber represents
        //#: number of bytes that the window spans
        //#: Create W lists in each of the positions 
        searchBuffer(unsigned int N);

        //@:bstr denotes a 16 bit binary set where
        //@:the lower and upper half reprsent two 
        list* getList(std::bitset<16> bstr);
        
        //@:match_index 
        //@:L integer match_len 
        //#: try to find a match of two or greater the for the string 
        //#: on input[match_index,match_index + len]
        unsigned long get_match(unsigned long match_index, unsigned int L);

        //#: Returs true if the buf_capacity = listnode_count 
        bool atCapacity();


};

//SECTION: Helper Functions

//?:I cant think why we would need this? Delete ??
//matchindex_to_str
//@:match_index
//@:L integer
//#:convert match_index to 
//#: to a str of length L 

#endif //SEARCHBUFFER_HPP