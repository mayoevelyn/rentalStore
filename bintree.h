//------------------------------------------------------------------------------
// BinTree
//------------------------------------------------------------------------------
// This is a Binary Search Tree that will store many objects. Greater objects
// will be stored on the right and lesser ojects on the left. 
// 
// This binary search tree can be used to find objects, display them, 
// empty out itself, and say if it's empty.
// 
// 
// 

#ifndef BinTree_H
#define BinTree_H

#include <iostream>
#include "nodedata.h"

using namespace std;

class BinTree {


private:
   struct Node {
      NodeData* data;
      Node* left;
      Node* right;
   };

   int size;
   Node* root;

   void makeEmptyHelper(Node*&);
   Node* insertHelper(Node*, NodeData*, bool&);
   void retrieveHelper(const NodeData&, NodeData*&, Node*, bool&) const;
   void getHeightHelper(const Node*, const NodeData&, int&, int) const;
   void copyHelper(Node*&, Node*);
   void isEqualHelper(Node*, Node*, bool&) const;
   void sideways(Node*, int) const;

   void bstreeToArrayHelper(int&, NodeData*[], Node*&);
   void arrayToBSTreeHelper(int, int, NodeData*[]);

public:

   friend ostream& operator<<(ostream&, BinTree&);
   friend void outputHelper(ostream&, Node*);

   // constructors
   BinTree();				// constructor
   BinTree(const BinTree&);
   ~BinTree();				// destructor

   bool insert(NodeData*);
   bool retrieve(const NodeData&, NodeData*&) const;

   int getHeight(const NodeData&) const;

   void displaySideways() const;
   void bstreeToArray(NodeData*[]);
   void arrayToBSTree(NodeData*[]);
   void makeEmpty();			//	empties the tree, deletes nodes

   // overwritten operators

   BinTree operator=(const BinTree&);

   bool operator==(const BinTree&) const;
   bool operator!=(const BinTree&) const;


};
#endif