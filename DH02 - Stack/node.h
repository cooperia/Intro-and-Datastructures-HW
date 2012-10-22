#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class node {

 public:

  //Constructor
  node();

  //Argument constructor.
  node(double, node*);
  //Destructor. (I dont use this because my delete_list func leaves head pointing to NULL.
  ~node();
  //Sets data in a node.
  void set_data(double);
  //Sets next node pointer.
  void set_next(node*);
  //Returns data.
  double get_data();
  //Returns next node object.
  node* get_next();


    


 private:
  double _data;
  node* _next;
  
};
#endif

