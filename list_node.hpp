/*
list_node.txt
a ListNode is the core component in a list. its primary 
function is to store an index into the input buffer
*/

struct listNode{
    private:
        //@: index into the input buffer
        listNode* next;
        int index;
};

