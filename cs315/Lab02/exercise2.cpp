#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"
#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include "stdlib.h"

using namespace std;

void Sierpinski(BMP & Output, int Xx, int Xy, int Yx, int Yy, int Zx, int Zy, int Px, int Py)
{
  int picWidth = Output.TellWidth();
  int picHeight = Output.TellHeight();
  for(int i=0; i<10000; i++){
    int randint = (rand()%3) +1;
    if (randint==1){

      int x = ((Px + Xx)/2);
      int y = ((Py + Xy)/2);

      Output(x, y)->Red = 255;
      Output(x, y)->Blue = 0;
      Output(x, y)->Green = 0;

      Px= x;
      Py= y;
    }

    else if(randint==2){

      int x = ((Px + Yx)/2);
      int y = ((Py + Yy)/2);

      Output(x, y)->Red = 255;
      Output(x, y)->Blue = 0;
      Output(x, y)->Green = 0;

      Px= x;
      Py= y;
    }

    else{

      int x = ((Px + Zx)/2);
      int y = ((Py + Zy)/2);

      Output(x, y)->Red = 255;
      Output(x, y)->Blue = 0;
      Output(x, y)->Green = 0;

      Px= x;
      Py=y;
    }
  }
}

  



int main( int argc, char* argv[])
{

  BMP myImage;
  myImage.SetSize(256,256);
  Sierpinski(myImage,128, 5, 5, 251, 251, 251, 171, 34);
  myImage.WriteToFile(argv[1]);
  return 0;
}
