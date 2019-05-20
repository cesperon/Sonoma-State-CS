// File: esperon_Lab2.cpp
// Author: Christian Esperon
// Description: This program will create a red and black checkered board bmp image 
//              as well as a sierpinski gasket bmp image, lastly this function will 
//              read an inputed bmp image and create a fractal pattern and write it 
//              to an output image.

//Easy BMP Library
#include <iostream>
using namespace std;

#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"
#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include "stdlib.h"

using namespace std;

//creates a checkered board pattern by painting certain pixels 
//in a given board black and red depending on which row or column
//the pixel belongs too.
void checkerBoard(BMP & Output)
{
	int picWidth = Output.TellWidth();
	int picHeight = Output.TellHeight();
	int row;
	int col;

	for (int i = 0; i < picWidth-1; ++i)
		for (int j = 0; j<picHeight-1; ++j)
		{
			int row = i/32;
			int col = j/32;

			if (row%2 == 0 and col%2 == 0 or row%2 != 0 and col%2 != 0 )
			{
				Output(i,j)-> Red = 255;
				Output(i,j)-> Blue = 0;
				Output(i,j)-> Green = 0;
			}

			else 
			{
				Output(i,j)-> Red = 0;
				Output(i,j)-> Blue = 0;
				Output(i,j)-> Green = 0;
			}
		}
}

//Repeatedly uses the mid- point forumula on two given points to paint 
//particular pixels red on a blank white bmp image creating a sierpinski 
//gasket bmp image.
void sierpinski(BMP & Output, int Xx, int Xy, int Yx, int Yy, int Zx, int Zy, int Px, int Py)
{
	int picWidth = Output.TellWidth();
	int picHeight = Output.TellHeight();

	for (int i = 0; i<10000; i++)
	{
		int randomNumbergenerator = (rand()%3) +1;

		if (randomNumbergenerator == 1)
		{

			int x = ((Px + Xx)/2);
			int y = ((Py + Xy)/2);

			Output(x,y)-> Red = 255;
			Output(x,y)-> Blue = 0;
			Output(x,y)-> Green = 0;

			Px = x;
			Py = y;
		}

		else if (randomNumbergenerator == 2)
		{

			int x = ((Px + Yx)/2);
			int y = ((Py + Yy)/2);

			Output(x, y)-> Red = 255;
			Output(x, y)-> Blue = 0;
			Output(x, y)-> Green = 0;

			Px = x;
			Py = y;
		}

		else
		{

			int x = ((Px + Zx)/2);
			int y = ((Py + Zy)/2);

			Output(x, y)-> Red = 255;
			Output(x, y)-> Blue = 0;
			Output(x, y)-> Green = 0;

			Px = x;
			Py = y;
		}
	}
}

//scaleImage function takes an input image and output image as parameters
//and scales the output image pixels to half the size of the input image
//pixels
void scaleImage(BMP & Image, BMP & Output)
{
	Output.SetSize(Image.TellWidth()/2, Image.TellHeight()/2);

	for(int i = 0; i < Image.TellWidth()/2; i++)
	{
		for (int j = 0; j < Image.TellWidth()/2; j ++)
		{
			Output(i,j) -> Red = Image(2*i, 2*j) -> Red;
			Output(i,j) -> Blue = Image(2*i, 2*j) -> Blue;
			Output(i,j) -> Green = Image(2*i, 2*j) -> Green;

		}
	}

}
//copies image onto output image using the easyBMP
//RangedPixelToPixelCopy function.
void copy(BMP & Image , BMP & Output, int x, int y)
{
	int image_width = Image.TellWidth();
	int image_height = Image.TellHeight();

	int output_width = Output.TellWidth();
	int output_height = Output.TellHeight();

	//BMP temp;
	//temp.SetSize(image_width, image_height);
	//BMP output1;

	RangedPixelToPixelCopy(Output, 0, output_width -1, 0, output_height - 1, Image, x, y );
}

//Creates a fractal image by using a recursive function to to scale
//the image and write it to the output image.
void Fractal(BMP & Image, BMP & Output)
{
	int size = Output.TellHeight();
	int x = 0;
	int y = size;
	int tileCount = (Image.TellHeight()/ size) -1;

	for(int i = 0; i < tileCount; i++)
	{
		imageScale(Image, Output, size * i, size);
		imageScale(Image, Output, Output.TellWidth() * (tileCount - 1), size + size * i);

	}

	if(Output.TellHeight() > 1)
	{
		BMP smallerTile;
		scaleImage(Output, smallerTile);
		Fractal(Image, smallerTile);
	}
}

int main(int argc, char * argv[])
{       
	BMP board;
	board.SetSize(256,256);
	checkerBoard(board);
	board.WriteToFile(argv[1]);

	BMP myImage;
	myImage.SetSize(256,256);
	sierpinski(myImage, 128, 5, 5, 251, 251, 251, 171, 34);
	myImage.WriteToFile(argv[2]);

	BMP Image;
	BMP Output;
        Image.ReadFromFile("in.bmp");
        copy(Image, Output);
        Fractal(Image, Output);
        Image.WriteToFile(argv[3]);



	return 0;

}
