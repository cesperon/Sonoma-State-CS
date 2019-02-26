// Title: OrderedSet.hpp
// Author: Christian Esperon
// Description: file containing function headers and implementations
// for OrderedSets, also contains function header and implementations
// for iterator class and expception class to be use by an OrderedSet.

#ifndef OrderedSet_HPP
#define OrderedSet_HPP

#include <string>
#include <iostream>
#include<sstream>
#include "WordData.h"
using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class ST> class OrderedSet;
template <class ST> ostream & operator <<(ostream & outs, const OrderedSet<ST> & L);

template<class ST>

class OrderedSet
{
  
   private:
      struct LNode
      {
	
         LNode ();
         ST data;
	 LNode * next;
	 LNode * prev;
	
      };
  
   public:

      class Iterator
      {
      public:
	Iterator ();
	Iterator (LNode * NP);
        ST & operator * () const;
	Iterator operator ++ ();
	Iterator operator ++ (int);
	Iterator operator -- ();
	Iterator operator -- (int);
	bool operator == (const Iterator & other) const;
	bool operator != (const Iterator & other) const;
	ST & operator [] (const int & index) const;

      private:
	LNode * current;
      };
  
      class Exception
      {
      public:
	Exception ();
	Exception (string msg);
	Exception (int idx);
        string Message () const;

      private:
	string message;
      };
  
      OrderedSet ();
      OrderedSet (const OrderedSet & other);
      ~OrderedSet ();
      OrderedSet & operator = (const OrderedSet & other);
      bool operator == (const OrderedSet & other);
      int Size () const;
      ST & operator [] (const int & index) const;
      void Clear ();
      bool IsEmpty () const;
      bool IsIn (const ST & value) const;
      bool Insert(const ST & value);
      bool Delete(const ST & value);
      OrderedSet operator + (const OrderedSet & other);
      OrderedSet operator * (const OrderedSet & other);
      void SetDirection (dtype dir);
      dtype GetDirection () const;
      friend ostream & operator << <> (ostream & outs, const OrderedSet<ST> & L);

      Iterator begin () const;
      Iterator rbegin () const;
      Iterator end () const;
      Iterator rend () const;
  
      void Forward (void function (const ST & param));
      void Backward (void function (const ST & param));
      void PrintValue (const int & value);

  
   private:
      LNode * first;
      LNode * last;
      dtype direction;
      int size;
      bool InsertFirst (const ST & value);
      bool InsertLast (const ST & value);
      bool DeleteFirst ();
      bool DeleteLast ();
};


// OrderedSet function implementations.

template<class ST>
void OrderedSet<ST>:: Clear()
{// This function will clear all nodes from the OrderedSet.
  
  LNode * n = first;
  LNode * p;

  while (n != NULL)
    {
      p = n->next;
      delete n;
      n = p;
    }
  first = NULL;
}

template<class ST>
bool OrderedSet<ST>:: IsEmpty () const
{// This function will determine whether the Ordered Set is
  //empty or not. If the OrderedSet is empty will return true
  //else will return false.
  
  if(first == NULL)
    {
      return true;
    }
  else
    return false;
}

template<class ST>
bool OrderedSet<ST>:: IsIn (const ST & value) const
{// This function will determine wheter a particular value
  //is in the OrderedSet if the value is in OrderedSet it will
  //return true, else will return false.
  
  LNode * n = first;
  LNode * p;

  while (n != NULL)
    {
      if(value == n->data)
	{
	  return true;
	}
      p = n->next;
      n= p;
    }
  return false;
  
  
  
  
}
template<class ST>
bool OrderedSet<ST>:: Insert (const ST & value)
{// This function will insert a value into OrderedSet by
  // ascending order.
  
  if(size == 0)
   return InsertFirst(value);

  if(IsIn(value))
    return false;

  if(value < first -> data)
    return InsertFirst(value);

  if(value > last -> data)
    return InsertLast(value);

  LNode * n = new LNode;
  if (n == NULL)
    return false;
  n-> data = value;

  LNode * s = first;
  while(s->data < value)
    
       s = s->next;
    

  LNode * p = s->prev;
  n->prev = p;
  s->prev = n;
  p->next = n;
  n->next = s;
  size++;
  return true;
  
	
}
template<class ST>
bool OrderedSet<ST>:: Delete (const ST & value)
{// This function will will delete a node from the OrderedSet
  // according to which value is passed to this function.
  
  if(size == 0)
    return false;

  if(size == 1)
    return DeleteFirst();

  if(IsIn(value) == false)
    return false;
  if(first->data == value)
    {
      return DeleteFirst();
    }
  if(last->data == value)
    {
      return DeleteLast();
    }

 
  if(IsIn(value)==true)
    {
      LNode * np = new LNode;
      if(np== NULL)
         return false;

      np->data = value;
      LNode * s = first;
      while(s-> data != value)
           s = s->next;

      LNode * r = s->prev;
      LNode * rn = s-> next;

      r->next = rn;
      rn->prev = r;
      size--;
      delete s;
    }

  
}
template<class ST>
OrderedSet<ST> OrderedSet <ST>:: operator + (const OrderedSet & other)
{// This function will return an ordered set containing the union
  // of its two ordered set operands.
  
  OrderedSet<ST> L;
  LNode * n = first;
  LNode * r = other.first;
  while(n != NULL)
    {
      if(L.IsIn(n->data)== false)
	{
	  L.Insert(n->data);
	}
      n=n->next;
    }

  while(r != NULL)
    {
      if(L.IsIn(r->data) == false)
	{
	  L.Insert(r->data);
	}
      r=r->next;
    }
  return L;
	  
  
}
template<class ST>
OrderedSet<ST> OrderedSet<ST>:: operator * (const OrderedSet & other)
{// This function will return an ordered set containg the intersections of
  // its two ordered set operands.
  
  OrderedSet<ST> L;
  LNode * n = first;
  LNode * o = other.first;
  while(n !=NULL)
    {
      if(other.IsIn(n->data))
	{
	  L.Insert(n->data);
	}
      n=n->next;
    }
 
  return L;
	  

  
}
template <class ST>
OrderedSet<ST>::LNode::LNode ()
{ // This function will initialize LNode object.
  
  next = NULL;
  prev = NULL;
  //size = 0;
}

template <class ST>
OrderedSet<ST>::OrderedSet ()
{ // This function will initialize an OrderedSet object.
  size = 0;
  first= NULL;
  last = NULL;
  direction = FORWARD;
  
}

template <class ST>
OrderedSet<ST>::OrderedSet (const OrderedSet & other)
{ // This function will copy an OrderedSet object.
  first = NULL;
  size = 0;
  for(LNode * n = other.first; n!=NULL; n= n->next)
    InsertLast (n->data);
  direction = other.direction;
}

template <class ST>
OrderedSet<ST>::~OrderedSet ()
{ // This function will deallocated the memory of an of an OrderedSet object.

  while(first)
    DeleteFirst();
  
}


template <class ST>
OrderedSet<ST> & OrderedSet<ST>::operator = (const OrderedSet<ST> & other)
{ // This function will allow you to use = to assign one instance to another.

  if (this == &other)
	return * this;
  while (first)
    DeleteFirst();
  for (LNode * n = other.first; n!= NULL; n = n->next)
    InsertLast (n->data);
  direction = other.direction;
  return * this;
  
}

template <class ST>
bool OrderedSet<ST>::operator == (const OrderedSet & other)
{ // This function will check equivalancy of two OrderedSet objects.

  if (size != other.size)
    return false;

  int j = 0;
  LNode * n = first;
  LNode * m = other.first;
  while (j < size)
    {
      if (n->data != m->data)
	{
	  return false;
	}
      n = n->next;
      m = m->next;
      j++;
    }
  return true;
      
}

template <class ST>
int OrderedSet<ST>::Size () const
{ // This function will return the size of the OrderedSet.

  return size;
  
}

template<class ST>
ostream & operator << (ostream & outs, const OrderedSet<ST> & L)
{ // This function will output the data in the OrderedSet.
  if (L.first == NULL)
    {
      cout<<"{";
      cout<<"}";
      return outs;
    }

  if (L.direction == FORWARD)
    {//print the list from beginning (first) to end
      outs<<"{";
      outs<<L.first->data;

      typename OrderedSet<ST>::LNode * n;
      for (n = L.first->next; n!=NULL; n= n->next)
	outs <<','<<n->data;
      outs<<"}";
    }
  if (L.direction == BACKWARD)
    {//print the list from end to beginning
      outs<<"{";
      outs<<L.last->data;

      typename OrderedSet<ST>::LNode*n;
      for(n = L.last->prev; n !=NULL; n= n->prev)
	outs<<','<< n->data;
      outs<<"}";
    }
  
  return outs;
  

}

template <class ST>
bool OrderedSet<ST>::InsertFirst (const ST & value)
{ // This function will insert a new node into the first position of the
  // OrderedSet.

  LNode* tmp = new LNode;
  
  if(tmp == NULL)
   {
     return false;
   }
  
  if(size == 0)
    {
       tmp-> data = value;
  
       tmp-> next = NULL;

       tmp-> prev = NULL;

       first = tmp;

       last = tmp;

       size ++;
       return true;
    }
  if(size >=1)
    {
      tmp->data = value;
      tmp->next = first;
      tmp->prev = NULL;
      first->prev = tmp;

      first = tmp;
      size++;
      return true;
    }
      
}

template <class ST>
bool OrderedSet<ST>::InsertLast (const ST & value)
{ // This function will insert a new node into the last position
  // of the linked OrderedSet.
  
  if(size == 0)
    {
      return InsertFirst(value);
    }
  LNode * n = new LNode;
  if( n == NULL)
    return false;

  if(size == 1)
    {
      n-> next = NULL;
      n-> prev = last;
      n-> data = value;
      last->next = n;
      last = n;
      size++;
      return true;
    }

  n->data = value;
  n->next = NULL;
  n->prev = last;

  last->next = n;
  last = n;
  size++;
  return true;
  
  
}

template <class ST>
bool OrderedSet<ST>::DeleteFirst ()
{ // This function will delete the first node in the OrderedSet.
  
  if(size == 0)
     return false;

  if(size == 1)
    {
      LNode* tmp = first;
      first = NULL;
      last = NULL;
      delete tmp;
      size-- ;
      return true;
    }

  LNode* tmp = first;
  first = first->next;
  first->prev = NULL;
  delete tmp;
  size--;

  return true;
}

template <class ST>
bool OrderedSet<ST>::DeleteLast ()
{ // This function will delete the last node in the linked list.

  if(size == 0)
    return false;
  if(size == 1)
    return DeleteFirst();

  LNode* n = last; 
  
  last = last->prev;
  last->next = NULL;
  n->prev = NULL;

  delete n;
  size--;
  return true;
    
}

template <class ST>
void OrderedSet<ST>::Forward (void function (const ST & param))
{//This function will traverse through the ordered set from beginning
  // to end.
  
  for (LNode * n = first; n; n= n->next)
    function (n->data);
}

template <class ST>
void OrderedSet<ST>::Backward (void function (const ST & param))
{// This function will traverse backward through the Ordered set.
  for (LNode * n = last; n; n= n->prev)
    function (n->data);
}

template <class ST>
void OrderedSet<ST>::SetDirection (dtype dir)
{// This function will set the direction of which the OrderedSet
  // will be traversed.
  
  direction = dir;
}

template <class ST>
dtype OrderedSet<ST>::GetDirection () const
{// This function will return the direction of the OrderedSet.
  
  return direction;
}

 void PrintValue (const int & value)
 {// This function will print the values in the OrderedSet.
   
   cout<< "The value in the list is " << value << endl;
 }

template <class ST>
ST & OrderedSet<ST>::operator [] (const int & index) const
{
      if (index < 0)
	throw(Exception(index));
      if (index >= size)
	throw(Exception(index));

     typename OrderedSet<ST>::LNode * n = first;
     for(int i = 0; i < index; i++)
        {
          n= n->next;
        }
     return n-> data;
   
}


//Iterator fucntion implementations

template <class ST>
OrderedSet<ST>::Iterator::Iterator ()
{// This function will initialize and iterator.
  
  current =NULL;
}

template <class ST>
OrderedSet<ST>::Iterator::Iterator (LNode * NP)
{// This function will point the iterator to current.
  current = NP;
}

template <class ST>
ST & OrderedSet<ST>::Iterator:: operator * () const 
{// This function will dereference an iterator.
  
     if (current == NULL)
       throw(Exception("Cannot dereference a NULL pointer"));
     return current->data;
    
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++()
{// This function will move the iterator forward through the list.
  
      if(current == NULL)
	throw(Exception("Cannot increment a NULL iterator"));
      current = current->next;
      return * this;
   
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++(int)
{// This function will move the iterator forward through the list.
  
     if(current== NULL)
       throw(Exception("Cannot increment a NULL iterator"));
    Iterator temp = *this;
    current = current ->next;
    return temp;
  
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator --()
{// This function will move the iterator backwards through the list.
 
      if(current==NULL)
        throw(Exception("Cannot decrement a NULL iterator"));
      current = current->prev;
      return *this;
      
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator -- (int)
{// This function will move the iterator backwards through the list.
  
      if(current ==NULL)
	throw(Exception("Cannot decrement a NULL iterator"));
      Iterator temp = *this;
      current = current->prev;
      return temp;
   
}

template <class ST>
bool OrderedSet<ST>::Iterator::operator == (const Iterator & other) const
{// Will check if the values in the iterator and other are equivalent.
  
  return current == other.current;
}

template <class ST>
bool OrderedSet<ST>::Iterator::operator != (const Iterator & other) const
{// This function will check if the values in the iterator and other are not
  // equivalent.
  
  return current != other.current;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::begin () const
{// This function will set the iterator to the beginning of the orderedset.
  
  Iterator temp (first);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rbegin () const
{// This function will set the iterator to the reversbegin location of the
  // OrderedSet.
  
  Iterator temp (last);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::end () const
{// This function will set the iterator to the end location of the
  // OrderedSet.
  
  Iterator temp;
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rend () const
{// This function will set the iterator to the reverse end location
  // of the OrderedSet.
  Iterator temp;
  return temp;
}

//Exception function implementations.

template <class ST>
OrderedSet<ST>::Exception::Exception()
{
  //Constructor for the Exception class.
}

template <class ST>
OrderedSet<ST>::Exception::Exception (string msg)
{// creates a message throug the passed string.
  
  message = msg;
}

template <class ST>
OrderedSet<ST>::Exception::Exception(int idx)
{// outputs the exception message.
  stringstream ss (stringstream::in|stringstream::out);
  ss<< "Subscript ["<< idx <<"] out of range";
  getline(ss, message);
}

template <class ST>
string OrderedSet<ST>:: Exception:: Message () const
{// returns exception message.
  return message;
}

#endif
