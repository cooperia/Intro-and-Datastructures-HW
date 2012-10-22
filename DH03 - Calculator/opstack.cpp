#include "opstack.h"

//Public Functions:

//Constructor
opstack::opstack(){
  _head = NULL;
  _size = 0;
}

//Destructor
opstack::~opstack(){
  opnode* temp = NULL;
  if(_head == NULL){
    return;
  }
  while((_head -> get_next()) != NULL){
    temp = _head;
    _head = (_head -> get_next());
    delete temp;
  }
  opnode* temper = NULL;
  temper = _head;
  _head = NULL;
  delete temper;
  _size = 0;
}

//Copy Constructor
opstack::opstack(const opstack& orig){
  _head = NULL; 
  opnode* cursor = NULL;
  _size = 0;
 
  for(cursor = orig._head; cursor != NULL; cursor = cursor -> get_next()){
    if(cursor == orig._head){
      _head = new opnode(cursor -> get_data(), NULL);

    }
    else{
      ins_last(cursor -> get_data(), _head);

    }
    _size++;
  }

}

//Assignment Op Overload.
opstack& opstack::operator=(const opstack& durka){
  if(this == &durka){return *this;}
  this -> clear();
  opnode* cursor = NULL;
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
int opstack::pop(){
  int value = 0;
  value = (_head -> get_data());
  opnode* temp = NULL;
  temp = _head;
  _head = (_head -> get_next());
  delete temp;
  _size--;
  return value;
}

//Push element onto opstack.
void opstack::push(int data){
  opnode* temp = NULL;
  if(_size == 0){
    _head = new opnode(data, NULL);
  }
  else{
  temp = new opnode(data, _head);
  _head = temp;
  }
  _size++;
}

//Returns top data without popping opnode.
int opstack::top(){
  int dat = 0;
  dat = (_head -> get_data());
  return dat;
}

//Clears a opstack.
void opstack::clear(){
  opnode* temp = NULL;

  if(_head == NULL){

  return;
  }

  while((_head -> get_next()) != NULL){
    temp = _head;
    _head = (_head -> get_next());
    delete temp;
  }
  opnode* temper = NULL;
  temper = _head;
  _head = NULL;
  delete temper;
  _size = 0;
}

//Returns size.
int opstack::size(){
  return _size;
}

//Prints contents of opstack.
void opstack::print(){
  opnode* cursor = NULL;
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

//Inserts at end of opstack.
void opstack::ins_last(int dat, opnode* & copy){
  opnode* cursor = NULL;
  opnode* temp = NULL;
  for(cursor = copy; cursor != NULL; cursor = cursor -> get_next()){
    if(cursor -> get_next() == NULL){
      temp = new opnode(dat, NULL);
      cursor -> set_next(temp);
      break;
    }
  }
}
