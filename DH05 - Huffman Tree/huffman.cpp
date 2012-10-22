#include "huffman.h"
#include <fstream>
#include <iostream>

using namespace std;
//Constructor
huffman::huffman(const char* file_ins, const char* file_outs){
  file_in = file_ins;
  file_out = file_outs;
}
//Counts and stuff.
void huffman::count(){
  ifstream in_file;
  unsigned char b;
  in_file.open(file_in);
  while(1){
  b = in_file.get();
  if(in_file.eof()){break;}
  node_array[int(b)].weight++;
  }

  node_array[256].weight = 1;

  for(int counter = 0; counter < 257; counter++){
    if(node_array[counter].weight != 0){
    }
  }
  in_file.close();
}
//Sorts list and builds huffman tree.
void huffman::buildtree(){
  rootlist = 256;

  bool success;
  int current;
  for(int counter = 0; counter < 256; counter++){
    current = rootlist;
    success = false;
    if(node_array[counter].weight != 0){
      while(node_array[current].nextroot != EOL){
	if(node_array[node_array[current].nextroot].weight >= node_array[counter].weight){

	  node_array[counter].nextroot = node_array[current].nextroot;
	  node_array[current].nextroot = counter;
	  success = true;
	  break;
	}
	current = node_array[current].nextroot;
      }
      if(!success){
      node_array[current].nextroot = counter;
      }
    }
  }
  int newnode = 257;
  while(1){
    node_array[newnode].weight = node_array[rootlist].weight + node_array[node_array[rootlist].nextroot].weight;

    node_array[newnode].lchild = rootlist;
    node_array[newnode].rchild = node_array[rootlist].nextroot;
    node_array[rootlist].parent = newnode;
    node_array[node_array[rootlist].nextroot].parent = newnode;

    rootlist = node_array[node_array[rootlist].nextroot].nextroot;

    if(rootlist == EOL){
      root = newnode;
      break;
    }

    if(node_array[rootlist].weight <= node_array[newnode].weight){
     list_insert(newnode);
    }
    else{
      node_array[newnode].nextroot = rootlist;
      rootlist = newnode;
    }
    newnode ++;

  }

}

//Inserts new nodes into list when needed.
void huffman::list_insert(int newnode){
  bool success = false;
  int current = rootlist;
  while(node_array[current].nextroot != EOL){
    if(node_array[node_array[current].nextroot].weight >= node_array[newnode].weight){

      node_array[newnode].nextroot = node_array[current].nextroot;
      node_array[current].nextroot = newnode;
      success = true;
      break;
    }
    current = node_array[current].nextroot;
  }
  if(!success){
    node_array[current].nextroot = newnode;
  }
}

//Puts header to output file.
void huffman::putheader(){
  obits.open(file_out);
  obits.putint(root,10);
  for(int counter = 257; counter <= root; counter ++){
    obits.putint(node_array[counter].lchild, 9);
    obits.putint(node_array[counter].rchild, 9);
  }
}

//Encodes each character from input file and calls putcode.
void huffman::encode(){
  ifstream input;
  int next;
  int nextnext;
  int counter;
  int temp_array[257];
  bool flag = false;
  input.open(file_in);
  while(1){
    if(flag){break;}
    counter = 0;
    next = input.get();
    if(input.eof()){
      next = 256;
      flag = true;
}
    while(1){
      nextnext = node_array[next].parent;
      if(node_array[nextnext].lchild == next){
	temp_array[counter] = 0;
      }
      else{
	temp_array[counter] = 1;
      }
      if(node_array[nextnext].parent == EOL){break;}
      counter++;
      next = nextnext;
    } 
    for(counter; counter >= 0; counter--){
      putcode(temp_array[counter]);
    }

  }
  obits.flush();
  obits.close();
}

//Puts bits to output file.
void huffman::putcode(int bit){
  obits.putbit(bit);
}

//Gets header from zipped file.
void huffman::getheader(){
  int counter = 257;
  ibits.open(file_in);
  ibits.getint(root, 10);

  for(counter; counter <= root; counter ++){
    ibits.getint(node_array[counter].lchild, 9);
    ibits.getint(node_array[counter].rchild, 9);

  }

}

//Decodes zipped file and writes to output file. 
void huffman::decode(){
  int b;
  int pos = root;
  ofstream out;
  out.open(file_out);
  while(ibits.getbit(b)){
    if(b == 0){
      pos = node_array[pos].lchild;
    }
    else{
      pos = node_array[pos].rchild;
    }
    if(pos == 256)break;
    if(pos < 256){
      out.put(char(pos));
      pos = root;
    }
  }
      ibits.close();
      obits.close();
}


