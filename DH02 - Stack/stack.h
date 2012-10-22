#ifndef STACK_H
#define STACK_H
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "node.h"
using namespace std;

class stack {

 public:

  //Constructor
  stack();

  //Destructor
  ~stack();

  //Copy Constructor.
  stack(const stack&);

  //Assignment Op Overload.
  stack& operator=(const stack&);

  //Pops top Element off stack. 
  double  pop();

  //Pushes data onto top of stack as a node. 
  void push(double);

  //Returns top without pooping node.
  double top();

  //Clears Stack.
  void clear();

  //Returns size.
  int size();

  //prints out contents of a stack.
  void print();

  //Inserts an element at bottom of stack. 
  void ins_last(double, node*&);

 private:
 
  node* _head;

  int _size;
};
#endif
