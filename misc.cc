//miscellaneous functions

//reads infile into a string and returns the string
std::string create_input_str(std::string infile)
{
    std::ifstream in(infile);
    std::stringstream buffer;
    buffer << in.rdbuf();
    return contents(buffer.str());
}

size_t calc_relative_offset(size_t buf_index,size_t LAB_index)
{
    return LAB_index - buf_index;
}






