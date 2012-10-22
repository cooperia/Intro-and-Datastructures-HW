#include <iostream>
#include <cstring>
#include "Stats.h"
using namespace std;

int main(int argc, char **argv){
  Stats a;
  ifstream inputfile;
  double mean;

  a.load(argv[1]);
  a.median(a);
  mean = a.mean();
  a.stndDev(mean);

return 0;
}

