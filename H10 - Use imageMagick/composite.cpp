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
  //makes transparent
  Image sig("150x150",Color(MaxRGB,MaxRGB,MaxRGB,MaxRGB));
  //Opaque
  //Image sig("150x150",Color(MaxRGB,MaxRGB,MaxRGB));
  cout << "MaxRGB = " << MaxRGB << endl;
  sig.annotate("Albert Schueller '08","100x20+20+75");
  sig.swirl(-90.0);
//  image.classType(DirectClass);
//  image.modifyImage();
  image.fillColor("black");
  // Make your own graph paper!
  for(int i=0; i<500; i+=10) {
//    image.draw(DrawableLine(i,0,i,499));
    image.draw(DrawableLine(0,i,i,499));
    image.draw(DrawableLine(i,0,499,i));
  }
  //image.matte(true);
  image.composite(sig,350,50,AtopCompositeOp);

  image.display();
//  image.write("composite.png");

  return 0;
}

