//Author:Ian Cooper
//Class:Data Structures
//Date:9/15/08

//Current Problems:
//No Destructor yet.
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "node.h"
using namespace std;

//Definitions.
#define RETURN '\n'
#define SPACE ' '

//Finds, reports and returns median as a double.
double reportMedian(node* head,int numPts);

//Finds, reports, and returns the number of points and an int.
int numPoints(node* head);

//Finds, reports and returns mean as a double.
double reportMean(node* head);

//Finds and reports standard deviation.
void stndDev(node* head, double median, int numPts);

//Sorts and inserts into list. If number belongs at head or tail, calls list_ins_first or list_ins_last
void list_ins(double dat, node* &head);

//Inserts at tail.
void list_ins_last(double dat,node* cursor);

//Inserts at head.
void list_ins_first(double dat,node* &head);

//Loads a file. Calls list_ins and such.
void load(const char* A, node* & head);

//Prints contents of a list.
void print(node* head);

//Clears a list.
void delete_list(node* &head);

int main(int argc, char **argv){

    double median= 0;
    int numPts = 0;
    ifstream inputfile;
    node* head = NULL;
    bool loaded = false;

    //If no file is specified, doesnt run load function. Otherwise runs load.
    if(argc > 1){
    load(argv[1], head);
    loaded = true;
    }
 


    //Goes until user hits enter without entering a number.
    while(1){
      if(loaded){
      print(head);
      numPts = numPoints(head);
      reportMean(head);
      median = reportMedian(head,numPts);
      stndDev(head,median,numPts);
      }
      cout<<"Please enter a real number you would like to add to the list: ";

      if(cin.peek() == SPACE){
	while(cin.peek() == SPACE){
	  cin.get();
	}
      }
      if(cin.peek()==RETURN){
	break;
      }
      double newNum;
      cin >> newNum;
      if(head == NULL){
	head = new node(newNum,NULL);
	loaded = true;
      }
      else{list_ins(newNum,head);}

      while(cin.peek() != RETURN){cin.get();}
      cin.get();
      
    }
    if(loaded){
    delete_list(head);
    }
return 0;
}

//Finds, reports, and returns the number of points as an int.
int numPoints(node* head){
  node* cursor = NULL;
  int counter = 0;

  for(cursor = head; cursor != NULL; cursor = cursor -> get_next()){
    counter++;
  }
  cout<<"Number of Points: "<<counter<<endl;
  return counter;
}

//Finds, reports, and returns median as a double.
double reportMedian(node* head, int numPts){
   node* cursor = NULL;
   int counter;
   counter = numPts;

   if(counter % 2 == 0){
     double firstMed;
     double secondMed;
     int med = counter/2;
     int count = 1;
     cursor = head;
     while(count < (med+1)){
       if(count == med){
	 firstMed = cursor -> get_data();
	 secondMed = cursor -> get_next() -> get_data();
	 break;
       }
       count++;
       cursor = cursor -> get_next();
     }
     double median;
     median = (firstMed+secondMed)/2;
     cout<<"Median: "<<median<<endl;
     return median;
   }
   else{
     int med = (counter+1)/2;
     int count = 1;
     double median;

     cursor = head;
     while(count != (med + 1)){
       if(count == med){
	 median = cursor -> get_data();
	 cout<<"Median: "<<median<<endl;
	 return median;
       }
       count++;
       cursor = cursor -> get_next();
     }
   }
}

//Finds, reports, and returns mean as a double.
double reportMean(node* head){
  node* cursor = NULL;
  double sum = 0;
  int counter = 0;
  for(cursor = head; cursor != NULL; cursor = cursor -> get_next()){
    sum = sum + (cursor -> get_data());
    counter++;
  }
  double mean;
  mean = sum/counter;
  cout<<"Mean: "<<mean<<endl;
  return mean;
}

//Finds and reports standard deviation.
void stndDev(node* head, double median, int numPts){
  node* cursor = NULL;
  double sum = 0;
  double dev;

  for(cursor = head; cursor != NULL; cursor = cursor -> get_next()){
    sum+=pow(((cursor -> get_data())-median),2.0);
  }

  dev = sqrt(sum/numPts);
  cout<<"Standard Deviation: "<<dev<<endl;
}

//Inserts into list and controls list_ins_last and list_ins_first.
void list_ins(double dat,node* &head){
  node* cursor = NULL;
  int counter = 0;
  for(cursor = head; cursor != NULL; cursor = cursor -> get_next()){
    if(counter == 0 && (cursor -> get_data()) >= dat){
      list_ins_first(dat,head);
      break;
    }
    if((cursor -> get_next()) == NULL){
      list_ins_last(dat,cursor);
      break;
    }
    if((cursor -> get_data()) < dat){
      node * check = NULL;
      check = (cursor -> get_next());
      if((check -> get_data()) > dat || (check -> get_data()) ==  dat){
	node* temp = NULL;
	temp = new node(dat,check);
	cursor -> set_next(temp);
	break;

      }
    }
    counter++;
  }
}

//Inserts at tail.
void list_ins_last(double dat, node* cursor){
  node* temp = NULL;
  temp = new node(dat,NULL);
  cursor -> set_next(temp);
}

//Inserts at head.
void list_ins_first(double dat,node* &head){
  node* temp = NULL;
  temp = new node(dat,head);
  head = temp;
}

//Loads a file.
void load(const char* A,node* &head){
  ifstream inputfile(A);
  if(inputfile.fail()){
    cout<<"You have just failed the retard check.(Your file failed to load.)"<<endl;
    exit(1);
  }
  double x;
  bool first = true;
  while(inputfile>>x){
    if(first == true){
      head= new node(x,NULL);
    }
    else{list_ins(x, head);}
    first = false;
  }
  inputfile.close();
  inputfile.clear();
}

//Prints list.
void print(node* head){
  node* cursor = NULL;
  cout<<"The list contains: " ;
  for(cursor = head; cursor != NULL; cursor = cursor -> get_next()){
    if((cursor -> get_next()) != NULL){
    cout<<cursor -> get_data() <<", ";
    }
    else{cout<<cursor -> get_data() << endl;}
  }
}

//Clears list.
void delete_list(node* &head){
  while((head -> get_next()) != NULL){
    node* temp = NULL;
    temp = head;
    head = (head -> get_next());
    delete temp;
  }
  node* temp = NULL;
  temp = head;
  //I'm assuming here that C++ knows how to get rid of a node* that is set to NULL
  head = NULL;
  delete  temp;

}


