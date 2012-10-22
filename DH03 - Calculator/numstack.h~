#ifndef NUMSTACK_H
#define NUMSTACK_H
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "numnode.h"
using namespace std;

class numstack {

 public:

  //Constructor
  numstack();

  //Destructor
  ~numstack();

  //Copy Constructor.
  numstack(const numstack&);

  //Assignment Op Overload.
  numstack& operator=(const numstack&);

  //Pops top Element off numstack. 
  double  pop();

  //Pushes data onto top of numstack as a numnode. 
  void push(double);

  //Returns top without pooping numnode.
  double top();

  //Clears Numstack.
  void clear();

  //Returns size.
  int size();

  //prints out contents of a numstack.
  void print();

  //Inserts an element at bottom of numstack. 
  void ins_last(double, numnode*&);

 private:
 
  numnode* _head;

  int _size;
};
#endif
