//misc.hpp
//A collection of miscellaneous function

#ifndef MISC_HPP
#define MISC_HPP
#include <string>

//@:infile the name of the input file
//#: reads the contents of the input file into a string
std::string create_input_str(std::string infile);

//@:buf_index an index of a match into the buffer
//@:LAB_index the index of the start of the current LAB
//#:get the position of the max index relative to LAB
size_t calc_relative_offset(size_t buf_index,size_t LAB_index);

//adds the string c1,c2 to the search buffer
//and updates the list index

unsigned char str_to_byte(std::string s);
void write(std::string s,std::ostream& out);
#endif
