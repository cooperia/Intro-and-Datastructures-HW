#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "avl.h"

#define RETURN '\n'
#define FILENAME "wordlist.txt"

using namespace std;

void suggest(string, avl, vector<string>&);
void transpose(string, vector<string>&);
void typo(string, vector<string>&);
void missing(string, vector<string>&);

int main(){
  vector<string> candidates;
  ifstream wordlist;
  wordlist.open(FILENAME);
  avl tree;
  string in;
  bool correct;
   while(1){
   wordlist >> in;
   // cout<<"here "<<in<<endl;
   if(wordlist.eof()){
         break;
    }
     tree.insert(in);
     //DEBUG!!
     //tree.print_tree();
   }

  while(1){
    in ="";
    cout<<"Please enter a word."<<endl;
    if(cin.peek() == RETURN){
      break;
    }

    cin>>in;

    correct = tree.is_element(in);
    if(correct){
      cout<<in<<" is spelled correctly."<<endl;
    }
    else{
      cout<<in<<" is spelled incorrectly... Here are some suggestions."<<endl;
      suggest(in, tree, candidates);
      candidates.clear();
    }
    while(cin.peek() != RETURN){
      cin.get();
    }
    cin.get();
  }

}

void suggest(string word, avl tree, vector<string>& candidates){
  transpose(word, candidates);
  typo(word, candidates);
  missing(word, candidates);
  //DEBUG
  cout<<"called the suggestion funcs"<<endl;
  for(int i = 0; i<candidates.size(); i++){
    //DEBUG
    cout<<"Candidate is "<<candidates[i]<<endl;
    if(tree.is_element(candidates[i])){
      //DEBUG
      cout<<"made it into if"<<endl;
	 cout<<candidates[i]<<endl;
       }
  }

}

void transpose(string word, vector<string>& candidates){
  string tmp_word;
  char tmp;
  for(int i = 0; i<(word.length()-1); i++){
    tmp_word = word;
    tmp = tmp_word[i];
    tmp_word[i] = tmp_word[i+1];
    tmp_word[i+1] = tmp;
    //DEBUG!!
    cout<<"Got to push in transpose."<<endl;
    candidates.push_back(tmp_word);
  }
  //DEBUG!!
  cout<<"Vector size is "<<candidates.size()<<endl;
  cout<<"Finished transpose func."<<endl;

}

void typo(string word, vector<string>& candidates){

}

void missing(string word, vector<string> &candidates){
}
