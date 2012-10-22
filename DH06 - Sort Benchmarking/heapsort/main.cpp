#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

void push(int&,int, int*);

int pop(int&, int*, int);

void reheap_up(int, int*);

void reheap_down(int*, int);

int parent(int);

int lchild(int);

int rchild(int);

int main(){
  int tail = -1;
  struct timeval tv;
  double tone, ttwo, total_time;

  ofstream out;
  const char* file_out = "out.dat";
  out.open(file_out);
  int dat;


  for(double run = 5; run<18; run++){
  int DATA_SIZE = int(pow(2.0,run));
    int a[DATA_SIZE];


    for(int j = 0; j<DATA_SIZE; j++){
      a[j] = -1;
    }

    gettimeofday(&tv,NULL);
    tone = tv.tv_sec+tv.tv_usec/1000000.0;

    srand(time(0));

    for(int i = 0; i<DATA_SIZE; i++){
      push(tail, rand(), a);
    }
;
    for(int z = 0; z<DATA_SIZE; z++){
      dat = pop(tail, a, DATA_SIZE);
      out.put(dat);
    }


    gettimeofday(&tv, NULL);

    ttwo = tv.tv_sec+tv.tv_usec/1000000.0;
    total_time = ttwo-tone;
    cout<<"T["<<run<<"] = "<<total_time<<endl;
    cout<<"logT["<<run<<"] = "<<(log(total_time))/(log(2.0))<<endl;
       }


 
}

int parent(int node){
  if(node == 0){return -1;}
  int parent = (node+1)/2 - 1;
  return parent; 
}

int lchild(int node){
  int lchild;
  lchild = (node*2)+1;
  return lchild;
}

int rchild(int node){
  int rchild;
  rchild = (node*2) +2;
  return rchild;
}

void reheap_up(int node,int* b){
  int temp;
  while(b[node] > b[parent(node)]){
    if(parent(node) == -1){return;}
    temp = b[node];
    b[node]= b[parent(node)];
    b[parent(node)] = temp;
    node = parent(node);
  }
}

void reheap_down(int* b, int DATA_SIZE){
  int node = 0;
  int temp;

  while(b[node] < b[lchild(node)] || b[node] < b[rchild(node)]){

  if(b[node] == -1){return;}
  if(lchild(node) >= DATA_SIZE || rchild(node) >= DATA_SIZE){return;}
    if(b[lchild(node)] >=  b[rchild(node)]){
      temp = b[node];
      b[node] = b[lchild(node)];
      b[lchild(node)] = temp;
      node = lchild(node);
    }
    else{
      temp = b[node];
      b[node] = b[rchild(node)];
      b[rchild(node)] = temp;
      node = rchild(node);
    }
   if(lchild(node) >= DATA_SIZE || rchild(node) >= DATA_SIZE){return;}
  }
}

void push(int& tail,int dat, int* b){
  b[tail + 1] = dat;
  tail++;
  reheap_up(tail, b);
}

int pop(int& tail, int * b, int DATA_SIZE){
  int top;
  top = b[0];
  b[0] = b[tail];
  b[tail] = -1;
  reheap_down(b, DATA_SIZE);
  tail--;
  return top;
}
