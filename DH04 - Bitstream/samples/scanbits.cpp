//File Name: scanbits.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Description: scans the bits in the variable c
//Last Changed: Mon Oct  6 12:22:41 PDT 2008

#include <iostream>
using namespace std;

int main() {
  unsigned char c = 'b';
  unsigned char mask = 0x80;
  
  cout << c << "=" ;
  for(int i=0;i<8;i++) {
    if(mask == (c & mask)) cout << 1; 
    else cout << 0;
    mask = mask>>1;
  }

  unsigned char d = 'b';
  unsigned char penis = 1;
  penis = penis <<1;
  if(penis == (d & penis)) cout<<"GREEN 1";
  else cout << "purple 0";


}

