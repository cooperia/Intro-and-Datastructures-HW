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
  void set_left(node*);

  void set_right(node*);

  void set_parent(node*);
  //Returns data.
  double get_data();
  //Returns next node object.
  node* get_left();

  node* get_right();

  node* get_parent();


    


 private:
  double _data;
  node* _lchild;
  node* _rchild;
  node* _parent;
  
};
#endif

