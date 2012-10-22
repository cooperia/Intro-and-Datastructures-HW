#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define RETURN '\n'
#define ZERO '0'
#define NINE '9'
#define FAIL '-1'
#define FILENAME "digits.txt"

//Searches the digits of PI for the string "key".
int Search(string digits,string key);

//Checks the key string for invalid characters.
int Check(string key);

//Reports success or failure and such. Basically my output.
void Report(int p, string key);
 
int main(){
  string digits;
  string key;
  int p = 0;
  int c = 0;
  ifstream InputFile;
  InputFile.open(FILENAME);
  InputFile >> digits;
  InputFile.close();

  while(1){
    cout << "Please enter a string of digits that you would like to search for.\n";

    //breaks while loop if '\n' is the only char found in the cin pipe.
    if(cin.peek() == RETURN){
      break;
    }
    cin >> key;

    //Calls the check function.
    c = Check(key);
    
    //in case of invalid characters..
    if(c != FAIL){
   
    //Calls the search function.
    p = Search(digits,key);
    
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
}

//Checks the key string for invalid characters.
int Check(string key){
  int i;
  for(i=0;i<key.length();i++){
    if(key[i]<ZERO || key[i]>NINE){
      return FAIL;
      break;
    }
    else if(cin.peek()==' '){
      while(cin.peek()==' '){
        cin.get();
      }
      if(cin.peek()>ZERO || cin.peek()<NINE){
	return FAIL;
	break;
      }
    }
  }
}

//Searches the digits of PI for the string "key".
int Search(string digits,string key){
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


//ask about e) accepting only a single string argument to Search()
//ask about how to make it fail if there are interior spaces
