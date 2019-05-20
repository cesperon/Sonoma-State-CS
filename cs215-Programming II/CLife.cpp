// File: CLife.cpp
// Add Documentation here

#include <ctime>
#include <cstdlib>
#include "CLife.h"

CLife::CLifeSquare::CLifeSquare ()
{
// This function will:

        what = BORDER;
}

void CLife::CLifeSquare::Display (ostream & outs)
{
// This function will:

                string dispString;
                switch (what)
                {
                        case EMPTY:
                                dispString = ".";
                                break;
                        case ADDING:
                                dispString = "*";
                                break;
                        case PERSON:
                                dispString = "X";
                                break;
                        case DELETING:
                                dispString = "#";
                                break;
                        default:
                                dispString = "B";
                }
                outs << dispString;
}

int CLife::CLifeSquare::Reset ()
{
// This function will:

        return 0;
}

CLife::CLife ()
{
// This function will:

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
// This function will:

        for (int r = 0; r < numRows+2; r++)
                delete [] grid[r];
        delete [] grid;
}

void CLife::Init (int R, int C)
{
// This function will:

        for (int r = 0; r < numRows+2; r++)
                delete [] grid[r];
        delete [] grid;
        generationsMap.clear();
        numRows = R;
        numCols = C;
        grid = new CLifeSquare * [numRows+2];
        for (int r = 0; r < numRows+2; r++)
            grid[r] = new CLifeSquare [numCols+2];
        for (int r = 1; r <= numRows; r++)
                for (int c = 1; c <= numCols; c++)
                        grid[r][c].what = EMPTY;
        finished = 0;
        evaluating = true;
        populationSize = 0;
        generations = 1;
}

void CLife::Instructions (ostream & outs, istream & ins)
{
// This function will:

        outs << endl;
        outs << "Put the title of your grame here\n\n";
        outs << "Put the instructions for playing your game here.\n";
        outs << endl;
}


void CLife::Display (ostream & outs)
{
// This function will:

        for (int r = 1; r <= numRows; r++)
        {
                for (int c = 1; c <= numCols; c++)
                        grid[r][c].Display (outs);
                outs << endl;
        }
}

void CLife::InitRandom ()
{
// This function will:

}

void CLife::InitFile (istream & ins)
{
// This function will:

}

void CLife::Next ()
{
// This function will:

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
// This function will:

        return true;
}

bool CLife::Delete (int row, int col)
{
// This function will:

        return true;
}

void CLife::Message (ostream & outs)
{
// This function will:

        string message = "Thank you for playing!\n";
        outs << endl << message << endl;
}

bool CLife::Done () 
{
// This function will:

        return finished != 0;
}

void CLife::Evaluate (int row, int col)
{
// This function will:

}

string CLife::MakeString () const
{
// This function will:

        return "";
}
