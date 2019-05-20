#include <iostream>
#include <ctime>
#include <cstdlib>
#include "OrderedSet.hpp"

using namespace std;
/*
void TestSubscript(OrderedSet<int> & S, int sub);
void TestDereference (OrderedSet<int>::Iterator itr);
*/
int main ()
{      /*
	OrderedSet<int> L;
	srand (time (NULL));
	int num = rand() % 20 + 5;
	cout << "The value of num is " << num << endl;
	int val = rand() % 10;
	cout << "The value of val is " << val << endl;
	for (int n = 0; n < num; n++)
	{
		L.InsertFirst (val);
		val = (val * 17 - 13) % 100;
	}
	cout << L << endl;
	cout << "From first to last:\n";
	for (OrderedSet<int>::Iterator itr = L.begin (); itr != L.end(); itr--)
		cout << "List value is " << * itr << endl;
	cout << "From last to first:\n";
	for (OrderedSet<int>::Iterator itr = L.rbegin (); itr != L.rend(); itr++)
	   cout << "List value is " <<* itr << endl;
	cout << L << endl;
	cout<< "clearing L"<<endl;
	//L.Clear();
	L.Insert(5);
	cout<< L<<endl;
	if(L.IsEmpty() == true)
	  {
	    cout<<"hi"<<endl;
	  }
	else if(L.IsEmpty() == false)
	  {
	    cout<<"dumb"<<endl;
	  }
	if(L.IsIn(8) == true)
	  {
	    cout<<"yeehaw"<<endl;
	  }
	cout<<"inserting"<<endl;
	L.Insert(5);
	cout<<L<<endl;
	cout<<"deleting"<<endl;
	L.Delete(8);
	cout<<L<<endl;
       */

	cout<<"+operator test"<<endl;
	OrderedSet<int> Q;
	OrderedSet<int> S;
	OrderedSet<int> T;

	

	for(int i =0; i<5; i++)
	  Q.Insert(i);

	for(int i = 5; i < 10; i++)
	  S.Insert(i);

	cout<<Q<<endl;

	cout<< S<<endl;

	T = S;

	T[2] = 8;

	cout<<T[2]<<endl;

	cout<<T<<endl;

	cout<<T+Q<<endl;

	T.Delete(8);

	cout<<T<<endl;

       

	for (OrderedSet<int>::Iterator itr = T.begin (); itr != T.end(); itr++)

	  LNode * g = itr;
	   

	cout<<T<<endl;

	//cout<<T*Q<<endl;

	

	

	
	return 0;
}
/*
void TestDereference (OrderedSet<int>::Iterator itr)
{
  try
    {
      cout<<"Testing * operator:\n";
      int value = *itr;
      cout<<"The value at the iterator is: ";
      cout<<value <<endl;
    }
  catch(OrderedSet<int>::Exception E)
    {
      cerr<<"Exception: "<<E.Message() << endl;
      return;
    }
}

void TestSubscript(OrderedSet<int> & S, int sub)
{
  try
    {
      cout<<"Testing [] operator:\n";
      int value = S[sub];
      cout<<"The value at S["<<sub<<"] is: ";
      cout <<value<<endl;
    }
  catch (OrderedSet<int>::Exception E)
    {
      cerr<< "Exception: "<<E.Message() <<endl;
      return;
    }
}
*/
