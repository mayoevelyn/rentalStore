// ------------------------------- BinTree.h ---------------------------------
// Kay Phan CSS 343 
// Created 1/22/2017
// Last Modified 3/13/2017
//----------------------------------------------------------------------------
// Purpose:
//
// The .h file for the BinTree class.
//
// This is a Binary Search Tree that will store many objects. Each Node in
// the tree can have up to two children. Greater objects will be stored on
// the right and lesser ojects on the left of any object.
// 
// This binary search tree can be used to find T objects,
// display them either as a tree or in order, empty out itself, empty its 
// data into a sorted array, or build a tree from a sorted array.
//----------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H

// for output capabilities
#include <iostream>

using namespace std;

template <typename T>
class BinTree {

    struct Node;        // forward declare the struct

public:
    // constructors
    BinTree();				   // default constructor
    BinTree(const BinTree&);   // copy constructor
    ~BinTree();				   // destructor

                                  // public functions
    bool insert(T*);
    bool retrieve(const T&, T*&) const;
    int getHeight(const T&) const;

    void makeEmpty();			//	empties the tree, deletes nodes

                                // overwritten operators
    BinTree& operator=(const BinTree&);
    bool operator==(const BinTree&) const;
    bool operator!=(const BinTree&) const;

    // display function
    void displayTree() const;

    // all private functions and data members
private:
    //private Node struct
    struct Node {
        T* data;
        Node* left;
        Node* right;
    };

    // private data member
    Node* root; // pointer to the root Node

    // helper functions
    void makeEmptyHelper(Node*&);
    Node* insertHelper(Node*, T*, bool&);
    void retrieveHelper(const T&, T*&, Node*, bool&) const;
    void getHeightHelper(const Node*, const T&, int&) const;
    void copyHelper(Node*&, Node*);
    void isEqualHelper(Node*, Node*, bool&) const;
    int branchHeight(const Node*) const;
    void displayTreeHelper(Node*) const;


};
#endif

//----------------------------- Constructor ----------------------------------
// Creates an empty binary search tree with a NULL root.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
template <typename T>
BinTree::BinTree() {
	root = NULL;
}

//--------------------------- Copy Constructor -------------------------------
// Creates a binary search tree identical to the passed parameter toCopy.
//----------------------------------------------------------------------------
// Precondition: Assumes that the toCopy parameter is initialized.
//----------------------------------------------------------------------------
template <typename T>
BinTree::BinTree(const BinTree& toCopy) {
	root = NULL;
	*this = toCopy;
}

//----------------------------- Destructor -----------------------------------
// Deletes the binary search tree and all its data, sets the root to NULL.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
template <typename T>
BinTree::~BinTree() {
	makeEmpty();
	root = NULL;
}

//--------------------------------- insert -----------------------------------
// Inserts the given T object into the tree. Returns true if 
// successfully inserted. It is not inserted if an equivalent object already
// exists in the tree.
//----------------------------------------------------------------------------
// Precondition: toInsert is not NULL.
//----------------------------------------------------------------------------
template <typename T>
bool BinTree::insert(T* toInsert) {
	bool success = true;
	root = insertHelper(root, toInsert, success);
	return success;
}

//------------------------------ insertHelper --------------------------------
// The recursive helper function of insert. Takes in a node, the T
// toInsert, and a reference to bool success for successful insertion.
// If the node is NULL, creates a new node with the given data. If not, 
// and if the node data is equal to toinsert, does not insert anything and 
// sets success to false. Else, recurses.
//----------------------------------------------------------------------------
// Precondition: See insert.
//----------------------------------------------------------------------------
template <typename T>
BinTree::Node* BinTree::insertHelper(Node* node, T* toInsert, bool& 
	success) {
	//if node is null, add the object
	if (node == NULL) {
		node = new Node;
		node->data = toInsert;
		node->left = NULL;
		node->right = NULL;
	}

	// if the object is greater than current, go right
	else if (*toInsert > *node->data)
		node->right = insertHelper(node->right, toInsert, success);
	// if the object is less than current, go left
	else if (*toInsert < *node->data)
		node->left = insertHelper(node->left, toInsert, success);
	else success = false;
	return node;
}

//-------------------------------- retrieve ----------------------------------
// Retrieves the T object equal to the parameter toGet and sets 
// toSet to the T. The value of toSet is unreliable if the object 
// is not found.
//----------------------------------------------------------------------------
// Precondition: Assumes toGet is initialized.
//----------------------------------------------------------------------------
template <typename T>
bool BinTree::retrieve(const T& toGet, T*& toSet) const {
	bool success = false;
	retrieveHelper(toGet, toSet, root, success);
	return success;
}

//----------------------------- retrieveHelper -------------------------------
// Recursive function for retrieve. Takes in the reference to the T 
// toGet, and the pointer that the retrieved object will be set to.
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
template <typename T>
void BinTree::retrieveHelper(const T& toGet, T*& toSet,
	Node* node, bool& success) const {
	if (node != NULL) {

		// recurses if node's data is not equal to toGet
		if (*node->data != toGet) {
			retrieveHelper(toGet, toSet, node->left, success);
			retrieveHelper(toGet, toSet, node->right, success);
		}

		//if found, sets toSet as the node's data, and retrieve is true
		else {
			toSet = node->data;
			success = true;
		}
	}
}

//-------------------------------- getHeight ---------------------------------
// Finds the height of the given T. The height of a node at a leaf is 
// 1, height of a node at the next level is 2, and so on.  
// The height of a value not found is zero. 
//----------------------------------------------------------------------------
// Precondition: Assumes heightOf is initialized. 
//----------------------------------------------------------------------------
template <typename T>
int BinTree::getHeight(const T& heightOf) const {
	int height = 0;
	if (root == NULL) return 0;
	getHeightHelper(root, heightOf, height);
	return height;
}

//----------------------------- getHeightHelper ------------------------------
// Recursive helper function for getHeight. Takes in a node, the object to
// find the height to, a reference to the height, and the current height.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
template <typename T>
void BinTree::getHeightHelper(const Node* node, const T& heightOf,
	int& height) const {
	if (node != NULL) {
		if (*node->data == heightOf) {
			height = branchHeight(node) + 1;
			return;
		}
		else {
			getHeightHelper(node->left, heightOf, height);
			getHeightHelper(node->left, heightOf, height);
		}
	}
}

//------------------------------ branchHeight --------------------------------
// Recursive function that returns the height of the tallest branch in the
// tree. Used to assist getHeightHelper.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
template <typename T>
int BinTree::branchHeight(const Node* node) const {
	if (node == NULL)
		return 0;
	else
	{
		// compute the depth of each subtree 
		int leftlvl = branchHeight(node->left);
		int rightlvl = branchHeight(node->right);

		//use the larger one 

		int currentHeight = ((leftlvl > rightlvl) ? leftlvl : rightlvl);
		return currentHeight + 1;
	}
}

//------------------------------- makeEmpty ----------------------------------
// Deletes all the nodes and their data in the tree.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
template <typename T>
void BinTree::makeEmpty() {
	makeEmptyHelper(root);
}

//---------------------------- makeEmptyHelper -------------------------------
// The recursive helper function for makeEmpty. Deletes the node and its data,
// then recurses.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
template <typename T>
void BinTree::makeEmptyHelper(Node*& node) {
	//does nothing if node is NULL
	if (node == NULL) return;

	// make left and right NULL
	makeEmptyHelper(node->left);
	makeEmptyHelper(node->right);

	//delete NODE
	delete node->data;
	delete node;
	node = NULL;
}

//------------------------------ Operator = ----------------------------------
// Deletes all the existing code and data and then copies all the nodes and
// data from the passed parameter.
//----------------------------------------------------------------------------
// Precondition: Assumes that the toCopy parameter is initialized.
//----------------------------------------------------------------------------
template <typename T>
BinTree& BinTree::operator=(const BinTree& toCopy) {
	makeEmpty();
	copyHelper(root, toCopy.root);
	return *this;
}

//------------------------------ copyHelper ----------------------------------
// Recursive helper method for copying over all the elements of one tree to
// another. It inserts all the node data from the right tree in preorder.
// If the node of the copied tree is NULL, then it doesn't do anything.
//----------------------------------------------------------------------------
// Precondition: Assumes that the toCopy parameter is initialized.
//----------------------------------------------------------------------------
template <typename T>
void BinTree::copyHelper(Node*& thisNode, Node* otherNode) {
	if (otherNode != NULL) {
		thisNode = new Node;
		thisNode->data = new T(*otherNode->data);
		thisNode->left = NULL;
		thisNode->right = NULL;
		copyHelper(thisNode->left, otherNode->left);
		copyHelper(thisNode->right, otherNode->right);
	}
}

//------------------------------ Operator == ---------------------------------
// Returns true if the parameter's data and structure is equal to this.
// equal trees:  a       a      unequal trees:   d        d
//              / \     / \                     / \      / 
//             b   c   b   c                   e   f    e
//                                                     /
//                                                    f
//----------------------------------------------------------------------------
// Precondition: Assumes that the toCompare parameter is initialized.
//----------------------------------------------------------------------------
template <typename T>
bool BinTree::operator==(const BinTree& toCompare) const {
	bool isEqual = true;
	isEqualHelper(root, toCompare.root, isEqual);
	return isEqual;
}

//----------------------------- isEqualHelper --------------------------------
// Recursive helper function for isEqual. Sets the boolean to false if the
// the current node does not have an equivalent counterpart in the other tree.
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
template <typename T>
void BinTree::isEqualHelper(Node* node, Node* otherNode,
	bool& isEqual) const {
	// does not recurse further if both are null
	if (node == NULL && otherNode == NULL) return;

	// if one node is NULL and not the other, then trees are not equal
	else if ((node == NULL && otherNode != NULL) || (node != NULL &&
		otherNode == NULL)) {
		isEqual = false;
		return;
	}

	// if nodes do not have equal data, then trees are not equal
	else if (*node->data != *otherNode->data) {
		isEqual = false;
		return;
	}

	// if nodes are equal, recurse
	else if (*node->data == *otherNode->data) {
		isEqualHelper(node->left, otherNode->left, isEqual);
		isEqualHelper(node->left, otherNode->left, isEqual);
	}
}

//------------------------------ Operator != ---------------------------------
// Returns true if the parameter's data and structure is not equal to this.
// equal trees:  a       a      unequal trees:   d        d
//              / \     / \                     / \      / 
//             b   c   b   c                   e   f    e
//                                                     /
//                                                    f
//----------------------------------------------------------------------------
// Precondition: Assumes that the toCompare parameter is initialized.
//----------------------------------------------------------------------------
template <typename T>
bool BinTree::operator!=(const BinTree& toCompare) const {
	bool isEqual = (*this == toCompare);
	return (isEqual == false);
}


//------------------------------ Operator << ---------------------------------
// Outputs all the data of the tree in the tree in order.
//----------------------------------------------------------------------------
// Precondition: Assumes ostream output and toOutput are initialized.
//----------------------------------------------------------------------------
template <typename T>
void BinTree::displayTree() const {
	displayTreeHelper(root);
}

//------------------------------ outputHelper --------------------------------
// Recursive helper method for the output operator <<. 
//----------------------------------------------------------------------------
// Precondition: Assumes ostream output and toOutput are initialized.
//----------------------------------------------------------------------------
template <typename T>
void BinTree::displayTreeHelper(Node* node) const {
	if (node != NULL) {
		displayTreeHelper(node->left);
        node->data.display();
        cout << endl;
		outputHelper(output, node->right);
	}
}
