#ifndef NUMNODE_H
#define NUMNODE_H
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class numnode {

 public:

  //Constructor
  numnode();

  //Argument constructor.
  numnode(double, numnode*);
  //Destructor. (I dont use this because my delete_list func leaves head podoubleing to NULL.
  ~numnode();
  //Sets data in a numnode.
  void set_data(double);
  //Sets next numnode podoubleer.
  void set_next(numnode*);
  //Returns data.
  double get_data();
  //Returns next numnode object.
  numnode* get_next();


    


 private:
  double _data;
  numnode* _next;
  
};
#endif

