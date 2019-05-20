#include <iostream>

using namespace std;

void insert(Node* & n, int k, int posn);
void print(Node *n);
struct Node {
  int key;
  Node* next;
};

int main() {
  Node * my1st;
  print(my1st);

  return 0;
}




void insert(Node* & n, int k, int posn) {
  // assume: 1<= 1 <= posn <= length f 1st + 1
  if (n == NULL) {
    //in this case, posn must be 1
    n = new Node();
    n->key = k;
    n->next = NULL;
  }
  else if (posn == 1) {
    Node * r = newNode (k);
    r->next = n;
    n =r;
  }
  else
    insert(n->next, k, posn-1);
}

void print(Node* n) {
  if(n != NULL) {
    cout<< n->key << ',';
    print(n->next);
  }
  cout << endl;
}
