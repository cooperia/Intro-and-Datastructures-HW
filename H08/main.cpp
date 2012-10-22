#include <iostream>
#include "Set.h"
using namespace std;

Set function(Set);
int main(){
  Set a;
  Set b(2);
  Set c;



  a.add(-1);
  a.add(2);
  a.add(3);

  b.add(4);
  b.add(5);
  b.add(7);
  cout<<"b is this big..."<<endl;
  b.size();
  cout<<"a is this big..."<<endl;
  a.size();
  c=a+b;
  cout<<"c is this big..."<<endl;
  c.size();
  cout<<c;
return 0;
}


Set function(Set a){
  cout<<"We made it this far."<<endl; 
return a;
}
