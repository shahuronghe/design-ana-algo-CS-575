#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void preOrder();
  void inOrder();
  int nodeCount();
  void deleteNode(int data);
  
 private:
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}

    void preOrderH(BinNode *node){
      if(node != 0){
        cout<<node->data<<" ";
        preOrderH(node->left);
        preOrderH(node->right);
      }
    }

    void inOrderH(BinNode *node){
     if(node != 0){
        inOrderH(node->left);
        cout<<node->data<<" ";
        inOrderH(node->right);
      }
    }

    int nodeCountH(BinNode *node){
      if(node == 0){
        return 0;
      }
      return nodeCountH(node->left) + nodeCountH(node->right) + 1;
    }


    bool deleteNodeH(struct BinNode *root, int data) {
	    BinNode *node = root;
     	    BinNode *parent = root;
     	    while(1){
	    	    if(node->data > data){
		  	    parent = node;
		  	    if(node->left != 0)
				    node=node->left;
		  	    else
				    break;
	    	    }
	    	    else if(node->data < data){
		  	    parent = node;
		  	    if(node->right != 0){
				    node=node->right;
		  	    }
		  	    else
				    break;
	    	    } else {
		  	    break;
	    	    }
      	    }
	    // Case1: 0 children
	    if(node->left == 0 && node->right == 0){
	    	    parent->left == node ? parent->left = 0 : parent->right = 0;
	    	    delete(node);
	    	    inOrderH(root);
		    return true;
      	    }
      	    // Case 2: 1 children
	    else{
	    	    if((node->left != 0) ^ (node->right != 0)){
			    if(parent->left == node){
			  	    parent->left = node->left;
			  	    delete(node);
		   	    } else {
			  	    parent->right = node->right;
			  	    delete(node);
		   	    }
		    	    inOrderH(root);
			    return true;
	      	    }
		    // Case 3: 2 children
	     	    else{
			    BinNode *temp1 = node->left;
			    BinNode *temp2 = temp1;
		    	    if(temp1->right == 0){
			  	    if(parent->left == node){
					    parent->left = temp1;
					    temp1->right = node->right;
					    delete(node);
			  	    }
			  	    else{
					    parent->right = temp1;
					    temp1->right = node->right;
					    delete(node);
			  	    }
		    	    } else{
			  	    while(temp1->right != 0){
					    temp2=temp1;
					    temp1 = temp1->right;
			  	    }
			  	    temp2->right = 0;
			  	    if(temp1->left != 0){
					    temp2->right = temp1->left;
			  	    }
			  	    if(parent->left == node){
					    parent->left = temp1;
					    temp1->left = node->left;
					    temp1->right = node->right;
					    delete(node);
			  	    } else{
					    parent->right = temp1;
					    temp1->left = node->left;
					    temp1->right = node->right;
					    delete(node);
			  	    }
		    	    }
		    	    inOrderH(root);
			    return true;
	      	    }
		    return false;
       	    }
    } 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 

}; // end of class declaration

#endif
