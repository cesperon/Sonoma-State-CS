//Author: Christian Esperon
//File  : esperonL05.cpp
//Description: Takes in a BMP image, starting point, and end point and
//draws a red line from the starting point to end point using Breadth
//First Seasrch.

#include "EasyBMP.h"
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

class Point {

private:
  int x; int y; 
public:

  Point () {}
  
  Point( int p, int q){
    x = p; y = q;

  }

  bool operator!=(const Point & other)
  {
    if( x != other.x && y != other.y)
      {
	return true;
      }
    else
      {
	return false;
      }
  }

      
  int getx() {
    return x;
  }

  int gety() {
    return y;
  }
    
};


bool isWhite(BMP & Image, int x, int y )
{
  if(Image(x,y)->Red == 255 && Image(x,y)->Green == 255 && Image(x,y)->Blue ==255)
    {
      return true;
    }
  else
    {
      return false;
    }
 
}


void colorToGray(BMP & Output) {
  int picWidth = Output.TellWidth();
  int picHeight = Output.TellHeight();
  Output.SetBitDepth(8);  //compression happens here
  for (int i = 0; i<picWidth-1; ++i)
    for (int j = 0; j< picHeight-1; ++j) {
      int col = 0.1*Output(i, j)->Blue +
	0.6*Output(i,j)->Green + 0.3*Output(i,j)->Red;
      if(col > 127) {
	Output(i,j)->Red = 255;
	Output(i,j)->Blue = 255;
	Output(i,j)->Green = 255;
      }
    }
}
  
void BFS(BMP & Image,Point s, Point t)
{
  int W = Image.TellWidth();
  int H = Image.TellHeight();

  //verify if starting coordinates and ending coordinates are valid
  if(s.getx() <0 || s.gety() <0 || s.getx() > W || s.gety() > H)
    {
      cout<< "invalid starting coordinates"<<endl;
      return;
    }
  if(t.getx() <0 || t.gety() <0  || t.getx() > W || t.gety() > H)
    {
      cout<< "invalid destination coordinates"<<endl;
      return;
    }

  if(!isWhite(Image,s.getx(),s.gety()))
    {
      cout<<"starting coordinate cannot be a black pixel"<<endl;
      return;
    }
  if(!isWhite(Image,t.getx(),t.gety()))
    {
      cout<<"destination coordinate cannot be a black pixel"<<endl;
      return;
    }
      

 int J = W*2;
 int distance[J][J] = {0};
 int Qcount = 0;
 //initialize queue
  queue <Point> Q;

  bool visited[W][W];

  Point parent[W][W];

  for(int j = 0; j<H; j++){
    for(int k = 0; k< W; k++){
      visited[j][k] = false;
    }
  }

  
  visited[s.getx()][s.gety()] = true;

  Q.push(s);
  Qcount++;

 
  while(!visited[t.getx()][t.gety()] && !Q.empty())
    {
      Point temp = Q.front();

      Q.pop();
   

      if(!visited[temp.getx()][temp.gety()-1] && isWhite(Image,temp.getx(), temp.gety()-1))
	{
	  visited[temp.getx()][temp.gety()-1] = true;
	  distance[temp.getx()][temp.gety()-1]+= 1;
	  parent[temp.getx()][temp.gety()-1] = temp;
	  Q.push(Point(temp.getx(), temp.gety()-1));
	  Qcount++;
	}

      if(!visited[temp.getx()-1][temp.gety()] && isWhite(Image,temp.getx()-1, temp.gety()))
	{
	  visited[temp.getx()-1][temp.gety()] = true;
	  distance[temp.getx()-1][temp.gety()]+=1;
	  parent[temp.getx()-1][temp.gety()] = temp;
	  Q.push(Point(temp.getx()-1, temp.gety()));
	  Qcount++;
	}

      if(!visited[temp.getx()+1][temp.gety()] && isWhite(Image,temp.getx()+1, temp.gety()))
	{
	  visited[temp.getx()+1][temp.gety()] = true;
	  distance[temp.getx()+1][temp.gety()] +=1;
	  parent[temp.getx()+1][temp.gety()] = temp;
	  Q.push(Point(temp.getx()+1, temp.gety()));
	  Qcount++;
	}

	if(!visited[temp.getx()][temp.gety()+1] && isWhite(Image, temp.getx(), temp.gety()+1))
	{
	  visited[temp.getx()][temp.gety()+1] = true;
	  distance[temp.getx()][temp.gety()+1]+=1;
	  parent[temp.getx()][temp.gety()+1] = temp;
	  Q.push(Point(temp.getx(), temp.gety()+1));
	  Qcount++;
	}
         
      
    }
  if(visited[t.getx()][t.gety()])
    {
      Point temp1 = t;
      int d = 0;
       while(temp1 != s)
	{
	  Image(temp1.getx(), temp1.gety())-> Red = 255;
	  Image(temp1.getx(), temp1.gety())-> Blue = 0;
	  Image(temp1.getx(), temp1.gety())-> Green = 0;

	  d+=distance[temp1.getx()][temp1.gety()];

	  temp1 = parent[temp1.getx()][temp1.gety()];
	  }
       cout<<"Length of Shortest Path: "<<d<<endl;
       cout<<"Number of Points that Entered the Queue: "<<Qcount<<endl;
    }
 
  return;

}


int main(int argc, char * argv[])
{
  
  BMP Image;

  int W  = Image.TellWidth();
  int H = Image.TellHeight();

  //read in bmp image from file
  Image.ReadFromFile(argv[1]);

  //convert image to black and white
  colorToGray(Image);
 
  int sx, sy;
  int tx, ty;

  //input users starting coordinates
  cout<<endl<<"Enter the x coordinate for the starting position: ";
  cin >> sx;
  cout<<endl;
  cout<<"Enter the y coordinate for the starting postion: ";
  cin>> sy;
  cout<<endl;

  //input users ending coordinates
  cout<<endl<<"Enter the x coordinate for the ending position: ";
  cin >> tx;
  cout<<endl;
  cout<<"Enter the y coordinate for the ending position: ";
  cin>> ty;
  cout<<endl;
  
  //create a starting point with users given input
  Point s = Point(sx, sy);
  //create ending point with users given input
  Point t = Point(tx, ty);

  //perform breadth first search on inputed image with the given
  //starting and ending points
  BFS(Image,s, t);

  //write image to file
  Image.WriteToFile(argv[2]);
    
    
  
  return 0;
}
