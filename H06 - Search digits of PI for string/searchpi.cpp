//Author: Ian Cooper
//Date: March 5,2008
//Purpose: Searches the first 1,000,000 digits of Pi for a user specified string of digits. 
//Rawr!!11one

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define RETURN '\n'
#define ZERO '0'
#define NINE '9'
#define FAIL -1
#define SPACE ' '
#define DIGITSFILE "digits.txt"

//Searches the digits of PI for the string "key".
int Search(string key,string digits);

//Checks the key string for invalid characters.
int Check(string key);

//Reports success or failure and such. Basically my output.
void Report(int p, string key);
 
int main(){
  string key;
  string digits;
  int p = 0;
  int c = 0;
  ifstream InputFile;
  InputFile.open(DIGITSFILE);
  InputFile >> digits;

  while(1){
    cout << "Please enter a string of digits that you would like to search for.\n";

    //breaks while loop if '\n' is the only char found in the cin pipe. (also clears spaces before a '\n' if there are any. Fixes the bug that caused the program to do nothing if "   \n" was entered.)   
    if(cin.peek() == SPACE){
      while(cin.peek() == SPACE){
	cin.get();
      }
    }
    if(cin.peek() == RETURN){
      break;
    }

    cin >> key;

    //Calls the check function.	cout<<"I GOT HERE!!";	cout<<"I GOT HERE!!";
    c = Check(key);
    
    //in case of invalid characters..
    if(c != FAIL){
   
    //Calls the search function.
     p = Search(key,digits);
    
    //Calls Report function
    Report(p,key);
    }
    else{
      cout<<"You entered an invalid string of characters.\n";
      cout<<"\n";
    }
    //Clears the 'cin' pipe.
    while(cin.peek() != RETURN){cin.get();}
    cin.get();
  }
  InputFile.close();
}

//Checks the key string for invalid characters.
int Check(string key){
  int i;
  char c;
  for(i=0;i<key.length();i++){
    if(key[i]<ZERO || key[i]>NINE){
      return FAIL;
    }
  }
  while(cin.peek() != RETURN) {
    cin.get(c);
    if (c!=SPACE) { return FAIL; }
  }
}

//Searches the digits of PI for the string "key".
int Search(string key,string digits){
  bool match;
  int i;
  int j;

  for(i=0;i<digits.length();i++){
    if(digits[i] == key[0]){
      match = true;
      for(j=1;j<key.length();j++){
        if(key[j] == digits[i+j]){
          match = true;
	}
        else{
          match = false;
          break;
        }
      }
      if(match == true){
        break;
      }
      
    }
  }
  if(match == true){
    return i+1;
  }
  else{
    return FAIL;
  }
}

//Reports results
void Report(int p,string key){
  if(p == FAIL){

    cout<<"\n"<<"You entered the string: "<<key<<"\n";
    cout<<"No match was found.\n";
    cout<<"\n";
  }
  else{
    cout<<"\n"<<"You entered the string: "<<key<<"\n";
    cout<<"Your string occured at digit "<<p<<" of PI.\n";
    cout<<"\n";
  }
}



