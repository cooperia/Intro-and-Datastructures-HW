//File Name: file-io.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: demonstrate simple file i/o 
//Last Changed: Fri Feb 29 13:10:45 PST 2008

#include <iostream>
#include <fstream>  //necessary for ofstream and ifstream objects
#include <cstdlib>  //necessary for the exit() function
using namespace std;

int main() {
  char x;
  int i=0;

  ifstream InputFile;
  //try to attach filehandle to external file
  InputFile.open("input-01.txt");
  if (InputFile.fail()) { 
    cout << "Failed to open file.\n";
    exit(1);
  }


  // Reads numbers until the read function fails.
  while(InputFile >> x) {
    i++; // increment number counter
    cout << i << ": " << x << endl;
  }
  
  InputFile.close();  //detach filehandle from external file


  return 0;
}

