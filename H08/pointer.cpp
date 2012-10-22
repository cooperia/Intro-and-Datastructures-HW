//File Name: pointer.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: demonstrate pointer syntax, usage
//Last Changed:

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  // on single values
  double i=1.1, j=-2.5, k=3.4;
  double *p = NULL;
  double a[10];

  for (int n = 0; n< 10; n++) {
    a[n] = sqrt(n);
  }

  p = &j;

  // print out memory location
  cout << p << endl;

  // dereference: * prints out value at memory location
  cout << *p << endl;

  // point p at the 5th element of a
  p = &a[4];
  for (int n = 0; n<6 ; n++) {
    cout << p[n] << endl; 
  }

  p[0]=10;

  for (int n = 0; n<10 ; n++) {
    cout << a[n] << endl; 
  }

  // address of: &

  // new operator

  int *m;
  int size;
  cout << "How large int array: " << endl;
  cin >> size;
  m = new int[size];
  for(int i=0;i<size;i++) {
    m[i] = 2*i;
  }

  for (int i=0; i<size; i++) {
    cout << m[i] << endl;
  }

  // delete operator
  //delete [] m;

  // memory leak: redirect pointer without deleting it first
  int *p7 = new int;
  *p7 = 10;
//  m=p7;  // lost memory at m, uncomment delete above to fix


  // dangling pointer: delete memory without setting pointer to NULL or
  // different valid memory location (common with multiple pointers to same
  // location)
  delete [] m;

  cout << m[3] << endl;
  m[3] = 7;

  // on arrays


  return 0;
}

