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

a search buffer can do the following
-  represent the portion of the input thats visible
-  determine if a string is matched or not
-  load new stuff into the input stream
- kick old stuff out
- 



*/

#ifndef SEARCHBUFFER_HPP
#define SEARCHBUFFER_HPP
#include "list.hpp"

const size_t BUF_SIZE = 256 * 256;

class searchBuffer{
    private:
        //@:buf is the search buffer
        list buf[BUF_SIZE];

        //@:the maximum number of list nodes that
        //@:    buf can accomodate
        size_t buf_capacity;

        //@:tracks the total number of list nodes
        //@:    currently inside of buf
        size_t listnode_count;

    public:
        //#: Initalizes buf_capactiy to size W
        //to 2^{N-2} which is max number of nodes 
        //it can store
        //Initialize 256*256 lists
        searchBuffer(size_t N);

        //make a new node at list_index with id input_buf_index
        void insert(size_t list_index, size_t input_buf_index); 
        
        //removes the oldest value in the list at list_index
        void remove(size_t list_index);
        //
        //@:match_index 
        //@:L integer match_len 
        //#: try to find a match of two or greater the for the string 
        //#: on input[match_index,match_index + len]
        std::pair<size_t,size_t> get_match(         \
                                   size_t list_index,\
                                   size_t LAB_index,\
                                   size_t max_match,\
                                   const std::string& input_buf,\
                                   size_t size_input_buf);

        //#: Returs true if the buf_capacity = listnode_count 
        bool atCapacity();

        size_t getCount();


};

//SECTION: Helper Functions


#endif //SEARCHBUFFER_HPP
