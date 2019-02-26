
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// MAXWORDS contains the maximum number of words
const int MAXWORDS = 100;

// Defintion of the worddata structure
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
void WordSort (worddata Words [], int N);
bool isvowel (char aletter);

int main()
{
  // Declare an input file and open "words.txt"
  ifstream input ("words.txt");
  if (input.fail())
    {
      cout<< "File: words.txt not found\n";
      exit (1);
    }

  // Declare an array of worddata objects to hold the words
  // and their vowel, consonant, digit, and special
  // character counts.

  worddata WordArray [MAXWORDS];

  int count = ReadFile (input, WordArray);

  
  // Call the ReadFile function to read the file, store the
  // words in the array and return the number of words read
  // from the file.                                                                                                                                             

  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (cout, WordArray, count);

  // Call the WordSort function to sort the words into
  // alphabetical order.
  WordSort (WordArray, count);

  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (cout, WordArray, count);

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
  int count = 0;
  while (input >> Words[count].word)
    {
      // Complete the following looping and decision code to
      // count the number of vowels, consonants, digits and
      // special characters in the word and store them in
      // the object Words[count]
      string aword = Words[count].word;

      for (int i = 0; i< Words[count].word.length(); i++)
	{
	  if (isvowel (aword[i]))
	    Words[count].vowels++;
	  else if (isalpha(aword[i]))
	    Words[count].consonanats++:
	  else if (isdigit(aword[i]))
	    Words[count].specialchars++;
	}
	      
	count++;

    }
  input.close();
  return count;

}

void WriteReport (ostream & output, worddata Words [], int count)
{
  int totalvowels = 0, totalconsonants = 0;
  int totaldigits = 0, totalspecialchars = 0;

  output << setw(12) << left << "Words";
  output << setw(8) << right << "Vowels";
  output << setw(8) << "Const.";
  output << setw (8) << "Digits";
  output << setw (8) << "Special" << endl;

  // loop here to write information about each word
  cout<< Words[count]; 
    
  // more code here to write totals data
}

void Swap (worddata & a, worddata & b)
{
  worddata temp;
  temp = a;
  a = b;
  b = temp;
}

void WordSort (worddata Words [], int N)
{
  int i =1;
  while (i<N)
    {
      int j = i;
      while (j>0 && Words[j].word < Words[j-1].word)
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
