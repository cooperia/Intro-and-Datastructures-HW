#include "numnode.h"

//Public Functions:

//Constructor
numnode::numnode(){
  _next = NULL;
}
//Argument constructor.
numnode::numnode(double data, numnode* next){
  _next = next;
  _data = data;
}
//Destructor. (not using this... my delete list func leaves head -> NULL
numnode::~numnode(){
}
//sets data
void numnode::set_data(double data){
  _data = data;
}
//sets next pointer
void numnode::set_next(numnode* next){
  _next = next;
}
//returns data in a numnode
double numnode::get_data(){
  return _data;
}
//returns next numnode object as pointer
numnode* numnode::get_next(){
  return _next;
}






  

