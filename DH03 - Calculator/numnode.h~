#ifndef OPNODE_H
#define OPNODE_H
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class opnode {

 public:

  //Constructor
  opnode();

  //Argument constructor.
  opnode(int, opnode*);
  //Destructor. (I dont use this because my delete_list func leaves head pointing to NULL.
  ~opnode();
  //Sets data in a opnode.
  void set_data(int);
  //Sets next opnode pointer.
  void set_next(opnode*);
  //Returns data.
  int get_data();
  //Returns next opnode object.
  opnode* get_next();


    


 private:
  int _data;
  opnode* _next;
  
};
#endif

