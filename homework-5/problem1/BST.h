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
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 

}; // end of class declaration

#endif
