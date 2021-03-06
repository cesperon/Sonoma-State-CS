// Title: Driver Program for Lab 7
// File id: Lab07app.cpp
// Author:
// Description: This program will instantiate a vector of WordDatas.
// The program will then read words from a file and store them in the
// vector. The program will then print the contents of the vector.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "WordData.h"

using namespace std;

void ReadWords (int argc, char * argv [], vector <WordData> & WDV);
void WriteWords (ostream & outs, const vector <WordData> & WDV);

int main (int argc, char * argv [])
{
	vector <WordData> words;
	cout << "\nPushing a WordData onto the end of the vector\n";
	words.push_back (WordData ("5, 17"));
	cout << "\nReading words from the file\n";
	ReadWords (argc, argv, words);
	cout << "\nWriting words to standard output\n";
	WriteWords (cout, words);

	cout << "\nFinding the sum of all of the words in the vector\n";
	WordData sum;
	for (int i = 0; i< words.size(); i++)
	  sum = sum + words[i];
	cout << "The sum of the words is " << sum << endl;

	cout << "\nSorting words vector\n";
	sort (words.begin(), words.end());
	cout << "\nWriting sorted words to standard output\n";
	WriteWords (cout, words);

	cout << "\nErasing first word from the vector\n";
	words.erase (words.begin());
	cout << "\nWriting modified words to standard output\n";
	WriteWords (cout, words);

	cout << "\nInserting first word into the vector\n";
	words.insert (words.begin(), WordData ("6, 5"));
	cout << "\nWriting modified words to standard output\n";

	WriteWords (cout,words);

	cout << "\nPopping last word from the vector\n";
	words.pop_back();
	cout << "\nWriting modified words to standard output\n";
	WriteWords (cout, words);

	cout << "\nClearing remaining words from the vector\n";
	words.clear ();
	cout << "\nWriting modified words to standard output\n";
	WriteWords (cout, words);
	
	return 0;
}

void ReadWords (int argc, char * argv [], vector <WordData> & WDV)
{
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " <filename>\n";
		exit (1);
	}
	ifstream ins (argv[1]);
	if (ins.fail())
	{
		cout << "File " << argv[1] << " not found\n";
		exit (2);
	}
	WordData aword;
	while (ins >> aword)
	{
	  //cout << "\nReading and doing a push_back of a single word\n";
		WDV.push_back (aword);
	}
	ins.close ();
}

void WriteWords (ostream & outs, const vector <WordData> & WDV)
{
	outs << "The words are:\n";
	for (int i = 0; i < WDV.size(); i++)
	  outs << ' ' << WDV[i]<< endl;
	outs << endl;
}
