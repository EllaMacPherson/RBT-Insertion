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


int main(){

  string command = "";

  cout<<"Enter INSERT, PRINT"<<endl;

  getline(cin, command);
  
  if(command == INSERT || command == insert){
    //Initial BSTinsert set it to RED

    //Check violations ->need way to look at uncles and such think about this
    /* Possible cases:
       1. Inserting at root. -> set it to B
       
       2. Parent is B -> DONE
       
       3. Parent AND uncle are R -> change Parent and Unc to BLACK, change Grandparent to RED -> Recursively call on Grandparent (if grandparent is root????)
       
       4. Uncle is B AND { (Parent is left AND node is right) || (Parent is right AND node is left) } ->
        Execute a LEFT rotation  if it's node on RIGHT
	Executre a RIGHT rotation if it's node on LEFT
	then call CASE 5
	
       5. Uncle is B AND { (Parent is left AND node is left) || (Parent is right and node is right) } ->
        
    */
         // If violations foubd
  }

  
















}





// Print function the same as binary search tree but add printing of R or B
