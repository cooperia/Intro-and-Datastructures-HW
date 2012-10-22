//File Name: setbits.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Description: tweak chars by setting individual bits
//Last Changed: Mon Oct  6 13:53:49 PDT 2008

#include <iostream>
using namespace std;

int main() {
  unsigned char c = 'b';
  unsigned char mask = 1;
  int bitpos = 2;
  int bit = 1;

  cout << c << endl;
  cout << int(c) << endl;

  // shift mask
  mask = mask << bitpos;
  if (bit == 1) {
    c = c|mask;
  }
  else {
    c = c & (~mask);
  }
  cout << "after mask:" << endl;
  cout << c << endl;
  cout << int(c) << endl;




  return 0;
}

