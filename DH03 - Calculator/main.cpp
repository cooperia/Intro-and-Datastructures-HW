//Author:Ian Cooper
//Class:Data Structures
//Date:9/28/08
//Hurray giant blobs of code.


#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "opstack.h"
#include "numstack.h"
#include "ops.h"
using namespace std;

//Definitions.
#define RETURN '\n'
#define SPACE ' '
#define ADD 0
#define SUB 1
#define MLT 2
#define DIV 3
#define UNM 4
#define LPR 5
#define RPR 6
#define DLR 7
#define END 8
#define PERIOD '.'
#define SPACE ' '
#define PRECDIM 9

//Executes operators.
bool exec_op(opstack&, numstack&);

//Determines what stack to push to. 
bool getToken(bool&,bool&,bool&);

//Decides what op is what.
int opSwitch(bool&);


int main(){
  numstack nums;
  opstack ops;
  bool unm = true;
  bool num = false;
  bool op = false;
  double number;
  bool fail = true;
  bool end = false;
  int current_op;
  char dummy;
  double result = 0;
  bool error = false;

  cout<<"***Welcome to Ian's semi-cool calculator!***"<<endl;
  cout<<"All expressions entered into this semi cool calculator must begin with '$' and end with ';'."<<endl;
  cout<<"To quit, simply press enter with an empty input line."<<endl<<endl;
  while (1){

  cout<<"Pease enter an expression. "<<endl;
  if(cin.peek() == RETURN){
    break;
  }
  if(cin.peek() != '$'){
    error = true;
  }

  cin>>dummy;
  ops.push(DLR);
  while(1){
    if(error){
      cout<<"Invalid Expression."<<endl;
      break;
    }
   fail = getToken(unm, num, op);
   if(!fail){
     cout<<"Invalid expression."<<endl;
       break;}
    if(num){
      cin>>number;
      nums.push(number);
    }
    else if(op){
      current_op = opSwitch(unm);
      while(!prec[current_op][ops.top()]){
	if(current_op == RPR && ops.top() == LPR){
	  exec_op(ops,nums);
	  break;
	}
	if(current_op == END && ops.top() == LPR){
	  error = true;
	  break;
	}
	error = exec_op(ops,nums);
	if(error){break;}
      }
      if(current_op == END){
	end = true;
      }
      if(current_op != RPR){
	ops.push(current_op);
      }
    }
  
   
    if(error){
      cout<<"Invalid Expression."<<endl;
      break;
    }
    else if(end){
      result =  nums.pop();
      cout<<"The answer is: "<<result<<"!!!"<<endl;
      break;
    }
  }

  while(cin.peek() != RETURN){
      cin.get();
    }
    cin.get();
  }
  return 0;
}

//Decides what op is what.
int opSwitch(bool& unm){
  char op;
  cin>>op;
  int dur = -1;
  switch(op){
  case '+':
    unm = true;
    dur =  ADD;
    break;

  case '-':
    if(unm){
      dur = UNM;
      break;
    }
    else{
      unm = true;
      dur = SUB;
      break;
    }

  case '*':
    unm = true;
    dur= MLT;
    break;

  case '/':
    unm = true;
    dur = DIV;
    break;

  case '(':
    unm = true;
    dur = LPR;
    break;

  case ')':
    dur = RPR;
    break;

  case ';':
    unm = true;
    dur = END;
    break;
      
  default:
    dur = -1;
    break;
  }
  return dur;
}

//Decides which stack to push to.
bool getToken(bool& unm, bool& num, bool& op){
  num = false;
  op = false;
  char dur;
  while(cin.peek() == SPACE){
    cin.get();
  }
  if((cin.peek() >= '0' && cin.peek() <= '9') ||( cin.peek() == PERIOD)){
    num = true;
    unm = false;

    return true;
  }
  else{
    if(cin.peek() != '-'){
      unm = false;
    }
    op = true;
    return true;
  }
    return false;
}

//Executes operators.
bool exec_op(opstack& ops, numstack& nums){

  double x, y;
  bool error = false;
  int op;
  op = ops.pop();



  switch(op){
  case ADD:
    y = nums.pop();
    x = nums.pop();
    nums.push(x+y);
    break;

  case SUB:
    y = nums.pop();
    x = nums.pop();
    nums.push(x-y);
    break;

  case MLT:
    y = nums.pop();
    x = nums.pop();
    nums.push(x*y);
    break;

  case DIV:
    y = nums.pop();
    x = nums.pop();
    nums.push(x/y);
    break;

  case UNM:
    y = nums.pop();
    nums.push(-y);
    break;

  case LPR:
    break;

  case DLR:
    ops.push(DLR);
    error = true;
    break;

  default:
    error = true;
    break;
  }
  return error;
}

