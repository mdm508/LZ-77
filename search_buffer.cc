#include "search_buffer.hpp"
#include "math.h"

//?: how to ensure its not used outside of file

searchBuffer::searchBuffer(size_t N)
{
    //initialize empty lists in buf
    for (size_t i=0; i < BUF_SIZE; ++i)
        buf[i] = list();
    
    //set capacity
    buf_capacity = pow(2,N-3);
    listnode_count = 0;
}

    

//make a new node at list_index with id input_buf_index
void searchBuffer::insert(size_t list_index, size_t input_buf_index)
{
    //buf[list_index] returns list at index list_index
    buf[list_index].insert(input_buf_index);
}

void searchBuffer::remove(size_t list_index)
{
    buf[list_index].remove();
}

std::pair<size_t,size_t> searchBuffer::get_match( \
                       size_t list_index,\
                       size_t LAB_index,\
                       size_t max_match,\
                       const std::string& input_buf,\
                       size_t size_input_buf)
{
    return buf[list_index].get_longest_match( \
                            LAB_index,\
                            max_match,\
                            input_buf,\
                            size_input_buf);
}

//?: one life if statement?
//#: Returs true if the buf_capacity = listnode_count 
bool searchBuffer::atCapacity()
{
    if (listnode_count == buf_capacity)
        return true;
    else
        return false;
}


size_t searchBuffer::getCount()
{
    return listnode_count;
}


