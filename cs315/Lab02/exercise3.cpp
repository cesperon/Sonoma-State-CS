#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"
#include "EasyBMP.h"
#include "EasyBMP.cpp"

using namespace std;

BMP fractal(BMP &Image,BMP & Output, int n)
{
  //if(n ==1)
  //return;
  //else{
    n =(n/2);
    Rescale(Image, 'f', n);
    //fractal(Image, Image, n);
    RangedPixelToPixelCopy(Image,0,510,510,0,Output,0,510);
    return Output;
    

  
  
  


}
int main(int argc, char * argv[])
{
  BMP myImage;
  BMP outputImage;
  int imageSize = 1020;
  
  myImage.ReadFromFile(argv[1]);
  outputImage.SetSize(imageSize,imageSize);
  Rescale(myImage, 'f', imageSize);
  fractal(myImage, outputImage, imageSize);
  outputImage.WriteToFile(argv[2]);
  return 0;

}
