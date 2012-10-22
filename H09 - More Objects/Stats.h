#ifndef STATS_H
#define STATS_H
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class Stats {

 public:

  //Constructor.
  Stats();

  //Destructor
  ~Stats();

  //Copy Constructor
  Stats(const Stats&);

  //Operator overload for '='.
  Stats& Stats::operator=(const Stats&);

  // adds the argument to the set
  void add(const double);

  // returns the cardinality of the set
  unsigned int cardinality() const;

  // prints out the contents of the array to the terminal, all elements,
  // comma separated list, no line breaks
  void print() const;

  // resets cardinality to zero (effectively emptying the set)
  void clear();

  //Calculates the median of a set of data and reports it.
  void median(Stats&);

  //Calculates the mean of a set of data and cout's it. Also returns the mean a  //s a double.
  double mean() const;

  //Calculates the standard deviation of the a set of data.
  void stndDev(double);

  //Loads the contents of a .dat file into a dynamic array and reports the 
  //number of data points in the file.
  void load(const char* A);


 private:
  double *_element;
  unsigned int _cardinality;
  unsigned int _array_size;
  unsigned int _chunk_size;
  //Increases array size by _chunk_size.
  void _grow();
  //Decreases array size by _chunk_size.
  void _shrink();
  //Swaps two data points in an array.
  void _swap(double*, double*);
  //Sorts data points from least to greatest.
  void _sort(Stats&);

};
#endif

