//Description: Prototypes for the binary search tree class.

#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class TTT{
    public: 
        TTT();
        void contains() const;
        bool isEmpty();
        void printTree(ostream & out = cout) const;
        void buildTree(ifstream & input, bool printmsg);
		double searchIndex(vector<string> keys);
    struct node{
	    node(const string &x, node *l, node *c, node *r)
		:lkey(x), left(l), center(c), right(r){
                llines.resize(0);
                rlines.resize(0);
                rkey = "";
	    }
		bool isLeaf();
        node* add(node * t);
	    string lkey;
        string rkey;
	    node * left;
	    node * right;
		node * center;
	    vector<int> llines;
        vector<int> rlines;
	};
	node * root;
	node * insertHelper(const string &X, int line, node *& rt, int &distWords);
	bool containsHelper(const string & x, node * t, node* &result) const;
	void printTreeHelper(node *t, ostream & out) const;
	int findHeight(node *t);
};
	
#endif	
    
	

