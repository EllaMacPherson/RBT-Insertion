#include <iostream>

using namespace std;

class node{

 public:
  node(node* p, node* l, node* r, int v);

  void changeColor();

  ~node();

  // Next nodes

  node* right;
  node* left;
  node* parent;

  // Value storage
  int value;
  
  bool color = false; // FALSE = color BLACK


};
