// Assignment :Lab 03 b
// File :esperonL03b.cpp
// Author :Christian Esperon
// Date :Spring 17
// Description :This program counts every vowel, consonant, digit
//and special character of the inputed txt file and totals them up

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include "Lab04.h"
using namespace std;



// Prototypes for functions used by this program
int ReadFile (ifstream & input, WordData * &  Words);
void WriteReport (ostream & output, WordData Words [], int count);
void Swap (WordData & a, WordData & b);
void WordSort (WordData Words [], int N);
bool isvowel (char aletter);

int main(int argc, char* argv [])
{
  
  // Check to see if the user entered an input file name
  // and an ouput file name. Exit if no file name
  if (argc<3)
    {
      cout<< "Usage: " << argv [0] << "<input-file><output-file>\n";
      exit (1);
    }

  // Open the input file
  ifstream input (argv[1]);


  // Check to see if the file was successfully opened
  // Exit if no file found.
  if (input.fail())
    {
      cout<< "File: "<< argv[1] << " not found\n";
      exit (2);
    }

  // Open the output file
  ofstream output (argv[2]);

  // Check to see if the output file was successfully opened
  // Exit if the file could not be opened
  if (output.fail())
    {
      cout<< "File: " <<argv[2]<< " could not be opened\n";
      exit (3);
    }

  // Declare a pointer to an array of WordData objects to
  // hold the words and their vowel, consonant, digit, and

  // special character counts.
  WordData * WordArray;
  
  // Call the ReadFile function to read the file, store the
  // words in the array and return the number of words read
  // from the file.
  int count = ReadFile (input, WordArray);
  cout<< count<< " words read from the file\n";
   
  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (output, WordArray, count);
  
  // Call the WordSort function to sort the words into
  // alphabetical order.
  WordSort (WordArray, count);
  cout<< endl;
  cout<<" "<<endl;
  
  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (output, WordArray, count);

  output.close();
  return 0;
  
}

// Implementations for functions used by this program



int ReadFile (ifstream & input, WordData * & Words)
{
  int count = 0;
  string oneword;
  // Read and count the words in the file
  while (input >> oneword){
    count++;
  }
  // Allocate space for the number of words counted by the
  // previous loop
  Words = new WordData [count];
  // Clear the fail flag
  input.clear();
  // Reposition the file pointer to the beginning of the file
  input.seekg (0, ios::beg);
  count = 0;
  // Read the words from the file into the array
  while (input >> oneword)
    {
      Words[count].SetWord(oneword);

      count++;

    }
  // Close the file
  input.close();
  // Return the size of the Words array
  return count;
  
}

void WriteReport (ostream & output, WordData Words [], int count)
{ 
  int totalvowels =0,totalconsonants  = 0;
  int totaldigits = 0, totalspecialchars  = 0;

  output << setw(12) << left << "Words";
  output << setw(8) << right << "Vowels";
  output << setw(8) << "Const.";
  output << setw (8) << "Digits";
  output << setw (8) << "Special" << endl;

  int j= i;
  while (j< count);
  {
    output <<setw(12)<< left<< " ";
    output<<setw(8) <<right<<"---";
    output<< setw(8) << "---";
    output <<setw(8)<< "---";
    output << setw(8)<<"---"<<endl;
    output<< setw(12) << left<< "Totals";
    output << setw(8)<<right<<totalvowels;
    output << setw(8) << totalconsonants;
    output << setw(8) << totaldigits;
    output << setw (8) << totalspecialchars<<endl;
  }
  
  
  // loop here to write information about each word
  
  // more code here to write totals data
}

void Swap (WordData & a, WordData & b)
{
  WordData temp;
  temp = a;
  a = b;
  b = temp;
}
04

void WordSort (WordData Words [], int N)
{
  int i =1;
  while (i<N)
    {
      int j = i;
      while (j>0 && Words[j].GetWord() < Words[j-1].GetWord())
	{
	  Swap (Words[j], Words[j-1]);
	  j--;

	}
      i++;
    }
}

bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I'
      || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}
