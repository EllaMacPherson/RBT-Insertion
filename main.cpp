#include "node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
  1. Every node is either red or black.
  2. All null nodes are considered black.
  3. A red node does not have a red child.
  4. Every path from a given node to any of its leaf nodes (that is, to any descendant null node) goes
  through the same number of black nodes.

NULLS ARE BLACK!!!!!!!

 */

// Functions declerations 

// get uncle  return node*
node* getUncle(node* n);
// BST insertion
void bstinsert(node*& root, node* current, int value, node*& storage);
// detect case/check violatiojs
void checkViolations(node* myNode, node* parent, node* grandparent, node* uncle, node*& root);
// function for each case???
//Rrotation
//Lrotation

void print(int depth, node* current);


int main(){

  string command = "";
  // Hold root of the tree, start as NULL
  node* root = NULL;

  // new node(parent, l, r, value);

  while(true){
    // Printing stuff 
    cout<<"Enter INSERT, PRINT"<<endl;
    getline(cin, command);

    if(command == "PRINT" || command == "print"){
      print(0, root);
    }


  
  
    if(command == "INSERT" || command == "insert"){
      // get inputs
      int value = 0;
      cout<<"What value would you like to add?"<<endl;
      cin>>value;
      cin.ignore();

      
      node* recent = NULL; // for storage of newly added one so it so can be used for checking conditions

      //Initial BSTinsert set it to RED
      bstinsert(root, root, value, recent); // structure GOOD, parents GOOD, node* of js added GOOD, uncle GOOD

      node* uncle = NULL;
      node* grandpa = NULL
      if(recent->parent != root && recent != root){
	uncle = getUncle(recent);
      }
      // REMEMBER: uncle is NULL if its the root or child of root but if that is NOT the case then it is VALID and needs to be checked for in cases

      //FIX  GRANDPA NOT BEING FED INTO THIS RIGHTTT!!
      if(recent != root){
	checkViolations(recent, recent->parent, grandpa, uncle, root);
      }

      // I HAVE: the UNCLE, the NODE* js added, its PARENT, its GRANDPARENT the ROOT,
      

      

      //      checkViolations();
      //Check violations WIKIPEDIA + GALBY VIDEO ->need way to look at uncles and such think about this
      /* Possible cases:
	 1. Inserting at root. -> set it to B
       
	 2. Parent is B -> DONE
       
	 3. Parent AND uncle are R -> change Parent and Unc to BLACK, change Grandparent to RED -> Recursively call on Grandparent (if grandparent is root????)
       
	 4. Uncle is B AND { (Parent is left AND node is right) || (Parent is right AND node is left) } ->
	 Execute a LEFT rotation  if it's node on RIGHT
	 Executre a RIGHT rotation if it's node on LEFT
	 then call CASE 5
	
	 5. Uncle is B AND { (Parent is left AND node is left) || (Parent is right AND node is right) } ->
	 Have parent left rotate with grandparent
	 Have parent right rotate with grandparent
	 Switch grandparent and parent colors

	 AND THEN ALL THESE WHEN GRANDPARENT OR PARENT IS ROOT IS GONNA BE DIFFERENT!!!!!!!!!!!!!!!!!!!!!!!
        
      */
      // If violations foubd, fIX THEM
    
    }
  }

}

void checkViolations(node* myNode, node* p, node* g, node* u, node*& root){
  // check each and every case and then call a seprate functin to FIX that case
  cout<<"checking violations: "<< "node: "<<myNode->value<<"parent: "<<p->value<<"grandparent: "<<g->value<<"Uncle: "<<u->value<<"root: " << root->value<<endl;

}

// Get uncle of one js inserted
node* getUncle(node* n){
  node* grandpa = n->parent->parent;
  if(n->parent == grandpa->left){
    return grandpa->right;
  }
  if(n->parent == grandpa->right){
    return grandpa->left;
  }

  return NULL;
}


// Same as bst but adds parent link by storing prev
void bstinsert(node*& root, node* current, int value, node*& storage){

  // If there is no root
  if(root == NULL){
    root = new node(NULL, NULL, NULL, value);
    storage = root;
    root->changeColor(); // Make black
    return;
  }

  if(current->value < value){
    // Recursive down right till NULL
    if(current->right != NULL){
      bstinsert(root, current->right, value, storage);
    }
    else{
      current->right = new node(current, NULL, NULL, value);
      storage = current->right;
      return;
    }
  }

  if(current->value > value){
    //Recursive down left till NULL
    if(current->left != NULL){
      bstinsert(root, current->left, value, storage);
    }
    else{
      current->left = new node(current, NULL, NULL, value);
      storage = current->left;
      return;
    }

  }

}

// Print function the same as binary search tree but add printing of R or B
void print(int depth, node* current){

  //move all the way to the right of the tree

  if(current->right != NULL){
    print((depth + 1), current->right);
  }

  //tab over depth times!
  for(int i = 0; i < depth; i++){
    cout<<"\t";
  }

  if(current != NULL){
    cout<<current->value;
    if(current->color == true){
      cout<<" R"<<endl;
    }
    if(current->color == false){
      cout<<" B"<<endl;
    }
  }

  // move all way to the left side of the tree
  if(current->left != NULL){
    print((depth + 1), current->left);
  }



}
