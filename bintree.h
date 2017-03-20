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

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

using namespace std;

template <typename T>
class BinTree {

private:
    // private struct class
    struct Node {
        T* data;		//
        Node* right;		//
        Node* left;			//
    };

    Node* root;	// the root of the tree

public:
    // constructors

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// Points head to NULL because no data to begin with
BinTree(){
    // no data
    root = NULL;
}


//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------
// Deletes all data in the tree
~BinTree() {
    makeEmpty();
}

//----------------------------------------------------------------------------
// insert
//----------------------------------------------------------------------------
// Inserts a new object into the tree in order
bool insert(T* object) {
    // start with the overall root
    root = insertHelper(root, object);
    return true;
}

//----------------------------------------------------------------------------
// retrieve
//----------------------------------------------------------------------------
// Takes in an object to retrieve and sets the other object if it is found. 
// Returns false if object not found.
bool retrieve(const T& toRetrieve, T*& toSet) const {
    return retrieveHelper(toRetrieve, toSet, root);
}

//----------------------------------------------------------------------------
// remove
//----------------------------------------------------------------------------
// Takes in an object to remove from the tree and a pointer to the removed
// object. Sets the passed parameter to the object and deletes the node. All
// its descedents will become the descendents of a new object.
bool remove(const T& toRemove, T*& toSet) {
    bool success;
    return removeHelper(toRemove, toSet, root);
}

Node* findLargestObject(Node* node) {
    if (node->right == NULL) return node;
    else return findLargestObject(node->right);
}


void displayTree() const {
    displayHelper(root);
}

void makeEmpty() {
    makeEmptyHelper(root);
}

//----------------------------------------------------------------------------
// makeEmptyHelper
//----------------------------------------------------------------------------
// Recursive helper method for makeEmpty.
// Checks if the node is NULL. If it is not, then traverses left, then right.
// Then, it deletes its data, its node, and points to NULL.
void makeEmptyHelper(Node* node) {
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
bool isEmpty() const {
    return root == NULL;
}

private:

//----------------------------------------------------------------------------
// insertHelper
//----------------------------------------------------------------------------
// Recursive helper function for insert. It returns a pointer to a node.
// If the node is NULL, the object is inserted there. If the object to insert 
//  is greater than the current, then it recurses right; else, left.
Node* insertHelper(Node* node, T* object) {
    //if node is null, add the object
    if (node == NULL) {
        node = new Node;
        node->data = object;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    // if the object is greater than current, go right
    else if (*object > *node->data) node->right = insertHelper(node->right, object);
    // if the object is less than current, go left
    else if (*object < *node->data) node->left = insertHelper(node->left, object);
    return node;
}

//----------------------------------------------------------------------------
// retrieveHelper
//----------------------------------------------------------------------------
// Recursive helper function for retrieve. Takes in an object to retrieve and sets the 
// other object if it is found. Returns false if object not found.
bool retrieveHelper(const T& toRetrieve, T*& toSet, Node* node) const {
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
// removeHelper
//----------------------------------------------------------------------------
// Recursive helper function of remove.
// Sets the passed parameter to the object and deletes the node. All its
// descedents will become the descendents of a new object
bool removeHelper(const T& toRemove, T*& toSet, Node* node) {
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

void displayHelper(Node* node) const {
    if (node != NULL) {
        //display left first
        displayHelper(node->left);

        //then display this
        cout << *(node->data);

        //then display right
        displayHelper(node->right);
    }
}
};
#endif
