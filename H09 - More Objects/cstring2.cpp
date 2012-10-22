//File Name: cstring.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: demo c-style strings
//Last Changed:

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {

  char college[] = "Whitman College";
  char city[20] = "Walla Walla";
  char *str_ptr;
  string cpp_str = "Washington"; //.c_str() member function returns c-style

  // ordinary assignment doesn't work, use strcpy

  // copy c-style string into char array

  // cout works on c_style strings

  // strlen gives number of chars in string (not including null char)



  return 0;
}

