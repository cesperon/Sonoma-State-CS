//File: Scan.cpp
//Author: Christian Esperon
//Description: functions used to tokenize a string into
//a vector and determine whether a token is a digit or
//not

#include <vector>
#include <string>

using namespace std;

//This function uses case switches to insert tokens from a string
//into a vector excluding commas and spaces
vector<string> Scan(string S)
{
	vector<string> Output;

	for (int i = 0; i < S.size(); i++)
	{
	  string token;
	  string token1;
	  token1 = "-";
	  
		switch(S[i]){
			case '[':
			  Output.push_back("[");
			  break;

			case ']':
			  Output.push_back("]");
			  break;

			case ',':
			  break;

		        case ' ':
			  break;

		        case '-':

			  while(S[i+1] >= '0' && S[i+1] <= '9')
			    {
			      i++;
			      token1 += S[i];
			    }
			  Output.push_back(token1);
			  break;
			 
		        default:

			  token+=S[i];

			  while(S[i+1] >= '0' && S[i+1] <= '9')
			    {
			      i++;

			      token += S[i];

			    }

			  Output.push_back(token);
			  break;
		}
	}
	return Output;
}

//This function determines whether a given token is a digit

bool isDigit(string S)
{
  if(S[0] >= '0' && S[0] <= '9')
    return true;

  else if(S[0] == '-')
    return true;

  else
    return false;
}


    
