//
#ifndef TOKENTRIPLE_HPP
#define TOKENTRIPLE_HPP
#include <string>
#include <stddef.h>

class tokenTriple {
    private:
        //@:set to 2^(S) - 1
        //@:denotes max str size in triple
        size_t max_strlen;
       
        //@: the current string
        std::string str;
    public:
        //@:a string to add to the triples string
        //#:concatenate s onto the end of str
        tokenTriple(size_t S,std::string s);

        //returns the empty string if 
        // after adding s to str the len(str)
        // was still under the capacity
        // otherwise it slices of the first
        // capcacity characters, returns that string
        // and sets str to the remainder
        std::string updateTriple(std::string s);

        //resets the triple to the emptry string
        void reset();

            
        ////////////////////// 
        //SECTION: Get Methods
        ////////////////////// 
        
        std::string getString();
        size_t getMaxStrLength();
        
        /////////////////////////////
        //SECTION: True/False Methods
        /////////////////////////////
        
        //#: if no more characters can be added to str
        //#: returns true
        bool hasCapacity(std::string s);

        //#: true if s is the emptry string
        bool isEmpty();
};

#endif //TOKENTRIPLE_HPP


    

