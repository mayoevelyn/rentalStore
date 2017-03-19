//------------------------------------------------------------------------------
// BSTree
//------------------------------------------------------------------------------
// This is a Binary Search Tree that will store many objects. Greater objects
// will be stored on the right and lesser ojects on the left. 
// 
// This binary search tree can be used to find objects, display them, 
// empty out itself, and say if it's empty.
// 
// 
// 

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

using namespace std;

template <typename T>
class BSTree {
   public:
      // constructors
      BSTree();				// constructor
      ~BSTree();				// destructor

      bool insert(T*);
      bool retrieve(const T&, T*&) const;
      bool remove(const T&, T*&);

      void display(std::ostream&) const;	// prints out all objects
      void makeEmpty();			//	empties the tree, deletes nodes
      bool isEmpty() const;			// any items in the tree?

   private:
      // private struct class
      struct Node {
         T* data;		//
         Node* right;		//
         Node* left;			//
      };

      Node* insertHelper(Node*, T*);
      bool retrieveHelper(const T&, T*&, Node*);
      bool removeHelper(const T&, T*&, Node*);
      void displayHelper(Node*, std::ostream&);
      void makeEmptyHelper(Node*);

      Node* findLargestObject(Node*);

      Node* root;	// the root of the tree
};

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// Points head to NULL because no data to begin with
template <typename T>
BSTree<T>::BSTree() {
   // no data
   root = NULL;
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------
// Deletes all data in the tree
template <typename T>
BSTree<T>::~BSTree() {
   makeEmpty();
}

//----------------------------------------------------------------------------
// insert
//----------------------------------------------------------------------------
// Inserts a new object into the tree in order
template <typename T>
bool BSTree<T>::insert(T* object) {
   // start with the overall root
   root = insertHelper(root, object);
   return true;
}

//----------------------------------------------------------------------------
// insertHelper
//----------------------------------------------------------------------------
// Recursive helper function for insert. It returns a pointer to a node.
// If the node is NULL, the object is inserted there. If the object to insert 
//  is greater than the current, then it recurses right; else, left.
template <typename T>
BSTree<T>::Node* BSTree<T>::insertHelper(Node* node, T* object) {
   //if node is null, add the object
   if (node == NULL) {
      node = new Node;
      node->data = ojbect;
      node->left = NULL;
      node->right = NULL;
      return node;
   }

   // if the object is greater than current, go right
   else if (*object > *node->data) node->right = insertHelper(node->right, object);
   // if the object is less than current, go left
   else node->left = insertHelper(node->left, object);
}

template <typename T>
bool BSTree<T>::retrieve(const T& toRetrieve, T*& toSet) const {
   return retrieveHelper(toRerieve, toSet, root);
}

template <typename T>
bool BSTree<T>::retrieveHelper(const T& toRetrieve, T*& toSet, Node* node) {
   // null means cannot find the object
   if (node == NULL) return false;

   // can find the object
   else if (*node->data == toRetrieve) {
      toSet = node->data;
      return true;
   }
   
   else if (*node->data > toRetrieve) {
      return retrieveHelper(toRetrieve, toSet, node->left);
   }

   else if (*node->data < toRetrieve) {
      return retrieveHelper(toRetrieve, toSet, node->right);
   }
}

//----------------------------------------------------------------------------
// remove
//----------------------------------------------------------------------------
// Takes in an object to remove from the tree and a pointer to the removed
// object. Sets the passed parameter to the object and deletes the node. All
// its descedents will become the descendents of a new object.
template <typename T>
bool BSTree<T>::remove(const T& toRemove, T*& toSet) {
   bool success;
   return removeHelper(toRemove, toSet, root);
}

//----------------------------------------------------------------------------
// removeHelper
//----------------------------------------------------------------------------
// Recursive helper function of remove.
// Sets the passed parameter to the object and deletes the node. All its
// descedents will become the descendents of a new object
template <typename T>
bool BSTree<T>::removeHelper(const T& toRemove, T*& toSet, Node* node) {
   // null means cannot find the object
   if (node == NULL) return false;

   // can find the object
   else if (*node->data == toRemove) {
      toSet = node->data;
      // case 1: leaf
      if (node->left == NULL && node->right == NULL) {
         delete node;
         node = NULL;
      }
      else {
         Node* replacement;
         // case 2: has left descendents
         if (node->left != NULL) {
            replacement = findLargestObject(node->left);
            node->data = replacement->data;
            delete replacement;
            replacement = NULL;
         }
         // case 3: has right child
         else replacement = node;
         node = node->right;
         delete replacement;
         replacement = NULL;
      }
      return true;
   }
   else if (*node->data > toRemove) {
      return removeHelper(toRemove, toSet, node->left);
   }
   else if (*node->data < toRemove) {
      return removeHelper(toRemove, toSet, node->right);
   }
}

template <typename T>
BSTree<T>::Node* BSTree<T>::findLargestObject(Node* node) {
   if (node->right == NULL) return node;
   else return findLargestObject(node->right);
}
 
template <typename T>
void BSTree<T>::display(std::ostream& output) const {
   displayHelper(root, output);
}

template <typename T>
void BSTree<T>::displayHelper(Node* node, std::ostream& output) {
   if (node != NULL) {
      //display left first
      displayHelper(node->left, output);

      //then display this
      output << node->data;

      //then display right
      displayHelper(node->right, output);
   }
}

template <typename T>
void BSTree<T>::makeEmpty() {
   makeEmptyHelper(root);
}

//----------------------------------------------------------------------------
// makeEmptyHelper
//----------------------------------------------------------------------------
// Recursive helper method for makeEmpty.
// Checks if the node is NULL. If it is not, then traverses left, then right.
// Then, it deletes its data, its node, and points to NULL.
template <typename T>
void BSTree<T>::makeEmptyHelper(Node* node) {
   //does nothing if node is NULL
   if (node != NULL) {
      // make left and right NULL
      makeEmptyHelper(node->left);
      makeEmptyHelper(node->right);

      //delete the node and its data
      delete node->data;
      delete node;
      node = NULL;
   }
}

//----------------------------------------------------------------------------
// isEmpty
//----------------------------------------------------------------------------
// Returns true if there are no objects in the tree (root is NULL).
template <typename T>
bool BSTree<T>::isEmpty() const {
   return root == NULL;
}
#endif