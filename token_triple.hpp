//
#include <string>
#ifndef TOKENTRIPLE_HPP
#define TOKENTRIPLE_HPP

class tokenTriple {
    private:
        //@:num bits to encode offset
        int L;
        //@:num bits to encode strlen
        int S;
        //@:set to 2^(S) - 1
        //@:denotes max str size in triple
        int max_strlen;
        //@: the current string
        std::string str;

    public:
        tokenTriple(int L, int S,std::string s);
        //@:a string to add to the triples string
        //#:concatenate s onto the end of str
        void updateTriple(std::string s);
        //#: returns str
        std::string getString();
        //#: if no more characters can be added to str
        //#: returns true
        bool isFull();
        //#:return true if str
        bool hasCapacity(std::string s);
};

#endif //TOKENTRIPLE_HPP


    

