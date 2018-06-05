#include "misc.hpp"
#include <sstream>
#include <fstream>

std::string create_input_str(std::string infile)
{
    std::ifstream in(infile);
    std::stringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

size_t calc_relative_offset(size_t buf_index,size_t LAB_index)
{
    return LAB_index - buf_index;
}






