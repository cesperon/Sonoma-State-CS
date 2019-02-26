//
//  main.cpp
//  rgb
//
//  Created by Gurman Gill on 2/7/17.
//  Copyright © 2017 Gurman Gill. All rights reserved.
//

#include <iostream>
using namespace std;

enum class color: uint
{
   
      bitMask = 0xFFFFFFFF,
 
       
	};

int main(int argc, const char * argv[]) {

  cout << "Enter a RGBA color value (e.g. 255 127 51 0): ";

  uint pixel;
  uint pixel1;
  uint pixel2;
  uint pixel3;
  
  cin>> pixel; 
  cin>> pixel1;
  cin>> pixel2;
  cin>> pixel3;

 
  // Use bitwise AND to isolate individual color channels red, green, blue and   alpha) from this pixel

  uint redChannel = pixel<<24;
  uint greenChannel = pixel1<<16;
  uint blueChannel = pixel2<<8;
  uint alphaChannel = pixel3;

  // Right shift the value into the range 0-255 and store it into an uint8_t (1 byte integer)
  int  red = redChannel & uint(color::bitMask);
  int green = greenChannel & uint(color::bitMask);
  int blue = blueChannel & uint(color::bitMask);
  int alpha = alphaChannel & uint(color::bitMask);

  int rG= red | green;
  int rgB= rG | blue;
  int rgbA = rgB | alpha;

  cout<<"Your color in hexadecimal is: "<<hex<<rgbA<<endl;;

  return 0;
}
