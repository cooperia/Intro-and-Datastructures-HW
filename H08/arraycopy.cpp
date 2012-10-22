//File Name: arraycopy.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: demo issues with array assignments
//Last Changed:

#include <iostream>
using namespace std;

// first arg is an int array to print, second is the number of elements in
// the array, prints out contents of array, one element per line
void print(int[], int);

int main() {
  int i;
  int a[10], b[10];
  
  for(i=0;i<10;i++) {
    a[i] = i*i;
  }
  // print array
  print(a,10);

  return 0;

}

void print(int a[], int n) {
  int i;
  for(i=0;i<n;i++) {
    cout << a[i] << endl;
  }
}
