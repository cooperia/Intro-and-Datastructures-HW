#include "stack.h"

//Public Functions:

//Constructor
stack::stack(){
  _head = NULL;
  _size = 0;
}

//Destructor
stack::~stack(){
  node* temp = NULL;
  if(_head == NULL){
    return;
  }
  while((_head -> get_next()) != NULL){
    temp = _head;
    _head = (_head -> get_next());
    delete temp;
  }
  node* temper = NULL;
  temper = _head;
  _head = NULL;
  delete temper;
  _size = 0;
}

//Copy Constructor
stack::stack(const stack& orig){
  _head = NULL; 
  node* cursor = NULL;
  _size = 0;
 
  for(cursor = orig._head; cursor != NULL; cursor = cursor -> get_next()){
    if(cursor == orig._head){
      _head = new node(cursor -> get_data(), NULL);

    }
    else{
      ins_last(cursor -> get_data(), _head);

    }
    _size++;
  }

}

//Assignment Op Overload.
stack& stack::operator=(const stack& durka){
  if(this == &durka){return *this;}
  this -> clear();
  node* cursor = NULL;
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
double stack::pop(){
  double value = 0;
  value = (_head -> get_data());
  node* temp = NULL;
  temp = _head;
  _head = (_head -> get_next());
  delete temp;
  _size--;
  return value;
}

//Push element onto stack.
void stack::push(double data){
  node* temp = NULL;
  if(_size == 0){
    _head = new node(data, NULL);
  }
  else{
  temp = new node(data, _head);
  _head = temp;
  }
  _size++;
}

//Returns top data without popping node.
double stack::top(){
  double dat = 0;
  dat = (_head -> get_data());
  return dat;
}

//Clears a stack.
void stack::clear(){
  node* temp = NULL;

  if(_head == NULL){

  return;
  }

  while((_head -> get_next()) != NULL){
    temp = _head;
    _head = (_head -> get_next());
    delete temp;
  }
  node* temper = NULL;
  temper = _head;
  _head = NULL;
  delete temper;
  _size = 0;
}

//Returns size.
int stack::size(){
  return _size;
}

//Prints contents of stack.
void stack::print(){
  node* cursor = NULL;
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

//Inserts at end of stack.
void stack::ins_last(double dat, node* & copy){
  node* cursor = NULL;
  node* temp = NULL;
  for(cursor = copy; cursor != NULL; cursor = cursor -> get_next()){
    if(cursor -> get_next() == NULL){
      temp = new node(dat, NULL);
      cursor -> set_next(temp);
      break;
    }
  }
}
