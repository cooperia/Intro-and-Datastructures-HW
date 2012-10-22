//File Name: image.cpp
//Author: Albert Schueller
//Email Address: schuelaw@whitman.edu
//Assignment Number:
//Description: test ImageMagick Compilation
//Last Changed: Wed Apr 25 20:05:49 PDT 2001

#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;


int main() {
  double start_R=1.0/255, start_G=1.0/255, start_B=145.0/255;
  double end_R=254.0/255, end_G=245.0/255, end_B=8.0/255;
  double t;
  ColorRGB myColor;
  Image image("500x500","white");
  image.classType(DirectClass);
  image.modifyImage();

  // Gradient strip.
  image.fillColor("black");
  for(int i=0; i<500; i++) {
    t = i/499.0;
    myColor = ColorRGB(start_R-t*(start_R-end_R),
	start_G-t*(start_G-end_G), start_B-t*(start_B-end_B));
    image.fillColor(myColor);
    image.draw(DrawableLine(0+i,200,0+i,300));
  }

  image.display();


  return 0;
}

