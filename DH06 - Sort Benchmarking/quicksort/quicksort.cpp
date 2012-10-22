#include <iostream>
#include <sys/time.h>
#include <cmath>


using namespace std;

void sort(int*, int, int, int);


int main(){
  int r,l;
  bool swapped =true;
  struct timeval tv;
  double t1 = 0;
  double t2 = 0;
  double total_time = 0;
  int j = 0;
  int DATA_SIZE = 5;
  // double d = 17;


   for(double d = 5; d<18; d++){
    DATA_SIZE = int(pow(2.0,d));
    int a[DATA_SIZE];
    j=0;
    swapped = true;

    srand(time(0));

    a[0] = 6;
    a[1] = 2;
    a[2]=7;

  for(int i = 0; i < DATA_SIZE; i++){
    a[i] = rand();
  }
  gettimeofday(&tv, NULL);
  t1=tv.tv_sec+tv.tv_usec/1000000.0;

  l=0;
  r=DATA_SIZE -1;

  sort(a,DATA_SIZE, r, l);


   gettimeofday(&tv, NULL);
   t2=tv.tv_sec+tv.tv_usec/1000000.0;
   total_time = t2-t1;
   cout<<"T["<<d<<"] = "<<total_time<<endl;
   cout<<"logT["<<d<<"] = "<<(log(total_time))/(log(2.0))<<endl;
    }
}

void sort(int* a, int DATA_SIZE, int r, int l){
  int m;
  int med;
  int end =r;
  m=(r-l)/2;
  int temp = 0;
  bool swapped = false;
  if(m==0){
    m=l;
  }


  if(a[l]>a[m]){
    temp = a[l];
    a[l] = a[m];
    a[m] = temp;
  }
  if(a[m]>a[r]){
    temp = a[m];
    a[m] = a[r];
    a[r] = temp;
  }

  if(a[l]<a[m]){
    temp = a[m];
    a[m] = a[l];
    a[l] =temp;
  }
  med = l;
  l = l+1;

  while(r>l){
    while(a[r]>a[med] && a[l]<a[med] && r>l){
      r--;
      l++;
    }
    if(r<=l){break;}

    while(a[r]>a[med]){
      r--;
    }
    if(r<=l){break;}
    while(a[l]<a[med]){
      l++;
      if(l == r){break;}
    }
    temp = a[r];
    a[r] = a[l];
    a[l] = temp;
    r--;
    l++;
  }
  if(a[r]>a[med]){
    temp = a[r-1];
    a[r-1] = a[med];
    a[med] = temp;
    r = r-1;
  }
  else{
    temp = a[r];
    a[r] = a[med];
    a[med] = temp;
  }
   if(med != (r -1) && r != med){
     sort(a,DATA_SIZE, r-1, med);
     }
   if(r+1 != end && r != end){
   sort(a,DATA_SIZE, end, r+1);
}
}
