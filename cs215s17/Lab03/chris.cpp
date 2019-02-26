#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
bool isvowel (char aletter);
// const int MAXWORDS = 100;

struct worddata
{
  worddata ();
  string word;
  int vowels;
  int consonants;
  int digits;
  int specialchars;
};


int ReadFile (ifstream & input, worddata * & Words);
void WriteReport(ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata W [], int N);

int main (int argc, char * argv [])
{
  // Check to see if the user entered a file name
  // Exit if no file name
  if (argc < 2)
    {
      cout << "Usage: " << argv[0] << " <filename>\n";
      exit (1);
    }
  // Open the input file
  ifstream input (argv[1]);
  if (input.fail())
    {
      cout << "File: " << argv[1] << " not found\n";
      exit (2);
    }
  // Declare a pointer to an array of worddata objects
  // to hold the words and their vowel, consonant, digit, and
  // special character counts.
  // worddata WordArray [MAXWORDS];
  worddata * WordArray;

  // Call the ReadFile function to read the file, store the
  // words in the array and return the number of words read
  // from the file.
  int count = ReadFile (input, WordArray);

  // Call the WordSort function to sort the words into
  // alphabetical order.
  WordSort (WordArray, count);

  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (cout, WordArray, count);

  return 0;
}

worddata::worddata ()
{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}

int ReadFile (ifstream & input, worddata * & Words)
{

  int count = 0;
  string oneword;
  // Read and count the words in the file
  while (input >> oneword)
    count++;
  // Allocate space for the number of words counted by the
  // previous loop
  Words = new worddata [count];
  // Clear the fail flag
  input.clear();
  // Reposition the file pointer to the beginning of the file
  input.seekg (0, ios::beg);
  count = 0;

  // Read the words from the file into the array
  while (input >> Words[count].word)
    {
      // Count the number of vowels, consonants, digits
      // and special characters in the word and store them
      // in the object Words [count]

      string aword = Words[count].word;

      // Number of letters in word
      int l = 0;
      while (l < aword.length())
	{
	  if (isvowel(aword[l]))
	    Words[count].vowels++;
	  else if (isalpha(aword[l]))
	    Words[count].consonants++;
	  else if (isdigit(aword[l]))
	    Words[count].digits++;
	  else
	    Words[count].specialchars++;
	  l++;
	}
      count++;
    }
  // Close the file
  input.close ();
  // Return the size of the Words array
  return count;
}

void WriteReport (ostream & output, worddata Words [], int count)
{
  worddata totals;
  totals.vowels, totals.consonants = 0;
  totals.digits, totals.specialchars = 0;

  output << setw (14) << left << "Word";
  output << setw (8) << right << "Vowels";
  output << setw (8) << "Const.";
  output << setw (8) << "Digits";

  output << setw (8) << "Special" << endl;;

  for(int i = 0; i < count; i++)
    {
      output << setw (14) << left << Words[i].word;
      output << setw (8) << right << Words[i].vowels;
      totals.vowels += Words[i].vowels;
      output << setw (8) << Words[i].consonants;
      totals.consonants += Words[i].consonants;
      output << setw (8) << Words[i].digits;
      totals.digits += Words[i].digits;
      output << setw (8) << Words[i].specialchars << endl;
      totals.specialchars += Words[i].specialchars;
    }
  {
    output << setw (14) << left << " ";
    output << setw (8) << right << "---";
    output << setw (8) << "---";
    output << setw (8) << "---";
    output << setw (8) << "---" << endl;
    output << setw (14) << left << "Totals";
    output << setw (8) << right << totals.vowels;
    output << setw (8) << totals.consonants;
    output << setw (8) << totals.digits;
    output << setw (8) << totals.specialchars << endl;
  }
}

void Swap (worddata & a, worddata & b)
{
  worddata t = a;
  a = b;
  b = t;
}

void WordSort (worddata W [], int N)
{
  int i = 1;
  while(i < N)
    {
      int j = i;
      while(j > 0 && W[j].word < W[j-1].word)
	{
	  Swap(W[j], W[j-1]);
	  j--;
	}
      i++;
    }
}

// Returns true/false depeninding if a letter in a word is a vowel or not
bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I' || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}
