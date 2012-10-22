//Author:Ian Cooper
//Date: May 5, 2008
//Some ImageMagickness... So frustrating. 


#include <iostream>
#include <cstdlib>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main() {

  Image image("500x500","white");

//colors for the gradient
double start_R=46.0/255, start_G=250.0/255, start_B=104.0/255;
double end_R=48.0/255, end_G=62.0/255, end_B=248.0/255;
double t;
ColorRGB myColor;

//my gradient
for(int i=0;i<500; i++){
  t=i/499.0;
  myColor = ColorRGB(start_R-t*(start_R-end_R), start_G-t*(start_G-end_G), start_B-t*(start_B-end_B));
  image.fillColor(myColor);
  image.draw(DrawableLine(i,0,i,499));
 }


// some swirling...
image.swirl(720.0);



image.fillColor("black");

//some nezumis
image.annotate("NEZUMI","100x20+20+245");
image.annotate("NEZUMI","100x20+429+245");
image.annotate("NEZUMI","100x20+225+89");
image.annotate("NEZUMI","100x20+225+400");
image.annotate("NEZUMI","100x20+124+179");
image.annotate("NEZUMI","100x20+124+320");
image.annotate("NEZUMI","100x20+319+179");
image.annotate("NEZUMI","100x20+319+320");

//my grid
for(int i=0; i<250; i+=5){
  //i like the ones after this....
  image.draw(DrawableLine(0,0,499,125));
  image.draw(DrawableLine(0,249-i/2,249+i,0));
  image.draw(DrawableLine(0,124-i/2,499,i/2));
  image.draw(DrawableLine(499,249-i/2,249-i,0));

  image.draw(DrawableLine(0,499,499,374)); 
  image.draw(DrawableLine(0,249+i/2,249+i,499));
  image.draw(DrawableLine(0,374+i/2,499,499-i/2));
  image.draw(DrawableLine(499,249+i/2,249-i,499));
 }

image.annotate("Ian Cooper 2008","100x20+205+245");

//still cant figure out how to get this in the pic as anything other than a big white box with a mouse in the middle. 
//Image mouse("mouse.jpg");
//mouse.composite(image,0,0,AtopCompositeOp);

image.write("out.gif");
image.display();

return 0;
}

