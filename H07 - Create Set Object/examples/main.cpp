//File Name:
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description:
//Last Changed:

#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
  Complex z(1,2);
  Complex a(1,-2);
  Complex c;

  c = -a+z;


  cout << c.ImagPart() << endl;

  return 0;
}
