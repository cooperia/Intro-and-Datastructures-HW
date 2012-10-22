//Author: Ian Cooper
//Date: 02/11/08
//Purpose: Solves for zero value of X in a programmer defined function to desired accuracy. 
//

#include <iostream>
#include <cmath>
using namespace std;

double f(double);


int main () {

  double accuracy;
  accuracy = 1.0e-4;
  double xl;
  double xr;
  double xm;
  double current;
  current = 1;
  double xr0;
  double xl0;



  cout << "Please enter the accuracy you would like to solve to(1.0e-4).\n";
  if (cin.peek() != '\n'){
    cin >> accuracy;
  }
  

  cout << "Please enter the number you would like to assign as the left parameter.\n";;
  cin >> xl;

  cout << "Please enter the number you would like to assign as the right parameter. \n";
  cin >> xr;

  xr0 = xr;
  xl0 = xl;

  while (current > accuracy){
    xm = (xr + xl)/2;
    if (f(xl)*f(xm) > 0){
      xl = xm;
    }
    else if(f(xm) == 0){
      break;
    }
    else {
      xr = xm;
    }
    current = xr - xl;
  }
  
 

  cout << "The zero value of the function sin(x) reported to " << accuracy << " accuracy, and between " << xl0 << " and " << xr0 << " is ";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(10);

  cout << xm << ".\n";
  cout << "This aproximated zero when plugged into the function sin(x) is actually "<< f(xm) << ". \n";

  return 0;
}

double f(double x){
  return sin(x);
}
