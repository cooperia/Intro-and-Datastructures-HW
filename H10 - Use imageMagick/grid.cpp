//File Name: image.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: test ImageMagick Compilation
//Last Changed: Wed Apr 25 20:05:49 PDT 2001

#include <iostream>
#include <cstdlib>
#include <Magick++.h>

using namespace std;
using namespace Magick;


int main() {

  Image image("500x500","white");
  image.classType(DirectClass);
  image.modifyImage();
  image.fillColor("black");
  // Make your own graph paper!
  for(int i=0; i<500; i+=10) {
    image.draw(DrawableLine(i,0,i,499));
    image.draw(DrawableLine(0,i,499,i));
  }

  image.display();

  return 0;
}

