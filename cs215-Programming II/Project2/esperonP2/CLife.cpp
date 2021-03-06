// File: CLife.cpp
// AUTHOR: Christian Esperon.
// Description: These functions will create a "Conways Game of Life" gameboard, then
// initialize the gameboard through useres preference. The game will then play out the 
// rules of the game on existing cells on the gameboard.The game will end once either
// of these things happen:Either the population dies out, becomes static or user quits
// the game.

#include <ctime>
#include <cstdlib>
#include "CLife.h"
#include <iomanip>


CLife::CLifeSquare::CLifeSquare ()
{
// This function will: set all CLife squares to borders when a CLife object
// is called.

        what = BORDER;
}

void CLife::CLifeSquare::Display (ostream & outs)
{
// This function will: output the displaystring accoring to the value of what.

                string dispString;
                switch (what)
                {
                        case EMPTY:
                                dispString = "  ";
                                break;
                        case ADDING:
                                dispString = "++";
                                break;
                        case PERSON:
                                dispString = "8D";
                                break;
                        case DELETING:
                                dispString = "XX";
                                break;
                        default:
                                dispString = "BB";
                }
                outs << dispString;
}

int CLife::CLifeSquare::Reset ()
{
// This function will:turn ADDING cells into PERSON and DELETING cells
// into EMPTY. IF cell is equivalent to ADDING function will return 1.
// If cell is equivalent to DELETING function will return -1. Else
// return 0.
  
  if (what == ADDING)
    {
      what = PERSON;
      return 1;
	}

  if (what == DELETING)
    {
      what = EMPTY;
      return -1;
    }
  
  return 0;

        
}

CLife::CLife ()
{
// This function will: construct a CLife object whenever it is called.

        numRows = 1;
        numCols = 1;
        grid = new CLifeSquare * [numRows+2];
        for (int r = 0; r < numRows+2; r++)
            grid[r] = new CLifeSquare [numCols+2];
        //grid[1][1].what = EMPTY;
        evaluating = true;
        finished = 0;
	populationSize = 0;
	generations = 0;
}

CLife::~CLife ()
{
// This function will: deallocate memory once CLife object is no longer in use.

        for (int r = 0; r < numRows+2; r++)
                delete [] grid[r];
        delete [] grid;
}

void CLife::Init (int R, int C)
{
// This function will: initialize the CLife object.

        for (int r = 0; r < numRows+2; r++)
                delete [] grid[r];
        delete [] grid;
        generationsMap.clear();
        numRows = R;
        numCols = C;
        grid = new CLifeSquare * [numRows+2];
        for (int r = 0; r < numRows+2; r++)
            grid[r] = new CLifeSquare [numCols+2];
        for (int r = 1; r <= (numRows); r++)
	  for (int c = 1; c <= (numCols); c++)
	       grid[r][c].what = EMPTY;
	    
        finished = 0;
        evaluating = true;
        populationSize = 0;
        generations = 1;
}

void CLife::Instructions (ostream & outs, istream & ins)
{
// This function will: display the game instructions.

        outs << endl;
        outs <<setw(20)<<right<< "Conway's Game of Life *<Special Edition>*\n\n";
        outs<<setw(23)<<right <<"[RULES]\n\n";
	outs <<setw(20)<<right<< "{Simply chose how you want to populate}\n";
	outs<<setw(20)<<right<< "{the board then watch the magic happen}\n\n";
	outs<<setw(25)<<right<<"[SYMBOL KEY]\n\n";
	outs<<setw(24)<<right<<"8D = PERSON\n";
	outs<<setw(26)<<right<<"XX = DELETING\n";
	outs<<setw(24)<<right<<"++ = ADDING\n";
	
        outs << endl;
}


void CLife::Display (ostream & outs)
{
// This function will: display the CLife gameboard as well as the current population
// and generation.
  
  char letter = 65;
  cout << "  ";

  for (int c = 1; c <= numCols; c++)
    {
      
      cout << "|  ";
      cout << letter << " ";
      letter++;
    }
  cout << "|" << endl; 
  
  letter = 65;
  
        for (int r = 1; r <= numRows; r++)
        {
	  cout << " " << "-";

	  for (int z = 0; z < numCols * 2.5; z++)
	    {
	      cout << "--";
	    }
	  
      	  cout << endl;
	  cout << letter;
	  letter++;
	  
                for (int c = 1; c <= numCols; c++)
		  {
		    cout << " | ";
		    
                        grid[r][c].Display (outs);
		  }
		
                outs << " | " << endl;
        }

	cout << endl;

	cout<< "Population Size [" << populationSize << "] | Generations [" << generations <<"]"<< endl<< endl<<endl;
	

}

void CLife::InitRandom ()
{
// This function will: randomly seed the gameboard using srand.
  
  srand(time(0));

  int rand1 = numRows;
  int rand2 = numCols;
  

  for (int i = 1; i<20; i++)
    {
      int r =( rand() % rand1)+1  ;
      int c = (rand() % rand2)+1  ;

      Add(r, c);
    }

  

}

void CLife::InitFile (istream & ins)
{
// This function will: initialize the board with an input file.

  int rows, cols;
  ins >> rows >> cols;
  Init(rows, cols);
  char filetype;
  ins >> filetype;

  if(filetype == 'G')
    {
      string lines;

      for( int r =1; r< rows; r++)
	{
	  ins >> lines;

	  for(int i = 0; i< lines.length(); i++)
	    {
	      if(lines[i] == 'X')
		{
		  Add(r, i +1);
		    }
	    }
	}
    }
  if (filetype == 'P')
    {
      int r;
      int c;

      while(ins >> r >> c)
	{
	  Add(r,c);
	}
    }
}



  void CLife::Next ()
{
// This function will: determine the next stage of the gameboard.

        if (evaluating)
                for (int r = 1; r <= numRows; r++)
                        for (int c = 1; c <= numCols; c++)
			    Evaluate (r, c);
			  
	
        else
        {
                for (int r = 1; r <= numRows; r++)
                        for (int c = 1; c <= numCols; c++)
                                populationSize += grid[r][c].Reset ();
                string mapStr = MakeString ();
                map<string, int>::iterator itr = generationsMap.find (mapStr);
                if (itr == generationsMap.end())
                {
                        generations++;
                        generationsMap [mapStr] = generations;
                }
                else
                {
                        finished = itr->second;
                }
        }
        if (populationSize == 0)
                finished = -2;
        evaluating = !evaluating;
}

bool CLife::Add (int row, int col)
{
// This function will: add a PERSON cell to the grid.

  if(row > numRows || col > numCols)
    {
      return false;
    }

  if(grid[row][col].what == PERSON)
    {
      return false;
    }

  grid[row][col].what = PERSON;

  populationSize++;

        return true;
}

bool CLife::Delete (int row, int col)
{
// This function will: delete a PERSON cell from the grid.
  
  if(grid[row][col].what == EMPTY)
    {
      return false;
    }
  grid[row][col].what = EMPTY;
   
        return true;
}

void CLife::Message (ostream & outs, char c)
{
// This function will: output quitting message if user quits as well as a thank
// you message once game has finished.
  
  if(c== 'q')
    {
      cout<<"YOU HAVE ENTERED THE Q KEY GAME IS NOW QUITTING...\n"<<endl;
    }

  else
    {
       string message = "Thank you for playing!\n";
       outs << endl << message << endl;
    }
    
}

bool CLife::Done () 
{
// This function will: determin if CLifce board is finished.

  if (finished ==0)
    {
      return false;
     
    }
  
     
  else
    {
      if (populationSize ==0 )
	{
	  cout<<"OH NO THE POPULATION HAS DIED OUT!"<<endl;
	}
 
      else
	{
          cout<<"THE POPULATION HAS BECOME STATIC"<<endl;
	}
      return true;
    }
       
}

void CLife::Evaluate (int r, int c)
{
// This function will: evaluate the status of a cell on the gameboard.

  int neighbors = 0;
  
  if ((grid[r-1][c-1].what) == PERSON || grid[r-1][c-1].what == DELETING)
    {
      neighbors ++;
    }
  if ((grid[r-1][c].what) == PERSON || grid[r-1][c].what == DELETING)
    {
      neighbors ++;
    }
  if ((grid[r-1][c+1].what) == PERSON || grid[r-1][c+1].what == DELETING)
    {
      neighbors ++;
    }
  if ((grid[r][c-1].what) == PERSON || grid[r][c-1].what == DELETING)
    {
      neighbors++;
    }
  if ((grid[r][c+1].what) == PERSON || grid[r][c+1].what == DELETING)
    {
      neighbors ++;
    }
  if ((grid[r+1][c-1].what) == PERSON || grid[r+1][c-1].what == DELETING)
    {
      neighbors ++;
    }
  if ((grid[r+1][c].what) == PERSON || grid[r+1][c].what == DELETING)
    {
      neighbors ++;
    }
  if ((grid[r+1][c+1].what)  == PERSON || grid[r+1][c+1].what == DELETING)
    {
      neighbors ++;
    }

	  
  
   if(grid[r][c].what == EMPTY && neighbors ==3)
     {
       grid[r][c].what = ADDING;
     }
   if ((grid[r][c].what == PERSON) && (neighbors == 2 || neighbors == 3))
     {
       grid[r][c].what = PERSON;
     }
   if (grid[r][c].what == PERSON && neighbors > 3)
     {
      grid[r][c].what = DELETING;
     }
   if(grid[r][c].what == PERSON && neighbors < 2)
     {
      grid[r][c].what = DELETING;
     }

  

}

string CLife::MakeString () const
{
// This function will: return a string type representing EMPTY and PERSON cells in the gameboard.

  string cellString;

  for (int r = 1; r <= numRows; r++)
    {
      for (int c=1; c <= numCols; c++)
	{
	  if (grid[r][c].what == EMPTY)
	    {
	      cellString += "O";
		}
	  else if(grid[r][c].what == PERSON)
	      {
		cellString += "X";
		  }
	}
    }
	

        return cellString;
}

