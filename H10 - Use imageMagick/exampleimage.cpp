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
  int r, c;
  double red_var, green_var, blue_var, t;
  Image image("500x500","white");
  image.classType(DirectClass);
  image.modifyImage();

  image.fillColor("red");
  image.draw(DrawableLine(0,0,499,499));

//  image.swirl(720.0);
//  image.spread();
//  image.fillColor("red");
  for (r=0;r<=10;r++) for (c=0;c<=10;c++)
  image.draw(DrawableColor(r,c,PointMethod));
  image.fillColor("black");
  image.annotate("Albert Schueller '08","100x20+15+15");

  image.write("out.gif");
  image.display();


  return 0;
}

