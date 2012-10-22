#include "numstack.h"

//Public Functions:

//Constructor
numstack::numstack(){
  _head = NULL;
  _size = 0;
}

//Destructor
numstack::~numstack(){
  numnode* temp = NULL;
  if(_head == NULL){
    return;
  }
  while((_head -> get_next()) != NULL){
    temp = _head;
    _head = (_head -> get_next());
    delete temp;
  }
  numnode* temper = NULL;
  temper = _head;
  _head = NULL;
  delete temper;
  _size = 0;
}

//Copy Constructor
numstack::numstack(const numstack& orig){
  _head = NULL; 
  numnode* cursor = NULL;
  _size = 0;
 
  for(cursor = orig._head; cursor != NULL; cursor = cursor -> get_next()){
    if(cursor == orig._head){
      _head = new numnode(cursor -> get_data(), NULL);

    }
    else{
      ins_last(cursor -> get_data(), _head);

    }
    _size++;
  }

}

//Assignment Op Overload.
numstack& numstack::operator=(const numstack& durka){
  if(this == &durka){return *this;}
  this -> clear();
  numnode* cursor = NULL;
  for(cursor = durka._head; cursor != NULL; cursor = cursor -> get_next()){
  if(cursor == durka._head){
    this -> push(cursor -> get_data());

  }
  else{
    ins_last(cursor -> get_data(), this -> _head);
  }
  (this -> _size) = (this -> _size) + 1;
   }

  return *this;
}

//Pops top element. Returns data. 
double numstack::pop(){
  double value = 0;
  value = (_head -> get_data());
  numnode* temp = NULL;
  temp = _head;
  _head = (_head -> get_next());
  delete temp;
  _size--;
  return value;
}

//Push element onto numstack.
void numstack::push(double data){
  numnode* temp = NULL;
  if(_size == 0){
    _head = new numnode(data, NULL);
  }
  else{
  temp = new numnode(data, _head);
  _head = temp;
  }
  _size++;
}

//Returns top data without popping numnode.
double numstack::top(){
  double dat = 0;
  dat = (_head -> get_data());
  return dat;
}

//Clears a numstack.
void numstack::clear(){
  numnode* temp = NULL;

  if(_head == NULL){

  return;
  }

  while((_head -> get_next()) != NULL){
    temp = _head;
    _head = (_head -> get_next());
    delete temp;
  }
  numnode* temper = NULL;
  temper = _head;
  _head = NULL;
  delete temper;
  _size = 0;
}

//Returns size.
int numstack::size(){
  return _size;
}

//Prints contents of numstack.
void numstack::print(){
  numnode* cursor = NULL;
  if(_head == NULL){
    cout<<"The stack is empty"<<endl;
    return;
  }
  cout<<"The stack contains: ";
  for(cursor = _head; cursor != NULL; cursor = cursor -> get_next()){
    if((cursor -> get_next()) != NULL){
      cout<<cursor -> get_data() <<", ";
    }
    else{cout<<cursor -> get_data() << endl;}
  }
}

//Inserts at end of numstack.
void numstack::ins_last(double dat, numnode* & copy){
  numnode* cursor = NULL;
  numnode* temp = NULL;
  for(cursor = copy; cursor != NULL; cursor = cursor -> get_next()){
    if(cursor -> get_next() == NULL){
      temp = new numnode(dat, NULL);
      cursor -> set_next(temp);
      break;
    }
  }
}
