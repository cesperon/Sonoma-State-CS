//Author: Christian Esperon
//file: Hash.cpp
//Description: Compares performance between separate-chaining
//linear hashing, quadratic-probing, double hashing

#include <time.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "SeparateChaining.cpp"
#include "QuadraticProbing.cpp"
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

bool solved(long long int gB)
{
  int count = 0;

  while(gB)
    {
      count +=gB & 1;
      gB >>=1;
    }

  if(count == 1)
    return true;

  else return false;

}


long long int makeMove(long long int gB, Moves m)
{
 
 gB= ( gB ^ (1LL <<(63 - m.from)));

 gB= ( gB ^(1LL <<(63 - m.mid)));

 gB= ( gB ^( 1LL <<(63 - m.to)));

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

bool validMove(long long int gB, int from, int mid, int to)
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
  if (isBitSet(gB,from) && isBitSet(gB,mid) && !isBitSet(gB,to))
    {
     
      return true;

      
    }
  else
    return false;
  

  
}

vector<Moves> nextMoves( long long int gB )
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
      if(validMove(gB,i, north, northJump))
	{
	  Moves temp = Moves(i, north, northJump);
	  M.push_back(temp);
	}
      //check if south jump is valid if so push to moves vector
      if(validMove(gB,i, south, southJump))
	{
	  Moves temp1 = Moves(i,south,southJump);
	  M.push_back(temp1);
	}
      //check if east jump is valid if so push to moves vector
      if(validMove(gB,i, east, eastJump) && east != 42 && eastJump != 42 && east != 35 && eastJump != 35)
	{
	  Moves temp2 = Moves(i, east, eastJump);
	  M.push_back(temp2);
	}
      //check if west jump is valid if so push to moves vector
      if(validMove(gB, i, west, westJump) && west != 36 && westJump !=36 && west != 43 && westJump !=43)
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

bool solve( long long int& gB, vector<Moves> & M)
{
 
  if(solved(gB))
    {
      return true;
    }

   vector<Moves> curMov = nextMoves(gB);
 
   for(int i = 0; i < curMov.size(); i++)
    {
      Moves temp1 = Moves(63-curMov[i].from, 63-curMov[i].mid, 63-curMov[i].to);
      long long int y = makeMove(gB,temp1);
      if (solve( y,M))
	{
	  gB= y;
	  M.push_back(temp1);
	  return true;
	}
    }
  return false;
}

bool hsolve(long long int & gB, vector<Moves> & M, HashTable<long long int> & H, HashTableClosed<long long int>& HC, int j,int & Sprobes,int & probes,vector<int> & insertProbes, vector<int> & searchProbes)
{
  
  //separate chaining
  if(j == 1)
    {
      if(solved(gB))
	return true;

      vector<Moves> curMov = nextMoves(gB);

      for(int i = 0; i< curMov.size(); i++)
	{
	  Moves temp1 = Moves(63 - curMov[i].from, 63 - curMov[i].mid, 63- curMov[i].to);
	  long long int y = makeMove(gB, temp1);
	  if(!H.contains(y,Sprobes))
	    {
	      searchProbes.push_back(Sprobes);
	      Sprobes = 0;
	      if(hsolve(y,M,H,HC,j,Sprobes,probes,insertProbes,searchProbes))
		{
		  gB = y;
		  M.push_back(temp1);
		  return true;
		}
	      else
		{
		  H.insert(y,probes);
		  insertProbes.push_back(probes);
		  probes = 0;
		}
	    }
	}
      return false;
    }
  /////linear Hashing
  if(j == 2)
    {
      if(solved(gB))
	return true;

      vector<Moves> curMov = nextMoves(gB);

      for(int i = 0; i< curMov.size(); i++)
	{
	  Moves temp = Moves(63 - curMov[i].from, 63 - curMov[i].mid, 63- curMov[i].to);
	  long long int y = makeMove(gB, temp);
	  if(!HC.contains(y,j,Sprobes))
	    {
	      searchProbes.push_back(Sprobes);
	      Sprobes = 0;
	      if(hsolve(y,M,H,HC,j,Sprobes,probes,insertProbes,searchProbes))
		{
		  gB = y;
		  M.push_back(temp);
		  return true;
		}
	      else
		{
		  HC.insert(y,j,probes);
		  insertProbes.push_back(probes);
		  probes = 0;
		}
	    }
	}
      return false;
    }
  //////Quadratic Probing
  if(j == 3)
    { 
      if(solved(gB))
	return true;

      vector<Moves> curMov = nextMoves(gB);

      for(int i = 0; i< curMov.size(); i++)
	{
	  Moves temp = Moves(63 - curMov[i].from, 63 - curMov[i].mid, 63- curMov[i].to);
	  long long int y = makeMove(gB, temp);
	  if(!HC.contains(y,j,Sprobes))
	    {
	      searchProbes.push_back(Sprobes);
	      Sprobes = 0;
	      if(hsolve(y,M,H,HC,j,Sprobes,probes,insertProbes,searchProbes))
		{
		  gB = y;
		  M.push_back(temp);
		  return true;
		}
	      else
		{
		  HC.insert(y,j,probes);
		  insertProbes.push_back(probes);
		  probes = 0;
		}
	    }
	}
      return false;
    }

  ///////Double hashing
  if(j == 4)
    {
      if(solved(gB))
	return true;

      vector<Moves> curMov = nextMoves(gB);

      for(int i = 0; i< curMov.size(); i++)
	{
	  Moves temp = Moves(63 - curMov[i].from, 63 - curMov[i].mid, 63- curMov[i].to);
	  long long int y = makeMove(gB, temp);
	  if(!HC.contains(y,j,Sprobes))
	    {
	      searchProbes.push_back(Sprobes);
	      Sprobes = 0;
	      if(hsolve(y,M,H,HC,j,Sprobes,probes,insertProbes,searchProbes))
		{
		  gB = y;
		  M.push_back(temp);
		  return true;
		}
	      else
		{
		  HC.insert(y,j,probes);
		  insertProbes.push_back(probes);
		  probes = 0;
		}
	      
	    }
	}
      return false;
    }
  
  
}

void printHash(long long int & gB, vector<Moves> & M)
{
  cout<<"Soultion:"<<endl;
  for(int i =M.size()-1; i>= 0; i--)
    {
      cout<<"("<<M[i].from<<" "<<M[i].mid<<" "<<M[i].to<<")"<<endl;
    }
  cout<<endl;
  cout<<"<<Binary number representation of winning game board>>"<<endl;
  for(int i = 63; i>=0; i--)
    {
      cout<<((gB>>i) & 1);
    }


  cout<<endl;
  cout<<"----------------------------------------------------------------"<<endl;
  



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
  long long int gameBoard3;
  
  if(inputFile){

    int value;

    while(inputFile>> value){
      pegs.push_back(value);
    }

  }

  else
    cout<<"txt file not recognized"<<endl;

  inputFile.close();
   

  //set up gameboard according to user input
  //of peg locations
  gameBoard = setUP(pegs);
  gameBoard1 = setUP(pegs);
  gameBoard2 = setUP(pegs);
  gameBoard3 = setUP(pegs);

  //display the setup gameBoard
  cout<<"<<Binary number representation of starting game board>>"<<endl;
  for (int i = 63; i>=0; i--){
    cout<<((gameBoard >> i) & 1);
  }
  cout<<endl;
  cout<<"----------------------------------------------------------------"<<endl;

  //Call Hsovle for j =1 corresponding to separate chaining
  HashTableClosed<long long int> failedB0(10007);
  HashTable<long long int> failedBoards0(10007);
  vector<Moves> * winMov0 = new vector<Moves>;
  vector<Moves> & vr0 = *winMov0;
  //declare int counter to count number of insert probes in separate chaining
  int probes = 0;
  int & p = probes;
  //declare int counter to count number of search probes in separate chaining
  int Sprobes = 0;
  int & Sp = Sprobes;
  //declare vector to hold probe count for each insert operation
  vector<int> insertProbe0;
  vector<int> & iP0 = insertProbe0;
  //declare vector to hold probe count for each search operation
  vector<int> searchProbe0;
  vector<int> & sP0 = searchProbe0;
  

  double finish_time;
  double start_time = clock();
  hsolve(gameBoard3,vr0,failedBoards0,failedB0,1,Sp,p,iP0,sP0);

  finish_time=clock();
  double time= (finish_time - start_time)/ CLOCKS_PER_SEC;

  if( hsolve(gameBoard3,vr0,failedBoards0,failedB0,1,Sp,p,iP0,sP0))
    {
      cout<<"Separate Chaining"<<endl;
      cout<<"time take: "<<time<<endl;
      int sum =0;
      for(int i = 0; i <= iP0.size()-1; i++)
	{
	  sum+=iP0[i];
	}
      cout<<"total insert probes: "<<sum<<endl;
      cout<<"average insert probes: "<<sum/iP0.size()<<endl;

      int Ssum0 = 0;
      for(int i = 0; i<= sP0.size()-1; i++)
	{
	  Ssum0 += sP0[i];
	}

      cout<<"total search probes: "<<Ssum0<<endl;
      cout<<"average search probes: "<<Ssum0/sP0.size()<<endl<<endl;

      

    }
  else
    cout<<"No Solutions"<<endl;
  
  //Call Hsolve for j = 2 corresponding to linear hashing
  HashTableClosed<long long int> failedB(10007);
  HashTable<long long int> failedBoards(10007);
  vector<Moves> * winMov = new vector<Moves>;
  vector<Moves> & vr = *winMov;
  //declare int counter to count number of insert probes for linear hashing
  int probes1 = 0;
  int & p1 = probes1;
  //declare int counter to count number of search probes for linear hashing
  int Sprobes1 = 0;
  int & Sp1 = Sprobes1;
  //declare vector to hold probe count for each insert operation
  vector<int> insertProbe;
  vector<int> & iP = insertProbe;
  //declare vector to hold probe count for each search operation
  vector<int> searchProbe;
  vector<int> & sP = searchProbe;

  double finish_time1;
  double start_time1 = clock();
  hsolve(gameBoard,vr,failedBoards,failedB,2,Sp1,p1,iP,sP);

  finish_time1=clock();
  double time1= (finish_time1 - start_time1)/ CLOCKS_PER_SEC;

  if( hsolve(gameBoard,vr,failedBoards,failedB,2,Sp1,p1,iP,sP))
    {
      cout<<"linear Hashing"<<endl;
      cout<<"time taken: "<< time1<<endl;
      //declare int variable to hold sum of probes in vector
      int sum1 =0;
      for(int i = 0; i <= iP.size()-1; i++)
	{
	  sum1+=iP[i];
	}
      cout<<"total insert probes: "<<sum1<<endl;
      cout<<"average insert probes: "<<sum1/iP.size()<<endl;

      int Ssum = 0;
      for(int i = 0; i<= sP.size()-1; i++)
	{
	  Ssum += sP[i];
	}
      
      cout<<"total search probes: "<<Ssum<<endl;
      cout<<"average search probes: "<<Ssum/sP.size()<<endl<<endl;
      

    }
  else
    cout<<"No Solutions"<<endl;

  //Call Hsolve for j = 3 corresponding Quadratic Probing
  HashTableClosed<long long int> failedB1(10007);
  HashTable<long long int> failedBoards1(10007);
  vector<Moves> * winMov1 = new vector<Moves>;
  vector<Moves> & vr1 = *winMov1;
  //declare int counter to count number of insert probes for quadratic probing
  int probes2 = 0;
  int & p2 = probes2;
  //declare int counter to count number of search probes in quadratic probing
  int Sprobes2 = 0;
  int & Sp2 = Sprobes2;
  //declare vector to hold probe count for each insert operation
  vector<int> insertProbe1;
  vector<int> & iP1 = insertProbe1;
  //declare vector to hold probe count for each search operation
  vector<int> searchProbe1;
  vector<int> & sP1 = searchProbe1;

  double finish_time2;
  double start_time2 = clock();
  hsolve(gameBoard1, vr1, failedBoards1, failedB1,3,Sp2,p2,iP1,sP1);
  finish_time2=clock();
  double time2 = (finish_time2- start_time2)/CLOCKS_PER_SEC;
  if(hsolve(gameBoard1, vr1, failedBoards1, failedB1,3,Sp2,p2,iP1,sP1))
    {
      cout<<"Quadratic Hashing"<<endl;
      cout<<"time taken: "<<time2<<endl;
      //declare int varaible to hold sum of probes in vector
      int sum=0;
      
      for(int i = 0; i <= iP1.size()-1; i++)
	{
	  sum +=iP1[i];
	}
      cout<<"total insert probes: "<<sum<<endl;
      cout<<"average insert probes: "<<sum/iP1.size()<<endl;

      int Ssum1 = 0;
      for(int i = 0; i<= sP1.size()-1; i++)
	{
	  Ssum1 += sP1[i];
	}

      cout<<"total search probes: "<<Ssum1<<endl;
      cout<<"average search probes: "<<Ssum1/sP1.size()<<endl<<endl;
      

      
    }
  else
    cout<<"No Solutions"<<endl;

  //Call Hsolve for j = 4 corresponding to Double Hashing
  HashTableClosed<long long int> failedB2(10007);
  HashTable<long long int> failedBoards2(10007);
  vector<Moves> * winMov2 = new vector<Moves>;
  vector<Moves> & vr2 = *winMov2;
  //declare int counter to count number of insert probes in double hashing
  int probes3 = 0;
  int & p3 = probes3;
  //declare int counter to count number of search probes in double hashing
  int Sprobes3 = 0;
  int & Sp3 = Sprobes3;
  //declare vector to hold probe count for each insert operation
  vector<int> insertProbe2;
  vector<int> & iP2 = insertProbe2;
  //declare vector to hold probe count for each search operation
  vector<int> searchProbe2;
  vector<int> & sP2 = searchProbe2;
  

  double finish_time3;
  double start_time3 = clock();
  hsolve(gameBoard2, vr2, failedBoards2, failedB2, 4,Sp3,p3,iP2,sP2);
  finish_time3=clock();
  double time3 = (finish_time3- start_time3)/CLOCKS_PER_SEC;
  if(hsolve(gameBoard2, vr2, failedBoards2, failedB2,4,Sp3,p3,iP2,sP2))
    {
      cout<<"Double Hashing"<<endl;
      cout<<"time taken: "<<time3<<endl;
      //declare int variable to hold sum of probes in vector
      int sum2 = 0;
      for(int i = 0; i < iP2.size(); i++)
	{
	  sum2+=iP2[i];
	}
      cout<<"total insert probes: "<<sum2<<endl;
      cout<<"average insert probes: "<<sum2/iP2.size()<<endl;

      int Ssum2 = 0;
      for(int i = 0; i<= sP2.size()-1; i++)
	{
	  Ssum2 += sP2[i];
	}

      cout<<"total search probes: "<<Ssum2<<endl;
      cout<<"average search probes: "<<Ssum2/sP2.size()<<endl<<endl;
      

      
    }
  else
    cout<<"No Solutions"<<endl;

  printHash(gameBoard2, vr2);
 

  

  
 

  return 0;
}
