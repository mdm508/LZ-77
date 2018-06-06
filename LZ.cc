//For now here is an overview of hte encode algo
//to be implemented later
//
//SETUP STEPS
//1) init window to be size W = 2^N
//2) Read and output first 3 bytes specifying N,L,S
//
// Special case of S=1 dont use a token triple just output triplle
// imediatley
//
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
#include <fstream>
#include <iostream>
#include <math.h>
#include "search_buffer.hpp" 
#include "misc.hpp"
#include "bits.hpp"
#include "token_triple.hpp"
using namespace std;
 int main()
{
    // TODO:
    // Parse the command line arguments
    std::string infile = "book1"; 
    std::string outfile = "outfile";
    const size_t L = 4;
    //@:offset encoding length
    const size_t N = 11;
    //@:encode strlen
    const size_t S = 3;
    
    
    // Prepare Files
    std::string input_buf = create_input_str(infile);
    std::ofstream file;
    file.open(outfile);

    // Init Bookeeping and Constant 
    const size_t input_buf_len = input_buf.length();
    const size_t eof_index = input_buf_len - 1;
    const size_t max_matchlen = pow(2,L);

    // VARIABLE DECLARATIONS USED IN MAINLOOP
    char c1, c2;           
    size_t list_index;     //index into SB
    size_t remove_list_index;
    size_t li = 0;         //LAB index 
    size_t li_advance; //used to adjust li by some amount
    size_t low_index = 0; //Low window index
    std::string tempstr, outstr;
    std::pair<size_t,size_t> match;
    tokenTriple triple(S,"");//Initialize a token triple to track non matches
    
    // Initialize Search Buffer (Window representation)
    // Read in the first two chars from L which couldnt possibly
    // be a match
    //TODO: IF file doesnt contain at least two things its a problem
    searchBuffer SB(N);
    c1 = input_buf[li], c2 = input_buf[li+1];
    list_index = chrs_to_number(c1,c2);

    int largest_match = 0; 
    while (li < eof_index - 2){
        //CHECK TO SEE IF THERE IS A MATCH
        ///////////////////////////////////
        //extract first two chars from LAB
        // and get the list index into SB
        c1 = input_buf[li]; c2 = input_buf[li+1];
        list_index = chrs_to_number(c1,c2);
        
        //check if there is a match at this index
        //match.second is the matchlength
        //match.first is start of match index
        match = SB.get_match(list_index,li,max_matchlen,input_buf,input_buf_len); 

        //CASE 1 THERE WAS A MATCH
        ///////////////////////////////////
        if (match.second > largest_match){
            largest_match = match.second;
        }
        if (match.second >= 2){
            //Before writting the new match as a token double, we must check
            //wether there are characters in triple that need to be written
            if (! triple.isEmpty()){
                tempstr = triple.getString();
                //if S is equal to one it we can only have 1 char per triple
                //in this case we must be sure to clear all of triple
                //which at this point may be backed up with characters
                //not yet written out
                if (S == 1){
                    for (int i = 0; i < tempstr.length(); ++i){
                        outstr = make_token_triple(std::to_string(tempstr[i]),L,S,1);
                        write(outstr,file); 
                    }
                }
                else{
                        outstr = make_token_triple(tempstr,L,S,tempstr.length());
                        write(outstr,file); 
                }
                triple.reset();
            }
            outstr = make_token_double(L,N,match.second,
                    calc_relative_offset(match.first,li));

            write(outstr,file);
            li_advance = match.second;
        }
        //CASE 2 THERE WASNT A MATCH
        ///////////////////////////////////
        else{
            //update triple 
            tempstr = string({c1,c2});
            tempstr = triple.updateTriple(tempstr);
            //if the addition of those two characters was more
            //than the capacity of the triple then output
            //the substring str[0,..capcaity-1]. any remaining chars
            //are stored in triple to be output later
            if (tempstr != ""){
                outstr = make_token_triple(tempstr,L,S,tempstr.length());
                write(outstr,file);
            }
            li_advance = 2;
        }//END OF MATCH/NOMATCH CASES

        //UPDATE THE SEARCH BUFFER
        if (SB.atCapacity()){
            c1 = input_buf[low_index]; c2 = input_buf[low_index+1];
            remove_list_index = chrs_to_number(c1,c2);
            SB.remove(list_index);
            low_index += 2;
        }
        //Insert new LA into window
        SB.insert(list_index,li);
        li += li_advance;
  }//END OF WHILE
    //check wether li is at EOF
    if (li == eof_index - 1){
        tempstr = std::to_string(c1);
        outstr = make_token_triple(tempstr,L,S,1);
        write(outstr,file);
    }
    outstr = make_token_eof(L,S);
    write(outstr,file);
    file.close();
    std::cout << "Largest Match " << largest_match << std::endl;
}//END of MAIN
