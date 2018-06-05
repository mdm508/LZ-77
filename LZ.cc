//For now here is an overview of hte encode algo
//to be implemented later
//
//SETUP STEPS
//1) init window to be size W = 2^N
//2) Read and output first 3 bytes specifying N,L,S
//
//ITERATE DOING THE FOLLOWING
//search window to find longest match with precix of LAB
//CASE 1: you find a match of 2 or more
//If on the last round you didnt match something THEN
//  output the triple that wasnt matched 
//  reset triple
//
//b) output encoding of <len,offset>
//b) 'shift' window forward len characters
//
//CASE 2: you dont find match of 2 or more
//IF on the last rand you didnt match something THEN
//       IF it triple can handle adding str that wasnt matched THEN
//              add umatched str to triple
//      OTHERWISE
//              output the triple
//
//make a new triple that is currenlty unmatt 
//CASE 3: There are no characters left to read
//  in this case output the EOF
//
//
//
#include "search_buffer.hpp" 
#include "misc.hpp"

 int main()
{
    // TODO:
    // Parse the command line arguments
    std::string infile = "infile.txt"; 
    std::string outfile = "outfile.txt";
    const size_t L;
    //@:offset encoding length
    const size_t N;
    //@:encode strlen
    const size_t S;
    
    // Prepare Files
    std::string input_buf = create_input_str(infile);
    ofstream file;
    file.open(outfile);

    // Init Bookeeping and Constant 
    const size_t input_buf_len = input_buf.length();
    const size_t eof_index = input_buf_len - 1;
    const size_t input_buf_len;
    //current position in input stream
    size_t lab_index = 0;
    //lowest position in the window
    size_t low_index = 0;

    // Initialize Search Buffer (Window representation)

