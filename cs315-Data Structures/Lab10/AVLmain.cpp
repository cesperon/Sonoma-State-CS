//Author: Christian Esperon
//File: AVLmain.cpp
//Decription: main functions that uses avl tree class to build
//and index using an inputed test file. Calculates the time taken
//to build avl tree and and keeps track of words line numbers as
//well as the number of key comparisons during inseriton.
#include "AVLtree.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main(int argc, char * argv[])
{
  string text;
  cout<<"Enter the name of the text file you would like to index: ";
  cin>>text;

  ifstream file(text.c_str());

  string temp;

  string temp2;

  AvlTree<string> B;

  int lineNumber = 1;

  int insertComp=0;
  
  //boost::timer t;
  //double duration;
  //t.restart();
  double finish_time;
  double start_time = clock();
  while(getline(file,temp))
    {
      
      B.buildTree(temp,lineNumber,insertComp);
      lineNumber++;
      

    }
  //B.printTree();
  
  finish_time = clock ();

  double time =(finish_time - start_time)/ CLOCKS_PER_SEC;

  //duration = t.elapsed();

  B.printTree(time,insertComp);

  


  return 0;
}
