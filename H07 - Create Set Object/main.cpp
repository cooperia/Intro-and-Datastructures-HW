#include <iostream>
#include "Set.h"
using namespace std;


int main(){
  Set a;
  Set b;
  Set c;
  Set d;
  Set e;

  a.add(-1);
  a.add(2);
  a.add(-3);
  a.add(3);

  b.add(1);
  b.add(2);

  c.add(1);
  c.add(2);
  c.add(4);

  d.add(5);
  d.add(6);


  if(c>3){
    cout<<"fuck your ass.";
  }


  // a.remove(3);

  // cout<<"Set e has the elements: "<<e<<"Its Cardinality is: "<<e.cardinality()<<"\n";

  //cout<<"\n";
  

  //c = h + b;
  //h+=9;
  //h-=2;
  //c=h*b;
  //cout<<h<<b;
  //h.print
  //b.print();
  //h.remove (4);
  //h.clear();
  //c.print();
  //cout <<"Cardinality = " <<c.cardinality()<<"\n";

  //check .iselement operator. 
  //if(h.isElement(4)){
  //cout<< "You are awesome. \n";
  //}
  //if(b<h){
  //cout<<"b is a subset of h.";
  //}
  //if(i<b){
  //  cout<<i<<" is an element of b.";
  //}
  //if(h>i){
  //  cout<<i<<" is an element of h.";
  //}

return 0;
}


