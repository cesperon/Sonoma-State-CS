// Title: Lab4 WordData class and implementaion
// Author:
// Description:

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

bool isvowel(char aletter);

class WordData
{
 public:
  WordData ();
  WordData (const WordData & OtherWord);
  ~WordData ();
  void SetWord (const string & InWord);
  string GetWord () const;
  void WriteData (ostream & outs) const;

 private:
  string word; // C++ string to hold the word
  int vowels; // vowel counter
  int consonants; // consonant counter
  int digits; // digit counter
  int specialchars; // special character counter

};

// Function implementations will be placed after this line


WordData::WordData()
{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}


WordData::WordData (const WordData & OtherWord)
{
  word = OtherWord.word;
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;
}

WordData::~WordData()
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

void WordData::SetWord (const string & InWord)
{
  word = InWord;
    for(int i = 0; i<word.length(); i++)
      {
	if(isalpha(word[i]))
	  {
	    if(isvowel (word[i]))
	      {
		vowels++;
	      }
	    else
	      {
		consonants++;
	      }
	  }
	else if(isdigit(word[i]))
	  {
	    digits++;
	  }
	else
	  {
	    specialchars++;
	  }
      }

}

string WordData::GetWord () const
{
  return word;
}

void WordData::WriteData (ostream & outs) const
{
  outs<<setw(12)<<left<<word;
  outs<<setw(8)<<right<<vowels;
  outs<<setw(8)<<consonants;
  outs<<setw(8)<<digits;
  outs<<setw(8)<<specialchars<<endl;
}
  
  
#endif
