#include "bitstream.h"

//obitstream contstructor
obitstream::obitstream(){
  bitpos = 0;
  bytebuffer = 0;
}

//obitstream destructor
obitstream::~obitstream(){
  flush();
  close();
}

//writes to file
void obitstream::flush(){
  file_out<<bytebuffer;
  bytebuffer = 0;
  bitpos = 0;

}

//opens output file
void obitstream::open(const char* filename){
  filenames = filename;
  file_out.open(filename);
}

//closes output file
void obitstream::close(){
  file_out.close();
}

//puts a 1 or 0 in bytebuffer, flushes when full.
void obitstream::putbit(int c){
  unsigned char mask = 1;
 
  if(bitpos == 8){
    flush();
  }
  mask = mask << bitpos;
  if(c==0){
    bytebuffer = bytebuffer & (~mask);
  }
  else if(c==1){
    bytebuffer = bytebuffer | mask;
  }
  bitpos++;

}

//checks if the next bit is 1 or 0
bool obitstream::checkbit(int n, int pos){
  int intmask =1;
  intmask = intmask<<pos;
  if(intmask == (n&intmask))return 1;
  else{return 0;}
}

//puts an int to file in b bits
void obitstream::putint(int n, int b){
  int intmask = 1;
  int counter = 0;
  for(counter=0; (counter<b) && (counter < 32); counter++){
    if(checkbit(n, counter)){putbit(1);}
    else{putbit(0);}
  }
}


//IBITSTREAM!!

 
//ibitstream contsructor
ibitstream::ibitstream(){
  bitpos = 0;
  bytebuffer = 255;
}

//ibitstream destructor
ibitstream::~ibitstream(){
  close();
}

//opens input file
void ibitstream::open(const char* filename){
  file_in.clear();
  file_in.open(filename);
  if(file_in.fail()){
    cout<<"No such file exists, silly."<<endl;
  }
}

//closes input file.
void ibitstream::close(){
  file_in.close();
}

//gets the next bit from the input file.
bool ibitstream::getbit(int &b, int pos){
   unsigned char mask = 1;
   int intmask = 1;
   int test = 0;
   intmask = intmask<<pos;
   if(bytebuffer == 255 || bitpos == 8){
     bitpos = 0;
     if(file_in.peek()== -1){
       file_in.get();
       return false;
     }
   bytebuffer = file_in.get();
   }
   mask = mask<<bitpos;
   if(mask == (bytebuffer&mask)){
     b = b | intmask;
     return true;
   }
   else{
     b = b &(~intmask);
     return true;
   }
}

//gets the next int from input file in b bit representation.
bool ibitstream::getint(int& n, int b){
  int intmask = 1;
  bool WIN = false;
  for(int counter = 0; counter < b; counter ++){
    WIN = getbit(n,counter);
    bitpos++;
      if(!WIN){
	return false;
      }
  }
  return true;
}


//returns true if eof is reached
bool ibitstream::eof(){
  if(file_in.eof()){
    return true;
  }
  else{
    return false;
  }
}

//checks whether next bit is 0 or 1
bool ibitstream::checkbit(int n, int pos){
  int intmask =1;
  intmask = intmask<<pos;
  if(intmask == (n&intmask))return 1;
  else{return 0;}
}

//test function used for testing...
int ibitstream::get(){
int durka;
durka = file_in.get();
return durka;
}
