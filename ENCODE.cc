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
