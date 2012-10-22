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
  const  char* filenames;


 public:
  obitstream();

  ~obitstream();

  //flushes full bytebuffer to file
  void flush();

  //opens output file
  void open(const char*);

  //closes output file
  void close();

  //puts a 0 or 1 in next bit of bytebuffer, flushes when full
  void putbit(int);

  //checks whether bit is 0 or 1.
  bool checkbit(int, int);

  //puts an int to file in b bit representation.
  void putint(int, int);

};

class ibitstream {
 private:
  unsigned char bytebuffer;
  int bitpos;
  ifstream file_in;


 public:
  ibitstream();

  ~ibitstream();
  //opens inputfile
  void open(const char*);
  //closes inputfile
  void close();
  //gets next bit from inputfile
  bool getbit(int &);
  //gets an int from input file in b bit representation
  bool getint(int &, int );
  //returns true if eof is reached
  bool eof();
  //checks for 0 or 1
  bool checkbit(int, int);
  //test function for testing things
  int get();
};
#endif
