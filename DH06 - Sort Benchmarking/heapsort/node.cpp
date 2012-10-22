#include "node.h"

//Public Functions:

//Constructor
node::node(){
  _lchild = NULL;
  _rchild = NULL;
  _parent = NULL;
}
//Argument constructor.
node::node(double data, node* parent){
  _data = data;
  _lchild = NULL;
  _rchild = NULL;
  _parent = parent;
}
//Destructor. (not using this... my delete list func leaves head -> NULL
node::~node(){
}
//sets data
void node::set_data(double data){
  _data = data;
}
//sets next pointer
void node::set_left(node* left){
  _lchild = left;
}

void node::set_right(node* right){
  _rchild = right;
}

void node::set_parent(node* parent){
  _parent = parent;
}
//returns data in a node
double node::get_data(){
  return _data;
}
//returns next node object as pointer
node* node::get_left(){
  return _lchild;
}
node* node::get_right(){
  return _rchild;
}
node* node::get_parent(){
  return _parent;
}







  

