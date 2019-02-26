// File: stack1.cpp
// Author: Christian Esperon
// Description: This program will take an inputed generalized list and create a vector
// of tokens.Then it will use the vector of tokens to implement an arbitrarily
// nested list using a stack.

#include <iostream>
#include <string>
#include <vector>
#include "stdlib.h"
#include "Scan.cpp"

using namespace std;

class Stack;

class Node {

public:
Node(int key1){
	key = key1;
	tag = 0;
	down = NULL;
	next = NULL;
}

Node(Node* dptr, Node* nptr) {
	tag = 1;
	down = dptr;
	next = nptr;
}

void setTag(int k){
        tag = k;
}
    
void setKey(int k) {
	key = k;
}

void setDown(Node* ptr) {
	down = ptr;
}

void setNext(Node* ptr) {
	next = ptr;
}

int getKey() {
	return key;
}

int getTag() {
       return tag;
}
    
Node* getDown() {
	return down;
}

Node* getNext() {
	return next;
}

int size() {
	if (this == NULL)
	   return 0;
	else if (this->tag == 0) return 1;
	else
	   return down->size() + next->size();
}
  
void update(int j, int k) {
  if (this == NULL)
    {
      cout<<"not valid to update empty list";
      return;

    }
  else if(tag == 0)
    {
      key = k;
      return;
    }
  else
    {
      int s = down->size();
      if(j<=s)
	{
	 down-> update(j,k);
	    }
      else
	{
	 next-> update(j-s,k);
	    }
    }
}

  
  
bool isEmpty() {
	  return this == NULL;
  }

void print(int depth) {
	  if (this == NULL) return;
	  if (tag == 0) {
	      cout << "<" << key << ":" << depth << ">  " ;
	      }
	  else {
	     down->print(depth+1);
	     next->print(depth);
	    } // end else
	 } // end print

private:
   int tag;
   int key;
   Node* down;
   Node* next;
};

class Stack {

private:
  int maxTop;// max stack size = size - 1
  int top;// current top of stack
  Node* values[1000];// element array

public:

  bool IsEmpty() { return top == -1; }
  bool IsFull() { return top == maxTop; }

 Stack() {
    top=-1;
    maxTop= 999;
  }

  

  void Push(Node* x) {
    if (IsFull())  // if stack is full, print error
      cout << "Error: the stack is full." << endl;
    else {
        values[++top]= x;
        }
  }

  Node*  Pop() {
    if (IsEmpty()) { //if stack is empty, print error
      cout << "Error: the stack is empty." << endl;
      return NULL;
    }
    else {
      return values[top--];
    }
  }

  Node* Top() {
    if (IsEmpty()) {
      cout << "Error: the stack is empty." << endl;
      return NULL;
    }
    else
      return values[top];
  }
};

int convert(string x) {
 // converts a string rep of decimal integer to an int
  return atoi(x.c_str());
}

Node* create (vector<string> T) {

  Stack S;

  for(int k = 0; k < T.size(); k++)
    {
      if(T[k] == "[")
	{
	  Node* N = new Node(NULL,NULL);
	  N->setTag(-1);
	  S.Push(N);

	    }
      else if(isDigit(T[k]))
	{
	  int key= convert(T[k]);
	  Node* R = new Node(key);
	  S.Push(R);
	}
      else if(T[k] == "]")
	{
	  Node* R = S.Pop();
	  Node * pointerNode = new Node(R, NULL);
	  while (S.Top()->getTag() != -1)
	    {
	      R = S.Pop();
	      pointerNode = new Node(R, pointerNode);
	    }

	    S.Pop();
	    S.Push(pointerNode);
	    
	}
    }
  return S.Pop();
}
	   

int main(int argc, char* argv[]) {
  
  //gets users inputed list and reads it into string s 
  string s;
  cout<<"Input a generalized list: "<<endl;
  getline(cin, s);
  cout<<endl<<"The input list (with depth for each key):"<<endl;

  //takes tokens from string and puts it into vector
  vector <string> g = Scan(s);

  //creates a nested list with the vector of tokens
  Node* n=create(g);
  n->print(0);
  cout<<endl;

  //asks user whether they want to update list or quit program
  //and reads that input into a char
  char a;
  cout<<"What would you like to do? "<<endl;
  cout<<"'u' : Update an element"<<endl;
  cout<<"'q' : Quit the program"<<endl;
  cin>>a;

  //uses inputed char to determine wheter to update nested list
  //or quit program.
  while(a != 'q'){
    switch(a){
       case 'u':
	 int position;
	 int value;
	 cout<<endl<< "Which element would you like to update? ";
	 cin>> position;
	 cout<< "What would you like to update it to? ";
	 cin>> value;
	 n->update(position, value);
	 cout<<endl<< "The updated list is: "<<endl;
	 n->print(0);
	 cout<<endl<<endl;	 
	 break;

      case 'q':
	break;
	
      }
    char c;
    cout<<"What would you like to do? "<<endl;
    cout<<"'u' : Update an element"<<endl;
    cout<<"'q' : Quit the program"<<endl;
    cin>>c;
    a=c;
  }

  
  return 0;
}

