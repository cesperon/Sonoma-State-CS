// Assignment : L03a
// File : 
// Author : Christian Esperon
// Date : Spring 2017
// Description :

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isvowel (char  aletter);

// MAXWORDS contains the maximum number of words
const int MAXWORDS = 100;

int main ()
{
  // Declare and open an input file
  ifstream input ("words.txt");
  
  // Array for storing words
  string words [MAXWORDS];
  
  // Read the words in the file into the array
  int count = 0;
  while (input >> words[count])
    {
      count++;
    }
  // Close the input file
  input.close();
  // Write the words and their vowel, consonant, digit
  
  // and special character counts.
  // Starting with the last word in the array.
  int w = count -1;
    while (w>=0)
      {
	int vowelCount = 0;
	int consCount = 0;
	int digitCount = 0;
	int charCount = 0;
	int i = 0;
	while (i < words[w].length())
	  {

	    if (isvowel(words[w][i]))
	     {
               vowelCount++;
	     }
	    else if (isalpha(words[w][i]))
	      {
		consCount++;
	      }
	    else if (isdigit(words[w][i]))
	      {
		digitCount++;
	      }
	    else
	      {
		charCount++;
		  }
	    i++;
	  }
	cout << words[w]<<'\t'<< vowelCount<<'\t'<<consCount
	     <<'\t'<<digitCount<<'\t'<<charCount<<endl;;
	    
	// Analyze the letters in the word

	// Write the vowel, consonant, digit and special character
	// counts. Seperate the parts of the line with tabs.

	w--;
      }
  // Starting with the first word in the array.
  int x = 0;
  while (x < count)
    {
      int vowelCount = 0;
      int consCount = 0;
      int digitCount =0;
      int charCount =0;
      int i = 0;
      while(i<words[x].length())
	{
	  if (isvowel(words[x][i]))
	    {
	      vowelCount++;
	    }
	  else if (isalpha(words[x][i]))
	    {
	      consCount++;
	    }
	  else if (isdigit(words[x][i]))
	    {
	      digitCount++;
	    }
	  else
	    {
	      charCount++;
	    }
	  i++;
	}
      cout << words[x]<<'\t'<<vowelCount<<'\t'
	   <<consCount<<'\t'<<digitCount<<
	'\t'<<charCount<<endl;
      // Analyze the letters in the word

      // Write the vowel, consonant, digit and special character
      // counts. Seperate the parts of the line with tabs.
      x++;
      
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
      
