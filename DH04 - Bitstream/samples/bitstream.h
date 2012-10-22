#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class obitstream {
 private:
  unsigned char bytebuffer;
  int bitpos;
  ofstream file_out;


 public:
  obitstream(){
    bitpos = 0;
  }

  ~obitstream(){
    flush();
    close();
  }

  void flush(){
    while(bitpos < 8){
      putbit(0);
    }
    file_out<<bytebuffer;
  }

  void open(const char*){
    file_out.open(char*);
  }

  void close(){
    file_out.close();
  }

  void putbit(int c){
    int counter=0;
    if(bitpos == 8){
      file_out<<bytebuffer;
      bitpos = 0;
    }
    mask = mask << bitpos;
    unsigned char mask=1;
    if(c==0){
      bytebuffer = bytebuffer & (~mask);
    }
    else if(c==1){
      bytebuffer = bytebuffer | mask;
    }
    bitpos++;
  }

  bool checkbit(int n, int pos){
    int intmask =1;
    intmask = intmask << pos
      if(intmask == (n & intmask))return 1;
      else{return 0;}
  }


  void putint(int n, int b){
    bitpos = 0;
    int intmask = 1;
    counter = 0;
    for(counter =0; counter < b && counter<32; counter++){
      if(checkbit(n, counter)){putbit(1);}
      else{putbit(0);}
    }
  }





};

class ibitstream {
 private:
  unsigned char bytebuffer;
  int bitpos;
  ifstream file_in;


 public:
  ibitstream();

  ~ibitstream();

  void open(const char*);

  void close();

  bool getbit(int &b);

  bool getint(int &n, int b);

  bool eof();
};
#endif
