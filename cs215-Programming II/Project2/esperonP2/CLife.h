// File: CLife.h
// Add Documentation here

#ifndef CLIFE_H
#define CLIFE_H

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

enum sType {BORDER, EMPTY, ADDING, PERSON, DELETING};

class CLife
{
    public:
        CLife ();
        CLife (const CLife & other);
        ~CLife ();
        CLife & operator = (const CLife & other);
        void Init (int R, int C);
        void Instructions (ostream & outs, istream & ins);
        void Display (ostream & outs);
        void InitRandom ();
        void InitFile (istream & ins);
        void Next ();
        bool Add (int row, int col);
        bool Delete (int row, int col);
        void Message (ostream & outs, char c);
        bool Done ();
    private:
        struct CLifeSquare
        {
                CLifeSquare ();
                void Display (ostream & outs);
                int Reset ();
                sType what;
        };
        int numRows, numCols;
        CLifeSquare ** grid;
        void Evaluate (int row, int col);
        string MakeString () const;
        map <string, int> generationsMap;
        bool evaluating;
        int finished;
        int populationSize;
        int generations;
};

#endif
