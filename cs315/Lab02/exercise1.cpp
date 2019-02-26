#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"
#include "EasyBMP.h"
#include "EasyBMP.cpp"

using namespace std;


  
void checkered(BMP & Output)
{
  int picWidth = Output.TellWidth();
  int picHeight = Output.TellHeight();
  int row;
  int col;
  for (int i = 0; i< picWidth-1; ++i)
    for (int j = 0; j<picHeight-1; ++j){
      int row= i/32;
      int col = j/32;
      if (row%2==0 and col%2==0 or row%2!=0 and col%2!=0)
	{
	  Output(i,j)->Red=255;
	  Output(i,j)->Blue =0;
	  Output(i,j)->Green = 0;
	}

      else
	{
	  Output(i,j)->Red=0;
	  Output(i,j)->Blue=0;
	  Output(i,j)->Green=0;
	}
    }
}
      

	
	
      
  
  
  
int main(int argc, char * argv[])
{
  BMP myImage;
  myImage.SetSize(256,256);
  checkered(myImage);
  myImage.WriteToFile(argv[1]);
  return 0;
}
