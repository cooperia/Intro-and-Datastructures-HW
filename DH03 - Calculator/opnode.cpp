#include "opnode.h"

//Public Functions:

//Constructor
opnode::opnode(){
  _next = NULL;
}
//Argument constructor.
opnode::opnode(int data, opnode* next){
  _next = next;
  _data = data;
}
//Destructor. (not using this... my delete list func leaves head -> NULL
opnode::~opnode(){
}
//sets data
void opnode::set_data(int data){
  _data = data;
}
//sets next pointer
void opnode::set_next(opnode* next){
  _next = next;
}
//returns data in a opnode
int opnode::get_data(){
  return _data;
}
//returns next opnode object as pointer
opnode* opnode::get_next(){
  return _next;
}






  

