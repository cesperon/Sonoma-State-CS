// Authors: Christian Esperon, Josh Hernandez
// Project02: Spam Classification
// cs242

#include <iostream>
#include <fstream>
using namespace std;


//void Count(int dict, char grid[][cols], int j[], double n);
double TotalEmail(string trainClass, double & doc1, double & doc2);


int main()
{
  //declare string variable to hold training data, training class, test data, and testclass.
  string trainData;
  string trainClass;
  string testData;
  string testClass;

  // ask user to input data files.
  cout<<"Enter the names of the training data, training class, test data and test class files (in that order): ";

  // input data to strings
  cin>> trainData;
  cin>> trainClass;
  cin>> testData;
  cin>> testClass;

  // initialize class counters
  double S = 0;
  double I = 0;
  double S1=0;
  double I1=0;
  double total = TotalEmail(trainClass, S, I);
  double total1 = TotalEmail(testClass,S1,I1);

  cout<<"Training using "<< total <<" cases"<<endl;

  cout<<"Evaluating "<< total1 << " test cases"<<endl;

  // Prob of class S,I documents
  double probS = S/total;
  double probI = I/total;

  // define dictionary
  const int dict = 48;

  // define grids to hold class S,I documents.
  char Sgrid [int(S)][dict];
  char Igrid [int(I)][dict];


  //read in data to grids
  ifstream traindata;
  traindata.open(trainData);
  ifstream trainclass;
  trainclass.open(trainClass);

  char Class;
  char Data;
  int s =0;
  int a=0;

  
  while(trainclass >> Class)
    {
      if (Class =='1' && s < int(S))
	{
	  for (int j = 0; j< dict; j++)
	    {
	      traindata >> Data;
	      Sgrid[s][j] = Data;
	    }
	  s++;
	}
      else if(Class == '0' && a < int(I))
	{
	  for (int b = 0; b< dict; b++)
	    {
	      traindata >> Data;
	      Igrid[a][b] =Data;
	    }
	  a++;
	}
    }
  

  traindata.close();
  trainclass.close();

  int countS [dict];
  int countI [dict];

  int *Sc;
  int *Ic;

  Sc = countS;
  Ic = countI;

  
  //counts the number of times S occurs in training data
  
  for (int col = 0; col < dict; col ++)
    {
      int wcount = 0;

      for(int row = 0; row < int(S); row++)
	{
	  if(Sgrid[row][col] == '1')
	    {
	      wcount++;
	    }
	}
       Sc[col] = wcount;
       }
 
  //counts the number of times I occurs in training data
  
  for (int col = 0; col < dict; col++)
    {
      int wcount = 0;
      for(int row = 0; row < int(I); row++)
	{
	  if (Igrid[row][col] == '1')
	    {
	      wcount++;
	    }
	}
	  Ic[col] = wcount;
	  }


  // calculate the liklihood that word occurs in S
  double word_probI [dict];
  double word_probS [dict];
  
  for (int i = 0; i < dict; i++)
   {
      word_probS[i] = Sc[i] / S;
    }

  // calculate the liklihood that word occurs in I

  for (int i = 0; i < dict; i ++)
    {
      word_probI[i] = Ic[i] / I;
      }


  ifstream I_file;
  I_file.open(testData);
  ifstream T_file;
  T_file.open(testClass);

  char checkClass;

  char q;

  //initialize posterior probability of both classes
  double liklihoodS = 1;
  double liklihoodI = 1;

  //initialize spam ham testclass checks
  double spam = 0;
  double ham = 0;

  // caclulate posterior probability
  for(int c = 0; c < total1; c++)
    {
      liklihoodS =1;
      liklihoodI =1;
      for (int i = 0; i < dict; i++)
        {
           I_file >> q;
           if (q =='1')
	     { liklihoodS *= word_probS[i];
	       liklihoodI *= word_probI[i];
	     }

           else if (q =='0')
	     {
	       liklihoodS *= (1 - word_probS[i]);
	       liklihoodI *= (1- word_probI[i]);
	     }
	}
  

      double posteriorS = probS * liklihoodS;

      double posteriorI = probI * liklihoodI;
      
      T_file >> checkClass;
      
       if(posteriorS > posteriorI)
	{
	  if(checkClass == '1')
	    {
	      spam = spam +1;
	    }
	}

      else if (posteriorI > posteriorS)
	{
	  if(checkClass == '0')
	    {
	      ham = ham +1;
	    }
	}
    
    }

  //output detection rate in percentages
  cout << "Successful detection rate of " << ((spam+ham)/total1) * 100 <<'%'<<endl;

 
  return 0;
}


//Implementation of functions 
//calculates total emails in training data 
double TotalEmail(string filename, double & doc1, double & doc2)
{
  char c;
  double totalMail =0;

  ifstream file;
  file.open(filename);

  while (file >> c)
    {
      if(c== '1')
	{
	  doc1 += 1;
	}
      else if (c == '0')
	{
	  doc2 += 1;
	}

      totalMail += 1;
    }
   file.close();

  return totalMail;
}
/*
void Count(int dict, char grid[][col], int j, double n) 
for (int col = 0; col < dict; col ++)
  {
    int wcount = 0;

    for(int row = 0; row < int(n); row++)
      {
	if(grid[row][col] == '1')
	  {
	    wcount++;
	  }
      }
    j[col] = wcount;
  }

*/
