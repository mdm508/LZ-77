//
#ifndef TOKENTRIPLE_HPP
#define TOKENTRIPLE_HPP
#include <string>

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

        //@:s is the string to potentially concatenate
        //@: onto str        
        //#:If there is enough room for s, then add it
        //#:to the end of str
        void updateTriple(std::string s);

        //#return the number of bytes needed to store str
        size_t calcBytesNeeded();
            
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
};

#endif //TOKENTRIPLE_HPP


    

