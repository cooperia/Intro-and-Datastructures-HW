#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

class Set {
// returns a set object representing the union
// of its two arguments
friend Set operator+(const Set&, const Set&);

// adds second argument to the set in the first argument
friend void operator+=(Set&, const int);

// removes second argument from the set in the first argument, returns
// true if an element was actually removed, otherwise returns false
friend bool operator-=(Set&, const int);

// returns a set object representing the intersection 
// of its two arguments
friend Set operator*(const Set&, const Set&);

// prints out the contents of the set to the terminal, all elements,
// comma separated list, no line breaks
friend ostream& operator<<(ostream&, const Set&);

// returns true if the left side is a subset of the right
friend bool operator<(const Set&, const Set&);

// returns true if the right side is a subset of the left
friend bool operator>(const Set&, const Set&);

// returns true if the left side is an element of the right
friend bool operator<(const int, const Set&);

// returns true if the right side is an element of the left
friend bool operator>(const Set&, const int);

public:

 // Constructor, sets _cardinality to zero. Also, initializes _chunk_size and _array_size to 10. 
 Set();

 //Constructor for custom size.
 Set(int);

 //Destructor.
 ~Set();

 //Copy Constructor.
 Set(const Set&);

 //Operator overload for '='.
 Set& operator=(const Set&);

 //Just some feedback for my face.
 int size() const;

 // returns true if its argument is an element of the set
 bool isElement(const int) const;

 // adds the argument to the set
 void add(const int);

 // removes the element from the set
 void remove(const int);

 // resets cardinality to zero (effectively emptying the set)
 void clear();

 // returns the cardinality of the set
 unsigned int cardinality() const;

 // prints out the contents of the set to the terminal, all elements,
 // comma separated list, no line breaks
 void print() const;


private:

 // holds the elements of the set (no repeated elements)
 int *_element;
 // holds the current cardinality of the set
 unsigned int _cardinality;
 //Holds the size of increase or decrease in allocation.
 unsigned int _chunk_size;
 //Holds the current amount of memory allocated to the array.
 unsigned int _array_size;
 //Grow funtion, increases _array_size by _chunk_size.
 void  _grow();
 //Shrink function, decreases _array_size by _chunk_size.
 void _shrink();
   
};
#endif
