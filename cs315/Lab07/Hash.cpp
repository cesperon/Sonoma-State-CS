
//Author: Christian Esperon
//file: Hash.cpp
#include <boost/timer.hpp>
#include "time.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "SeparateChaining.cpp"
#include <cstdlib>

using namespace std;

class Moves{

public:

  int from; int mid; int to;

  Moves () {}

  Moves(int f, int m, int t){

    from = f; mid = m; to =t;

  }


};

int isPowerOfTwo(long long int n)
{
  return n && (! (n &(n-1)));
}
	       
int findPosition(long long int gB)
{
  if(!isPowerOfTwo(gB))
    return -1;

  long long int i = 1, pos =1;

  while (!(i & gB))
    {
      i = i <<1;

      ++pos;
    }
  return pos;
}
bool solved(long long int gB)
{
  int count = 0;

  while(gB)
    {
      count +=gB & 1;
      gB >>=1;
    }

  if(count == 1)
    {
      return true;
      cout<<findPosition(gB);
	}

  else return false;

}

//checks to see if peg is red
bool isRed(vector<int> & M, int peg)
{
  if(M[0] == peg){
    return true;
  }
  else{
    return false;
  }
}
 

//modify to make red bit unjumpable
long long int makeMove(long long int gB, Moves m,vector<int> & initPegs)
{//64 vs 63

  /* 
 if(isRed(initPegs, m.from))
    {
      gB = (gB ^ (1LL<<(63-m.from)));
      gB = (gB ^ (1LL<<(63-m.mid)));
      gB = (gB ^ (1LL<<(63-m.to)));

     
      }*/
 if(isRed(initPegs,63- m.mid))
   {
     gB = ( gB ^ (1LL<<(63-m.from)));
     gB = ( gB ^ (1LL<<(63-m.to)));
     //return gB;
     }
 else
   {
       gB= ( gB ^ (1LL <<(63 - m.from)));

       gB= ( gB ^(1LL <<(63 - m.mid)));

       gB= ( gB ^( 1LL <<(63 - m.to)));
       //return gB;

   }
 return gB;

 
}

bool contains(vector<int> gB, int n)
{
  int gbSize = gB.size()-1;
  for(int i = 0; i<= gB.size()-1; i++)
    {
      if(gB[i] == n)
	return true;

    }

  return false;
}

bool isBitSet(long long int gB, int k)
{
  if(gB & (1LL <<( k)))
    return true;

  else
    return false;

}

bool validMove(long long int gB, int from, int mid, int to,vector<int> & initPegs)
{
  //checks if moves are happening in four corners of the board which is considered out of bounds
   if(from == 63 || from == 62 || from == 58 || from == 57 || from == 56 || from == 55 || from == 51 || from == 50 || from == 28 || from == 27 || from == 23 || from ==22
     || from == 21 || from == 20 || from == 16 || from ==15)
    {
      return false;
    }
  
  if(mid == 63 || mid == 62 || mid == 58 || mid == 57 || mid == 56 || mid == 55 || mid == 51 || mid == 50 || mid == 28 || mid == 27 || mid == 23 || mid ==22
     || mid == 21 || mid == 20 || mid == 16 || mid ==15)
    {
      return false;
    }

  if(to == 63 || to == 62 || to == 58 || to == 57 || to == 56 || to == 55 || to == 51 || to == 50 || to == 28 || to == 27 || to == 23 || to ==22
     || to == 21 || to == 20 || to == 16 || to ==15)
    {
      return false;
    }
  

  //checks if moves are happening beyond the scope of the board, cant be greater than 63 or less than 15
  if(from > 63 || mid > 63 || to > 63)
    {
      return false;
    }

  if(from < 15 || mid < 15 || to < 15)
    {
      return false;
    }

  //check if from has a peg && mid has a peg && to doesn't have a peg if so move is valid
  //and if mid bit is not red
  if (isBitSet(gB,from) && isBitSet(gB,mid) && !isBitSet(gB,to))
    {
     
      return true;

      
    }
   
  if (isRed(initPegs,from))
    {
      return false;
      }
  else
    return false;
  

  
}

vector<Moves> nextMoves( long long int gB,vector<int> & initPegs )
{
  vector<Moves> M;
  for(int i = 63; i >=15; i--)
    {
      //declare directions from peg
      int north = i + 7;
      int south = i - 7;
      int east = i - 1;
      int west = i + 1;

      //declare jumping positon from peg
      int northJump = i + 14;
      int southJump = i - 14;
      int eastJump = i - 2;
      int westJump = i + 2;

      //check if north jump is valid if so push to moves vector
      if(validMove(gB,i, north, northJump,initPegs))
	{
	  Moves temp = Moves(i, north, northJump);
	  M.push_back(temp);
	}
      //check if south jump is valid if so push to moves vector
      if(validMove(gB,i, south, southJump,initPegs))
	{
	  Moves temp1 = Moves(i,south,southJump);
	  M.push_back(temp1);
	}
      //check if east jump is valid if so push to moves vector
      if(validMove(gB,i, east, eastJump,initPegs) && east != 42 && eastJump != 42 && east != 35 && eastJump != 35)
	{
	  Moves temp2 = Moves(i, east, eastJump);
	  M.push_back(temp2);
	}
      //check if west jump is valid if so push to moves vector
      if(validMove(gB, i, west, westJump,initPegs) && west != 36 && westJump !=36 && west != 43 && westJump !=43)
	{
	  Moves temp3 = Moves(i, west, westJump);
	  M.push_back(temp3);
        }


    }

  

  return M;
}
 
long long int setUP(vector<int> B)
{

  //using horners rule to initiate game board
  long long int gB = 0;

  for(int i= 0; i<= 63; i++)
    {

       long long int s = 0;

      if( contains( B, i)){

	  s=1;
	 
	}

      gB= 2 *gB + s;
    }

  return gB;
      
		   
}

bool solve( long long int & gB, vector<Moves> & M, vector<int> & initPegs)
{
 
  if(solved(gB))
    {
     
      return true;
    }

  vector<Moves> curMov = nextMoves(gB,initPegs);
 
   for(int i = 0; i < curMov.size(); i++)
    {
      
      Moves temp1 = Moves(63-curMov[i].from, 63-curMov[i].mid, 63-curMov[i].to);
      long long int y = makeMove(gB,temp1,initPegs);
      if (solve( y,M,initPegs))
	{
	  gB= y;
	  M.push_back(temp1);
	  return true;
	}
    }
  return false;
}

bool hsolve(long long int& gB, vector<Moves> & M, HashTable<long long int> & H, vector<int>& initPegs)
{
  if(solved(gB))
    return true;

  vector<Moves> curMov = nextMoves(gB,initPegs);

  for(int i = 0; i< curMov.size(); i++)
    {
      Moves temp1 = Moves(63 - curMov[i].from, 63 - curMov[i].mid, 63- curMov[i].to);
      long long int y = makeMove(gB, temp1,initPegs);
      if(!H.contains(y))
	{
	  if(hsolve(y,M,H,initPegs))
	    {
	      gB = y;
	      M.push_back(temp1);
	      return true;
	    }
	  else
	    H.insert(y);
	}
    }
  return false;
}
	      

int main()
{
  string initBoard;
  cout<<"Welcome to Peg Solitiare!"<<endl;
  cout<<"-------------------------"<<endl;

  cout<<"Please enter name of text file to begin."<<endl;
  cin>>initBoard;
  cout<<endl;
  ifstream inputFile;
  inputFile.open(initBoard.c_str());

  //declare vector to hold values of where
  //beginning pegs are placed
  vector<int> pegs;

  

  //initialize peg solitaire gameboards to be use with different
  //sizes of HashTables
  long long int gameBoard;
  long long int gameBoard1;
  long long int gameBoard2;
  long long int gameBoard0;
  
  if(inputFile){

    int value;

    while(inputFile>> value){
      pegs.push_back(value);
    }

  }

  else
    cout<<"txt file not recognized"<<endl;

  inputFile.close();

  vector<int> & pegVal = pegs;
   

  //set up gameboard according to user input
  //of peg locations
  gameBoard = setUP(pegs);
  gameBoard1 = setUP(pegs);
  gameBoard2 = setUP(pegs);
  gameBoard0 = setUP(pegs);

  //display the setup gameBoard
  cout<<"<<Binary number representation of starting game board>>"<<endl;
  for (int i = 63; i>=0; i--){
    cout<<((gameBoard >> i) & 1);
  }
  cout<<endl;
  cout<<"----------------------------------------------------------------"<<endl;

  int option;

  
  
  while(option !=3)
    {
     
      cout<<"Options: (1) solve using DFS with no hash table (2) solve using DFS using hash table (3) quit "<<endl;

      cin>>option;
      
      if(option ==1)
	{
	  //using DFS to solve with no HashTable
	  vector<Moves> * winMove0 = new vector<Moves>;
	  vector<Moves> & win = *winMove0;

	  boost::timer t0;
	  double duration0;
	  t0.restart();
	  solve(gameBoard0,win,pegVal);
	  duration0 = t0.elapsed();
	  if( solve(gameBoard0,win,pegVal))
	    {
	      /*
	      for(int i =0; i<=pegVal.size() -1; i++)
		{
		  cout<<pegVal[i]<<" ";
		}
	      */
	      cout<<"Soultion With No HashTable: "<<endl;
	      
	      for(int i =win.size()-1; i>= 0; i--)
		{
		  cout<<"("<<win[i].from<<" "<<win[i].mid<<" "<<win[i].to<<")";
		  }
	      cout<<endl<<endl;
	      cout<<"Execution Time With No HashTable: "<< duration0<<endl<<endl;
	      cout<<"<<Binary number representation of winning game board>>"<<endl;
	      for(int i = 63; i>=0; i--)
		{
		  cout<<((gameBoard0>>i) & 1);
		}


	      cout<<endl;
	      cout<<"----------------------------------------------------------------"<<endl;
	     
	      // printHash(gameBoard0, win);

	    }
	  else
	    cout<<"No Solutions"<<endl;

	}
      /*
      if(option ==2)
	{
	  //HashTable size 10000
	  HashTable<long long int> failedBoards(10000);
	  vector<Moves> * winMov = new vector<Moves>;
	  vector<Moves> & vr = *winMov;

	  boost::timer t;
	  double duration;
	  t.restart();
	  hsolve(gameBoard,vr,failedBoards,pegVal);
	  duration = t.elapsed();

	  if( hsolve(gameBoard,vr,failedBoards,pegVal))
	    {
	      cout<<"Soultion With HashTable Size 10000: "<<endl;
	      for(int i =vr.size()-1; i>= 0; i--)
		{
		  cout<<"("<<vr[i].from<<" "<<vr[i].mid<<" "<<vr[i].to<<")";
		}
	      cout<<endl<<endl;
	      cout<<"Execution Time With HashTable Size 10000: "<< duration<<endl<<endl;
	      cout<<"<<Binary number representation of winning game board>>"<<endl;
	      for(int i = 63; i>=0; i--)
		{
		  cout<<((gameBoard>>i) & 1);
		}


	      cout<<endl;
	      cout<<"----------------------------------------------------------------"<<endl;

	    }
	  else
	    cout<<"No Solutions"<<endl;
	  
          //HashTable size 50000
	  HashTable<long long int> failedBoards1(50000);
	  vector<Moves> * winMov1 = new vector<Moves>;
	  vector<Moves> & vr1 = *winMov1;

	  boost::timer t1;
	  double duration1;
	  t1.restart();
	  hsolve(gameBoard1,vr1,failedBoards1,pegVal);
	  duration1= t1.elapsed();
	  if( hsolve(gameBoard1,vr1,failedBoards1,pegVal))
	    {
	      cout<<"Soultion With HashTable Size 50000: "<<endl;
	      for(int i =vr1.size()-1; i>= 0; i--)
		{
		  cout<<"("<<vr1[i].from<<" "<<vr1[i].mid<<" "<<vr1[i].to<<")";
		}
	      cout<<endl<<endl;
	      cout<<"Execution Time with HashTable Size 50000: "<< duration1<<endl<<endl;
	      cout<<"<<Binary Number Representation of Winning Game Board>>"<<endl;
	      for(int i = 63; i>=0; i--)
		{
		  cout<<((gameBoard1>>i) & 1);
		}
	      cout<<endl;
	      cout<<"----------------------------------------------------------------"<<endl;

	    }

	  //HashTable size 100000
	  HashTable<long long int> failedBoards2(100000);
	  vector<Moves> * winMov2 = new vector<Moves>;
	  vector<Moves> & vr2 = *winMov2;

	  boost::timer t2;
	  double duration2;
	  t2.restart();
	  hsolve(gameBoard2,vr2,failedBoards2,pegVal);
	  duration2 = t2.elapsed();
	  if( hsolve(gameBoard2,vr2,failedBoards2,pegVal))
	    {
	      cout<<"Soultion With HashTable Size 100000: "<<endl;
	      for(int i =vr2.size()-1; i>= 0; i--)
		{
		  cout<<"("<<vr2[i].from<<" "<<vr2[i].mid<<" "<<vr2[i].to<<")";
		}
	      cout<<endl<<endl;
	      cout<<"Execution Time with HashTable Size 100000: "<< duration2<<endl<<endl;
	      cout<<"<<Binary Number Representation of Winning Game Board>>"<<endl;
	      for(int i = 63; i>=0; i--)
		{
		  cout<<((gameBoard2>>i) & 1);
		}
	      cout<<endl;
	      cout<<"----------------------------------------------------------------"<<endl;

	    }
	  
	    }*/

      if(option ==3)
	{
	  exit(0);
	}
    }


  return 0;
}
