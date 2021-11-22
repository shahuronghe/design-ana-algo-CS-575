#include <iostream>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST {
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
    class BinNode {
      public:
      int data;
      int height;
      BinNode * left;
      BinNode * right;

      // BinNode constructors
      // Default -- data part is default int value; both links are null.
      BinNode(): left(0), right(0) {}

      // Explicit Value -- data part contains item; both links are null.
      BinNode(int item): data(item), left(0), right(0) {}

      void preOrderH(BinNode * node) {
        if (node != 0) {
          cout << node -> data << " ";
          preOrderH(node -> left);
          preOrderH(node -> right);
        }
      }

      void inOrderH(BinNode * node) {
        if (node != 0) {
          inOrderH(node -> left);
          cout << node -> data << " ";
          inOrderH(node -> right);
        }
      }

      int nodeCountH(BinNode * node) {
        if (node == 0) {
          return 0;
        }
        return nodeCountH(node -> left) + nodeCountH(node -> right) + 1;
      }

      void deleteNodeH(BinNode *myRoot, int toBeDeleted){
       BinNode *node = myRoot;
       BinNode *parent = myRoot;
       while(1){
        if(node->data > toBeDeleted){
          parent = node;
          if(node->left != 0)
            node=node->left;
          else
            break;
        }
        else if(node->data < toBeDeleted){
          parent = node;
          if(node->right != 0){
            node=node->right;
          }
          else
            break;
        }
        else{
          break;
        }
      }
       //Case 1: no children
      if(node->left == 0 && node->right == 0){
        parent->left == node ? parent->left = 0 : parent->right = 0;
        delete(node);
        inOrderH(myRoot);
      }

      //Case 2: 1 children
      else{
        if((node->left != 0) ^ (node->right != 0)){
         if(parent->left == node){
          parent->left = node->left;
          delete(node);
         }
         else{
          parent->right = node->right;
          delete(node);
         }
        inOrderH(myRoot);  
      }
      
      // Case2: 2 children
      else{
        BinNode *tnode = node->left;
        BinNode *p = tnode;
        if(tnode->right == 0){  
          if(parent->left == node){
            parent->left = tnode;
            tnode->right = node->right;
            delete(node);
          }
          else{
            parent->right = tnode;
            tnode->right = node->right;
            delete(node);
          }
        }
        else{
          while(tnode->right != 0){
            p=tnode;
            tnode = tnode->right;
          }
          p->right = 0;

          if(tnode->left != 0){
            p->right = tnode->left;
          }

          if(parent->left == node){
            parent->left = tnode;
            tnode->left = node->left;
            tnode->right = node->right;
            delete(node);
          }
          else{
            parent->right = tnode;
            tnode->left = node->left;
            tnode->right = node->right;
            delete(node);
          } 
        } 
        inOrderH(myRoot);
      }
     }
   }
      
      int getHeight(BinNode * node) {
        if (node == 0)
          return -1;
        return 1 + max(getHeight(node -> left), getHeight(node -> right));
      }

      BinNode * rightRotate(BinNode * node) {
        BinNode * temp = node -> left;
        node -> left = node -> left -> right;
        temp -> right = node;
        return temp;
      }

      BinNode * leftRotate(BinNode * node) {
        BinNode * temp = node -> right;
        node -> right = node -> right -> left;
        temp -> left = node;
        return temp;
      }

      void updateHeight(BinNode * node) {
        if (node != 0) {
          updateHeight(node -> left);
          updateHeight(node -> right);

          cout << "\n\nNode's data: " << node -> data << " Old height: " << node -> height << " ";
          node -> height = getHeight(node);
          cout << "New Height: " << node -> height;
        }
      }

      BinNode * postOrderBalancing(BinNode * node, BinNode * parent, BinNode * myRoot) {
        if (node != 0) {
          int leftHt, rightHt, htDiff;
          postOrderBalancing(node -> left, node, myRoot);
          postOrderBalancing(node -> right, node, myRoot);
          if (node -> left != 0) {
            leftHt = node -> left -> height;
          } else {
            leftHt = -1;
          }
          if (node -> right != 0) {
            rightHt = node -> right -> height;
          } else {
            rightHt = -1;
          }

          htDiff = leftHt - rightHt;

          // If the tree is not balanced
          if (htDiff != 0 && htDiff != -1 && htDiff != 1) {

            // tree is left heavy
            if (leftHt > rightHt) {
              // node's left child is left heavy
              if (getHeight(node -> left -> left) > getHeight(node -> left -> right)) {
                // As the tree is of type LL we will rotate it to right
                BinNode * newRoot = rightRotate(node);
                if (parent -> left == node) {
                  parent -> left = newRoot;
                  return myRoot;
                } else if (parent -> right == node) {
                  parent -> right = newRoot;
                  return myRoot;
                } else {
                  return newRoot;
                }
              }
              // its child is right heavy
              else {
                // As the tree is of the type LR we will first rotate node's child to left and then node to right
                node -> left = leftRotate(node -> left);
                BinNode * newRoot = rightRotate(node);
                if (parent -> left == node) {
                  parent -> left = newRoot;
                  return myRoot;
                } else if (parent -> right == node) {
                  parent -> right = newRoot;
                  return myRoot;
                } else {
                  return newRoot;
                }
              }
            }

            // tree is right heavy at node
            else {
              // node's right child is right heavy
              if (getHeight(node -> right -> left) < getHeight(node -> right -> right)) {
                BinNode * newRoot = leftRotate(node);
                if (parent -> left == node) {
                  parent -> left = newRoot;
                  return myRoot;
                } else if (parent -> right == node) {
                  parent -> right = newRoot;
                  return myRoot;
                } else {
                  return newRoot;
                }
              } else {
                // As the tree is of type RL, we first right rotate the right child and then left rotate the left node
                node -> right = rightRotate(node -> right);
                BinNode * newRoot = leftRotate(node);
                if (parent -> left == node) {
                  parent -> left = newRoot;
                  return myRoot;
                } else if (parent -> right == node) {
                  parent -> right = newRoot;
                  return myRoot;
                } else {
                  return newRoot;
                }
              }
            }
          }
        }
        return 0;
      }

      int max(int v1, int v2) {
        return v1 > v2 ? v1 : v2;
      }
    }; // end of class BinNode declaration

  /***** Data Members *****/
  BinNode * myRoot;

}; // end of class declaration

#endif