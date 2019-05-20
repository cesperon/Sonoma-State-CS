#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

double exp(int x, int n);
int f(int n);
vector<string> Gray(int n);

struct Node {

  int key;
  Node* next}
  
int main()
{

  for(int i = 0; i<5; i++)
    
  double g = exp(2,51);

  double r = exp(8,5);

  cout<<r<<'\n'<<g<<'\n';

  int j = f(10);

  int a = f(1);

  int b = f(7);

  int c= f(127);

  int d = f(32767);

  cout<< j<<'\n'<<a<<'\n'<<b<<'\n'<<c<<'\n'<<d<<'\n';

  vector<string> h = Gray(6);

  for(int i = 0; i< h.size(); i++)
    cout<<h[i]<<endl;
}

double exp(int x, int n)
{
  if (n==1) return x;
  else if (n%2 ==0)
    return exp(x*x, n/2);
  else return x* exp(x*x, (n-1)/(2));
}

int f(int n)
{
  if(n==1) return 0;
  else if(n%2 ==0) return 1 + f(n/2);
  else return 2+ f((n-1)/2);
}

vector<string> Gray(int n) {

  vector<string> v;
  vector<string> u;
  vector<string>::iterator it = v.begin();

  if(n==1){
    v.push_back("0");
    v.push_back("1");
    return v;
  }
  else{
    v = Gray(n-1);
    for(int i = 0; i<v.size(); i++)
      u.push_back(v[i] + "0");
    for(int i = v.size()-1; i>=0; i--)
      u.push_back(v[i] + "1");

    return u;
  }
}

    

