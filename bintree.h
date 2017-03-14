// ------------------------------- BinTree.h ---------------------------------
// Kay Phan CSS 343 
// Created 1/22/2017
// Last Modified 1/29/2017
//----------------------------------------------------------------------------
// Purpose:
//
// The .h file for the BinTree class.
//
// This is a Binary Search Tree that will store many objects. Each Node in
// the tree can have up to two children. Greater objects will be stored on
// the right and lesser ojects on the left of any object.
// 
// This binary search tree can be used to find NodeData objects,
// display them either as a tree or in order, empty out itself, empty its 
// data into a sorted array, or build a tree from a sorted array.
//----------------------------------------------------------------------------

#ifndef BinTree_H
#define BinTree_H

// for output capabilities
#include <iostream>
// for the NodeData object
#include "nodedata.h"

using namespace std;

class BinTree {

// all private functions and data members
private:

   //private Node struct
   struct Node {
      NodeData* data;
      Node* left;
      Node* right;
   };
   
   // private data member
   Node* root; // pointer to the root Node

   // helper functions
   void makeEmptyHelper(Node*&);
   Node* insertHelper(Node*, NodeData*, bool&);
   void retrieveHelper(const NodeData&, NodeData*&, Node*, bool&) const;
   void getHeightHelper(const Node*, const NodeData&, int&) const;
   void copyHelper(Node*&, Node*);
   void isEqualHelper(Node*, Node*, bool&) const;
   void sideways(Node*, int) const;
   int branchHeight(const Node*) const;

   void bstreeToArrayHelper(int&, NodeData*[], Node*&);
   void arrayToBSTreeHelper(int, int, NodeData*[]);

// public and friend functions
public:

   // friend output operator
   friend ostream& operator<<(ostream&, BinTree&);
   friend void outputHelper(ostream&, Node*);

   // constructors
   BinTree();				      // default constructor
   BinTree(const BinTree&);   // copy constructor
   ~BinTree();				      // destructor
   
   // public functions
   bool insert(NodeData*);
   bool retrieve(const NodeData&, NodeData*&) const;
   int getHeight(const NodeData&) const;
   void displaySideways() const;
   void bstreeToArray(NodeData*[]);
   void arrayToBSTree(NodeData*[]);

   void makeEmpty();			//	empties the tree, deletes nodes

   // overwritten operators
   BinTree& operator=(const BinTree&);
   bool operator==(const BinTree&) const;
   bool operator!=(const BinTree&) const;


};
#endif