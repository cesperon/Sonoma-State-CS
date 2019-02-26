// Title: WordData class and implementaions
// Author: Christian Esperon
// Description: WordData class implementations, functions to
// to be use by a WordData object.

#include "WordData.h"

WordData::WordData()
{ // WordData Constructor, will initialize WordData type objects when
  // they are created.
  length = 0;
  word = new char [1];
  word[0] = '\0';
  vowels = consonants = digits = specialchars=0;

}


WordData::WordData (const string & Inword)
{// Initialize WordData, SetWord to Inword.
  length = 0;
  word = new char [1];
  word [0] = '\0';
  vowels = consonants = digits = specialchars =0;
  SetWord(Inword);
}


WordData::WordData (const WordData & OtherWord)
{ // The copy constructor will copy another WordData objects values
  // to its own.
  if (testing)
    cout<< "The copy constructor has been called "
	<< "for address " << this << endl;
  length = OtherWord.length;
  word = new char [1+length];
  strcpy (word, OtherWord.word);
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;
}

WordData::~WordData()
{ // The destructor will deallocate WordData objects memory.
  if (testing)
    cout<< "The destructor has been called "
	<< "for address " << this << endl;
  delete [] word;
  
}

bool isvowel (char aletter)
{// will return true if aletter is a vowel if not
  // wiil return false.
  
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I'
      || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}

void WordData::SetWord (const string & InWord)
{ // The SetWord function will allow the user to change the value
  // of the word to their desired preferences.
  if (testing)
    cout << "The SetWord function has been called "
	 << "for address " << this << endl;
  
  delete [] word;
  length = InWord.length();
  word = new char [1 + length];
  strcpy (word, InWord.c_str());
  vowels = consonants = digits = specialchars = 0;
  for (int i =0; i<length; i++)
    if (isalpha (word[i]))
      switch (toupper (word[i]))
	{
	  case 'A': case 'E': case 'I':
	  case 'O': case 'U':
	    vowels++; break;
	  default:
	    consonants++;
	}
    else if (isdigit (word[i]))
      digits++;
    else
      specialchars++;
    
   
}

string WordData::GetWord () const
{ // The GetWord function will return the current word.
  
  if (testing)
    cout << "The GetWord function has been called "
	 << "for address" << this << endl;
  
  return word;
}

void WordData::WriteData (ostream & outs) const
{ // The WriteData function will write the data out onto the console
  
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
{// This function will return the number of vowels.
  return vowels;
}

int WordData::GetNumConsonants () const
{//This function will return the number of consononants.
  return consonants;
}

int WordData::GetNumDigits () const
{//This function will return the number of digits.
  return digits;
}

int WordData::GetNumSpecialChars () const
{//This function will return the number of special characters.
  return specialchars;
}

bool WordData::operator > (const WordData & OtherWord) const 
{// This function will overload the greather than function
  // to return true if one object is bigger than the other
  // and false when it is smaller.
  
  if(length > OtherWord.length)
    {
      return true;
    }
  if(length < OtherWord.length)
    {
      return false;
    }
  string one = word;
  for ( int i =0; i< one.length(); i++)
    {
      one[i] = tolower(one[i]);
    }

  string two = OtherWord.word;
  for ( int i = 0; i< two.length(); i++)
    {
      two[i] = tolower(two[i]);
    }
  return one > two;

}

bool WordData::operator < (const WordData & OtherWord) const
{
  //Less than operator which returns true when a WordData object is less
  // than another WordData object and false when it is larger than another
  //WorData object.
  if (length < OtherWord.length)
    return true;
  if (length > OtherWord.length)
    return false;
  string one = word;
  for (int i = 0; i< one.length(); i++)
    one[i] = tolower(one[i]);
  string two = OtherWord.word;
  for (int i =0; i< two.length(); i++)
    two[i] = tolower(two[i]);
  return one < two;
}
WordData & WordData::operator = (const WordData & OtherWord)
{
  // Test for self-assignment. If this and the address of OtherWord
  // are the same, return the object referenced by this:
  if (this == &OtherWord)
    return * this;

  // Delete the existing word
  delete [] word;
  // copy the length of Otherword
  length = OtherWord.length;
  // Allowcate space for the new word
  word = new char [1 + length];
  // Copy the new word from OtherWord into word
  strcpy (word, OtherWord.word);

  // Copy the remaining attributes of OtherWord into the
  // corresponding attributes of this:
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;

  // Return the object referenced by this:
  return * this;
}

bool WordData::operator == (const WordData & OtherWord)const
{// This function will test for equality, and returns true if
  // two objects are equal and false if they are not.
  
  if(strcmp (word, OtherWord.word) == 0)
    return true;
  return false;
}

bool WordData:: operator != (const WordData & OtherWord)const
{// This function will test for un-equivalency, will return true
  // if two functions are not equivalent and false if they are
  if(strcmp (word, OtherWord.word) == 0)
    return false;
  return true;
}

WordData WordData::operator + (const WordData & OtherWord) const
{// This function will add two WordData objects together adding up
  // their vowels, digits, consonants, and special chars.
  WordData sum;

  sum.length = length + OtherWord.length;
  sum.word = new char [1 + sum.length];
  strcpy (sum.word, word);
  strcat (sum.word, OtherWord.word);
  sum.vowels = vowels + OtherWord.vowels;
  sum.consonants = consonants + OtherWord.consonants;
  sum.digits = digits + OtherWord.digits;
  sum.specialchars = specialchars + OtherWord.specialchars;

  return sum;
}

ostream & operator << (ostream & outs, const WordData & w)
{// Output operator will output WordData object values onto
  //the console.
  cout<<setw(12)<<left<< w.word;
  cout<<setw(8)<<right<< w.vowels;
  cout<<setw(8)<<right<< w.consonants;
  cout<<setw(8)<<right<< w.digits;
  cout<<setw(8)<<right<< w.specialchars;

  return outs;
}

istream & operator >> (istream & ins, WordData & w)
{// Input operator input string into WordData object.
  string astring;
  ins>> astring;
  if (!ins.fail())
    {
      w.SetWord(astring);
    }
  return ins;
}


