//Ian cooper
//Bitstream assignment
//Oct 15, 2008
//Data structures.
#include <iostream>
#include <string>
#include <fstream>
#include "bitstream.h"

using namespace std;

int main(){
  //A buttload of declarations.
  int choice = 0;
  string command ;
  obitstream obits;
  ibitstream ibits;
  string ofile_name;
  string ifile_name;
  string bits;
  int inputbit;
  int b = -1;
  int recieve =0;
  int write = 0;
  string number;
  bool check = false;


  cout<<"ACTIONS:"<<endl<<endl;
    cout<<"1. Set the name of the input file."<<endl;
    cout<<"2. Set the name of the output file."<<endl;
    cout<<"3. Set the of bits in the bit representation."<<endl;
    cout<<"4. List the contents of the input file as integers."<<endl;
    cout<<"5. Write integers to the output file in b-bit representation."<<endl<<endl;


    //main while loop
  while(1){
  
    cout<<"Please choose an action."<<endl;

    getline(cin, command);
    if(command.length() == 0) break;
    choice = atoi(command.c_str());


    //command switch
  switch(choice){

  case 1:
    cout<<"Please enter the name of the input file you would like to open:"<<endl;
    getline(cin,ifile_name);
    ibits.open(ifile_name.c_str());
    break;

  case 2:
    cout<<"Please enter the name of the output file you would like to open:"<<endl;

    getline(cin,ofile_name);
    obits.open(ofile_name.c_str());
    break;

  case 3:
    cout<<"Please enter an integer for the number of bits you would like to represent things with:"<<endl;
    getline(cin,bits);
    b=atoi(bits.c_str());
    break;

  case 4:
    if(b==-1){
      cout<<"You must first set the bit notation."<<endl;
      break;
    }

    cout<<"The file contains:"<<endl; 
    while(1){
      check = ibits.getint(recieve, b);
      if(check){
      cout<<recieve<<endl;
      }
      else{
	break;}

     }
    break;

  case 5:
    if(b == -1){
      cout<<"You must first enter a bit representation using option 3."<<endl;
      break;
    }
    while(1){
    cout<<"Please enter an int you would like to write to file in b-bit notation."<<endl;
    getline(cin,number);
    if(number.length() == 0)break;
    write = atoi(number.c_str());
    obits.putint(write,b);
    }
    break;

  default:
    cout<<"ERROR!!! I don't know how to handle your request, please try again."<<endl;
    break;
  }



  }
}
