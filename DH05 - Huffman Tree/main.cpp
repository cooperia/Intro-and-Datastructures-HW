#include "huffman.h"
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
  string hzip = "./hzip";
  string hunzip = "./hunzip";

  huffman huff(argv[1], argv[2]);

  if(argv[0] == hzip){
    cout<<"Compressing..."<<endl;
    huff.count();
    huff.buildtree();
    huff.putheader();
    huff.encode();
    cout<<"Compressed!"<<endl;
  }
  else if(argv[0] == hunzip){
    cout<<"Decompressing..."<<endl;
    huff.getheader();
    huff.decode();
    cout<<"Deconpressed!"<<endl;
  }


}
