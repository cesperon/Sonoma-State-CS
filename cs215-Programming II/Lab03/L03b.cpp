// Assignment :
// File :
// Author :
// Date :
// Description :

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// MAXWORDS contains the maximum number of words

// Definition of the worddata structure
struct worddata
{
  worddata ();
  string word;
  int vowels;
  int consonants;
  int digits;
  int specialchars;
};
// Prototypes for functions used by this program

int ReadFile (ifstream & input, worddata Words []);
void WriteReport (ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata W [], int N);
bool isvowel (char aletter);

int main ()
{
  // Declare an input file and open "words.txt"

  // Declare an array of worddata objects to hold the words
  // and their vowel, consonant, digit, and special
  // character counts.

  // Call the Readfile function to read the file, store the
  // words in the array and return the number of words read
  // from the file.

  // Call the WriteReport function to write the data
  // store in the array in a formatted fashion.

  // Call the WordSort function to sort the words into
  // alphabetical order.

  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.

  return 0;
}

// Implementations for functions used by this program
worddata::worddata()
{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}

int ReadFile (ifstream & input, worddata Words [])
{
  return 0;
}

void WriteReport (ostream & output, worddata Words [], int count)
{

}

void Swap (worddata & a, worddata & b)
{
}

void WordSort (worddata W [], int N)
{
}

bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I'
      || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}
