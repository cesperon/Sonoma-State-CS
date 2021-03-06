// Title: Lab4 WordData class and implementaion
// Author: Christian Esperon
// Description: WordData class to be used by the
// main function.

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const bool testing = false;

class WordData
{
 public:
  WordData ();
  WordData (const WordData & OtherWord);
  ~WordData ();
  int GetNumVowels () const;
  int GetNumConsonants () const;
  int GetNumDigits () const;
  int GetNumSpecialChars () const;
  void SetWord (const string & InWord);
  string GetWord () const;
  void WriteData (ostream & outs) const;
  bool operator > (const WordData & OtherWord) const;

 private:
  string word; // C++ string to hold the word
  int vowels; // vowel counter
  int consonants; // consonant counter
  int digits; // digit counter
  int specialchars; // special character counter

};

// Function implementations will be placed after this line


WordData::WordData()
{ // The default constructor
  if (testing)
    cout<< "The default constructor has been called "
	<< "for address: " << this << endl;
  
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}


WordData::WordData (const WordData & OtherWord)
{ // The copy constructor
  if (testing)
    cout<< "The copy constructor has been called "
	<< "for address " << this << endl;
  
  word = OtherWord.word;
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;
}

WordData::~WordData()
{ // The destructor
  if (testing)
    cout<< "The destructor has been called "
	<< "for address " << this << endl;
  
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
{ // The SetWord function
  if (testing)
    cout << "The SetWord function has been called "
	 << "for address " << this << endl;
  
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
{ // The GetWord function.
  if (testing)
    cout << "The GetWord function has been called "
	 << "for address" << this << endl;
  
  return word;
}

void WordData::WriteData (ostream & outs) const
{ // The WriteData function.
  if (testing)
    cout<< "The WriteData function has been called "
	<< "for address" << this << endl;
  
  outs<<setw(15)<<left<<word;
  outs<<setw(8)<<right<<vowels;
  outs<<setw(8)<<consonants;
  outs<<setw(8)<<digits;
  outs<<setw(8)<<specialchars<<endl;
}
  
int WordData::GetNumVowels () const
{
  return vowels;
}

int WordData::GetNumConsonants () const
{
  return consonants;
}

int WordData::GetNumDigits () const
{
  return digits;
}

int WordData::GetNumSpecialChars () const
{
  return specialchars;
}

bool WordData::operator > (const WordData & OtherWord) const 
{
  if(word.length() > OtherWord.GetWord().length())
    {
      return true;
    }
  else if (word.length() < OtherWord.GetWord().length())
    {
      return false;
    }
  else if (word.length() == OtherWord.GetWord().length())
    {
      if (word > OtherWord.GetWord())
	{
	  return true;
	}
      else if(word <= OtherWord.GetWord())
	{
	  return false;
	}
    }
}
#endif
