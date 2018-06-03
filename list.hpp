
//TODO: See if we can get away with just using unsigned 
// int to reprsent indices in list nodes

//NOTE: a unsigned long supports values in range
//0 to 4,294,967,295
//1,029,744 bytes is biggest doc we deal with which 
//means we should have plenty of space
//later on we can change to int and see if it works better

//A listNode is the core component in a list. its primary 
//function is to store an index into the input buffer
struct listNode{
    private:
        ////@: index into the input buffer
        listNode* next;
        unsigned long index;
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
        int len;
    public:
        //@:n is the number of list nodes desired
        //#: inits a linked list of n listNodes. Each
        //#: each listNode will be point to null ptr
        list(int n);

        //#: deletes each node in the list
        ~list();

        //@:i is an integer reprsenting an index 
        //#:will create a new list node with key set to i
        //#:and insert it at the end of the list. tail
        //#:points to this new element. and len incremented by one 
        void insert(unsigned long i);

        void remove();
        //#:removes the listNode pointed to by head 
        //#:and makes head point to the next of the recently
        //#:deleted head. Deletes the recently removed node

        //@:matchindex
        //@:L is the match length 
        //#:search the entire list for the ListNode
        //#:whose index when scanend has the longest match
        //#:up to L.
        //#:returns the index of the ListNode that was found
        //#:as well as the length of the match
        unsigned long get_longest_match(unsigned long matchindex,int L);
};

//SECTION: Helper Functions

//This function helps get_longest_match
//@:matchindex
//@:L
//@:buf_index
//#:using brute force pattern matching, match as many characters
//#:as possible starting at matchindex+2 and buf_index+2 since
//#:these are assumed to have already been matched
//#:return the length of the match (include the two characters matched initially)
//#:thus lowest return value is 2
int matchindex(unsigned long match);
