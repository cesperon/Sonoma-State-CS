// Assignment : Lab 2 b
// File : esperonL02b.cpp
// Date : Spring 2017
// Description : This program reads the file words.txt and identifies each
// character of each word within the file as a vowel, consonant, digit, or
// special character, then it records how many times those characters
// occur.

#include <fstream>
#include <iostream>
using namespace std;

bool isvowel (char aletter);


int main ()
{
  ifstream input;
  string aword;

  input.open ("words.txt");

  while (input >> aword)
   {
     int VowelCount = 0;
     int ConsonantCount = 0;
     int DigitCount = 0;
     int SpecharCount = 0;
     int i = 0;
     while (i < aword.length())
       {
	 if (isvowel(aword[i])){
	   VowelCount++;
	    
	 }
       
         else if (isalpha(aword[i])){
	   ConsonantCount++;
	      
	 }

	 else if (isdigit(aword[i])){
	   DigitCount++;
	 }

	 else{
	   SpecharCount++;
	 }
	   
	 i++;

       }
     
       
       cout << aword << '\t' << aword.length()
	  << '\t' << VowelCount << '\t'
          << ConsonantCount << '\t'<< DigitCount<<
	 '\t'<<SpecharCount<<endl;
   }  
  return 0;
}

bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I'
      || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}




