//File Name: copy.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: copies first argument to second
//Last Changed:

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

  ifstream SRC(argv[1]);
  ofstream DST(argv[2]);

  if(SRC.fail()) { 
    cout << "Unable to open source file: " << argv[1] << endl;
    exit(1);
  }

  char x;

  while(SRC.get(x)) DST.put(x);

  SRC.close();
  DST.close();




  return 0;
}

