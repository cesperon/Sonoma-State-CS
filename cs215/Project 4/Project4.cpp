/***************************************************************
 * Project: Project 4
 * File: Project4.cpp
 * Author: Christian Esperon
 * Project:
 * Description: An application file that will test OrderedSets
 * with different data types which include string, WordData, 
 * integers, and user defined types.
****************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "OrderedSet.hpp"
#include "WordData.h"
using namespace std;

//Function headers for data testing functions.
int WordDataTest (string file);
int IntTest ();
void StringTest (string file);


int main(int argc, char * argv [])
{
  //Create a string variable.
  string txtFile;

  //Ask user for input.
  cout<<"Enter txt file: ";

  //Read in input into string.
  cin>>txtFile;

  //WordData test.
  WordDataTest(txtFile);

  //String test.
  StringTest(txtFile);

  //Integer test.
  IntTest();


  return 0;
}

//Function Implementations

//This function will test a WordData type in an OrderedSet.
int WordDataTest (string file)
{

  cout<<"\nTesting OrderedSet with WordData:\n\n";
  ifstream input (file.c_str());
  WordData oneword;
  OrderedSet<WordData>WD;
  while (input>>oneword)
    WD.Insert (oneword);
  input.close();
  OrderedSet<WordData>::Iterator itr;
  cout<<"From first to last:\n";
  for (itr = WD.begin(); itr != WD.end(); itr++)
    cout<<'\t'<<*itr<<endl;
  cout<< "From last to first:\n";
  for (itr = WD.rbegin(); itr != WD.rend(); --itr)
    cout <<'\t' <<*itr <<endl;
  cout << "End of OrderedSet with WordData test\n";
  
  return 0;
}

//This function will test an integer in an OrderedSet.
int IntTest ()
{
  cout<<"Testing OrderedSet with integers:\n";
  OrderedSet<int> R;
  OrderedSet<int> L;
  srand(time(NULL));
  int val = rand() % 10;
  int val1 = rand() % 2;
  for (int n= 1; n< 10; n++)
    {
      R.Insert(n+val1);
      L.Insert(n+val);
    }

  cout << L << endl<<endl;

  OrderedSet<int>::Iterator itr;
  cout<<"First Ordered Set from first to last:\n";
  for (itr = L.begin(); itr != L.end(); itr++)
    cout<<'\t'<<*itr<<endl;
  cout<< "First Ordered Set from last to first:\n";
  for (itr = L.rbegin(); itr != L.rend(); --itr)
    cout <<'\t' <<*itr <<endl;

  OrderedSet<int>::Iterator itr2;
  cout<<"Second Ordered Set from first to last:\n";
  for (itr2 = R.begin(); itr !=R.end(); itr2++)
    cout<<'\t'<<*itr2<<endl;
  cout<<"Second Ordered Set from last to first:\n";
  for(itr2 = R.rbegin(); itr != R.rend(); --itr)
    cout<<'\t'<<*itr2 <<endl;

  
  return 0;

}

//This function will test a string data type in an OrderedSet.
void StringTest (string file)
{
    
  cout<<"\nTesting OrderedSet with string: \n";
  ifstream input (file.c_str());
  string oneword;
  OrderedSet<string>WD;
  while (input>>oneword)
    WD.Insert(oneword);
  input.close();
  OrderedSet<string>::Iterator itr;
  cout<<"From first to last:\n";
  for (itr = WD.begin(); itr != WD.end(); itr++)
    cout<<'\t'<<*itr<<endl;
  cout<< "From last to first:\n";
  for (itr = WD.rbegin(); itr != WD.rend(); --itr)
    cout <<'\t' <<*itr <<endl;
  cout << "End of OrderedSet with WordData test\n\n";
  
}
