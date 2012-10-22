#include <fstream>
#include <iostream>
#include "bitstream.h"
#define EOF_ORD 256
#define EOL -1 


//Huffnode!

class huffnode{
  friend class huffman;
 private:
  int lchild, rchild, parent, weight, nextroot;

 public:
  huffnode(){
    lchild = EOL;
    rchild = EOL;
    parent = EOL;
    weight = 0;
    nextroot = EOL;
  };
};

//Huffman shtuff!!

class huffman{
 private:
  int root,rootlist,leaves;
  huffnode node_array[513];
  ibitstream ibits;
  obitstream obits;
  const char *file_in, *file_out;

  void insert(int i);

 public:
  //Constructor
  huffman(const char*, const char*);
  //Counts the number of occurances of each character in a file.
  void count();
  //Sorts and builds the huffman tree.
  void buildtree();
  //Inserts nodes back into the list when necessary.
  void list_insert(int);
  //Writes the header to the output file.
  void putheader();
  //Encodes each character from the input file then calls putcode.
  void encode();
  //Puts encoded bits to the output file.
  void putcode(int);
  //Gets header from input zipped file.
  void getheader();
  //Decodes zipped file and puts to output file.
  void decode();
};
