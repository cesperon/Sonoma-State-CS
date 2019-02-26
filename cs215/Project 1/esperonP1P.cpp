// Assignment :Project 1
// File :esperonP1.cpp
// Author:Christian Esperon
// Date : Spring 17
// Description : This program will read a text file then
// input the words from the text file into an array. The
// program will then sort strings in the file as well as
// calculate the shortest string, longest string, adjacent
// strings with least similarity, adacent strings with greatest
// similarity and  ascending and descending sequences.

#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// MaxWords contains the maximum amount of words
const int MaxWords = 1000;

// Prototypes
void WordSort(string Words [], int N);
void Swap(string & a, string & b);
void WriteReport( string Words[], int count);
void ShortestLongestString(string Words[], int count);
float Similarity(const string & s1, const string & s2);
void LeastGreatestSimilarity(string Words[], int count);

int main()
  {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    // Declare an array to hold the words inputed from
    // the inputed file.
    string words[MaxWords];

    // Declare a variable to open text file.
    ifstream input;

    // Open the text file strings.txt.
    input.open("strings.txt");

    // If input fails create a message telling the user
    // that the file did not work.
    if(input.fail())
      {
	cout<<"your file didnt work.";
      }

    // If input does not fail read the file into the array.
    else
      {
	int count=0;

	while(input>>words[count])
	  {
	    count++;
          }
      
        cout<<"The Strings:"<<endl;

	// Write the file onto the console.
        WriteReport(words,count);

	// Finds the longest string in the word array.
	ShortestLongestString(words,count);
	
	LeastGreatestSimilarity(words,count);
	
	cout<<"\n""\n"<< "Sorted Strings:"<<endl;

	// Sort the word in the file.
	WordSort(words, count);

	// Write the files onto the console.
	WriteReport(words,count);

      }
   
     return 0;
  }

// Function implementations

void Swap(string & a, string & b)
{
  string temp;
  temp=a;
  a=b;
  b=temp;
}

void WordSort(string Words[], int N)
{
  int i =1;
  while (i<N)
    {
      int j =i;
      while(j>0 && Words[j]< Words[j-1])
	{
	  Swap(Words[j], Words[j-1]);
	  j--;
	}
      i++;
    }
}

void WriteReport(string Words[], int count)
{
  for(int i=0, j=1; i< count; i++, j++)
    {
      cout<<setw(12)<<left<<Words[i];
      if(j==7){
	j=0;
	cout<<'\n';
      }
    }
}

void ShortestLongestString(string Words[], int count)
{
  string maxWord = "";
  string minWord = "longestwordthatisreallyreallylong";
  
  for(int i=0; i<count; i++)
    {
      if(Words[i].length() > maxWord.length())
	{
	  maxWord= Words[i];
	}
    }
  
  for(int j= 0; j<count;j++)
    {
      if(Words[j].length() < minWord.length())
	{
	  minWord = Words[j];
	}
    }

  cout<<"\n""\n"<<"Shortest String: "<< minWord;
  cout<<"\n""\n"<<"Longest String: "<< maxWord;
  
}

float Similarity(const string &  s1, const string & s2)
{
  float similar= 0;
  float simpercent;
  float ssize;
  if(s1.length()>s2.length())
    {
      ssize= s1.length();
    }
  else
    {
      ssize= s2.length();
    }
    
  if(s1 == s2)
    {
      similar =ssize;
    }
  else
    {
      for(int i =0; i< ssize; i++)
	{
	  if(s1[i]==s2[i])
	    {
	      similar++;
		}
	}

      
    }
  return (similar/ssize)* 100;	
}
  
void LeastGreatestSimilarity( string Words[], int count)
{
  float Gsim = 0;
  float Lsim = 100;
  string Word1;
  string Word2;
  string Word3;
  string Word4;
  
  for(int i= 0; i<count; i++)
    {
      float Sim= Similarity(Words[i],Words[i+1]);
      
      if(Sim <Lsim)
	{
	  Lsim=Sim;
	  Word1=Words[i];
	  Word2=Words[i+1];
	}
    }
  
  cout<<"\n""\n"<<"Adjacent Strings with Least Similarity: "<<Word1<<
    " "<<Word2<<" ("<<Lsim<<")%";

  for(int i= 0; i< count; i++)
    {
      float Sim = Similarity(Words[i], Words[i+1]);

      if(Sim >Gsim)
	{
	  Gsim = Sim;
	  Word3= Words[i];
	  Word4= Words[i+1];
	}
    }

  cout<<"\n""\n"<<"Adjacent Strings with Greatest Similarity: "<<Word3<<
    " "<< Word4<< " ("<< Gsim<<")%";
}
	
