#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
   
   BinNode bn;
   bn.updateHeight(myRoot);
   BinNode *temp = bn.postOrderBalancing(myRoot, myRoot, myRoot);
   if(temp != 0){
      myRoot = temp;
   }
   bn.updateHeight(myRoot);
   cout<<"\nInorder : ";
   bn.inOrderH(myRoot);
   cout<<"\nPreorder : ";
   bn.preOrderH(myRoot);
}

void BST::preOrder(){
	BinNode bn;
	bn.preOrderH(myRoot);
}

void BST::inOrder(){
	BinNode bn;
	bn.inOrderH(myRoot);
}

int BST::nodeCount(){
	BinNode bn;
	return bn.nodeCountH(myRoot);
}

void BST::deleteNode(int node){
	BinNode bn;
	if(!search(node)){
		cout<<"Failed to delete, item not found"<<endl;
		return;
	}
	bn.deleteNodeH(myRoot, node);
	cout<<"Item deleted: "<<node;
  bn.updateHeight(myRoot);
  bn.postOrderBalancing(myRoot, myRoot, myRoot);
  bn.updateHeight(myRoot);
  cout<<"\nIn-Order:";
	bn.inOrderH(myRoot);
	cout<<"\nPre-Order";
	bn.preOrderH(myRoot);
}
