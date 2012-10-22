#ifndef OPSTACK_H
#define OPSTACK_H
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "opnode.h"
using namespace std;

class opstack {

 public:

  //Constructor
  opstack();

  //Destructor
  ~opstack();

  //Copy Constructor.
  opstack(const opstack&);

  //Assignment Op Overload.
  opstack& operator=(const opstack&);

  //Pops top Element off opstack. 
  int  pop();

  //Pushes data onto top of opstack as a opnode. 
  void push(int);

  //Returns top without pooping opnode.
  int top();

  //Clears Opstack.
  void clear();

  //Returns size.
  int size();

  //prints out contents of a opstack.
  void print();

  //Inserts an element at bottom of opstack. 
  void ins_last(int, opnode*&);

 private:
 
  opnode* _head;

  int _size;
};
#endif
