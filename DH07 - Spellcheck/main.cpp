//Uathor: Ian Cooper
//Clsas: Dtaa Sturctruse
//Puropse: I usre wihs I had a splel Cehckre


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "avl.h"

#define RETURN '\n'
#define FILENAME "wordlist.txt"

using namespace std;

//Transposes each pair of adjacent letters
void transpose(string, vector<string>&);
//Trys every letter of the alphabet in every slot of the string.
void typo(string, vector<string>&);
//Adds every letter of the alphabet to the beginning, end, and in between each pair of letters. 
void missing(string, vector<string>&);

int main(){
  vector<string> candidates;
  ifstream wordlist;
  wordlist.open(FILENAME);
  avl tree;
  string in;
  bool correct;
  int check;

  cout<<"If you would like to run in debugging mode, please enter a 1."<<endl<<"Otherwise just press enter."<<endl;

  if(cin.peek() == '1'){
    while(cin.peek() != RETURN){
      cin.get();
    }
    cin.get();
    while(1){
      cout<<"Please enter a two-character string you would like to add to the avl tree."<<endl;
      if(cin.peek() == RETURN){return 0;}
      cin>>in;
      tree.insert(in);
      tree.print_tree();

      while(cin.peek() != RETURN){
	cin.get();
      }
      cin.get();
    }
  }

    cout<<"Loading wordlist..."<<endl;
  while(1){
    wordlist >> in;
    if(wordlist.eof()){
      break;
    }
    
    tree.insert(in);
  }

  while(cin.peek()!= RETURN){
    cin.get();
  }
  cin.get();

  while(1){
    cout<<"Please enter a word."<<endl;
    if(cin.peek() == RETURN){
      break;
    }

     cin>>in;

    correct = tree.is_element(in);
    if(correct){
      cout<<"=============================="<<endl;
      cout<<in<<" is spelled correctly."<<endl;
      cout<<"=============================="<<endl;
     }
    else{
      cout<<"=============================="<<endl;
    cout<<in<<" is spelled incorrectly... Here are some suggestions..."<<endl;

    for(int v = 0; v<in.length(); v++){
      in[v] = tolower(in[v]);
    }
    
    transpose(in, candidates);
    typo(in, candidates);
    missing(in, candidates);

    for(int i = 0; i<candidates.size(); i++){
      if(tree.is_element(candidates[i])){
	cout<<candidates[i]<<endl;
      }
    }
    cout<<"=============================="<<endl;
    candidates.clear();
    }


    while(cin.peek() != RETURN){
      cin.get();
    }
    cin.get();
  }

}

//Transposes each pair of adjacent letters.
void transpose(string word, vector<string>& candidates){
  string tmp_word;
  char tmp;
  for(int i = 0; i<(word.length()-1); i++){
    tmp_word = word;
    tmp = tmp_word[i];
    tmp_word[i] = tmp_word[i+1];
    tmp_word[i+1] = tmp;
    candidates.push_back(tmp_word);
  }

}

//Trys every letter of the alphabet in every slot of the string.
void typo(string word, vector<string>& candidates){
  string temp;
  for(int j = 0;j<word.length(); j++){
    for(int i =1; i<26; i++){
      temp = word;
      if(isalpha(temp[j])){
	temp[j] = 'a' +((temp[j]-'a')+i)%26;
      }
      else{continue;}
      candidates. push_back(temp);
    }
  }
}

//Adds every letter of the alphabet to the beginning, end, and in between each pair of letters. 
void missing(string word, vector<string> &candidates){
  char ins;
  string inser;
  string temp;

  for(int i =0; i <= word.length(); i++){
    for(int j = 0; j<26; j++){
      temp = word;
    ins =(('a' + j));
    inser = ins;
    temp.insert(i, inser);
    candidates.push_back(temp);
    }
  }


}
