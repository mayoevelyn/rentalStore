//------------------------------------------------------------------------------
// BinTree
//------------------------------------------------------------------------------
// This is a Binary Search Tree that will store many objects. Greater objects
// will be stored on the right and lesser ojects on the left. 
// 
// This binary search tree can be used to find NodeData objects,
// display them either as a tree or in order, empty out itself, empty its 
// data into a sorted array, or build a tree from a sorted array.
// 
// 

#include "bintree.h"

//----------------------------- Constructor ----------------------------------
// Creates an empty binary search tree.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
BinTree::BinTree() {
   size = 0;
   root = NULL;
}

//--------------------------- Copy Constructor -------------------------------
// Creates a binary search tree identical to the passed parameter toCopy.
//----------------------------------------------------------------------------
// Precondition: Assumes that the toCopy parameter is initialized.
//----------------------------------------------------------------------------
BinTree::BinTree(const BinTree& toCopy) {
   root = NULL;
   size = 0;
   *this = toCopy;
}

//----------------------------- Destructor -----------------------------------
// Deletes the binary search tree and all its data.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
BinTree::~BinTree() {
   makeEmpty();
   root = NULL;
}

//--------------------------------- insert -----------------------------------
// Inserts a NodeData object into the tree. Returns true if successfully 
// inserted. It is not inserted if the tru
//----------------------------------------------------------------------------
// Precondition: toInsert is not NULL.
//----------------------------------------------------------------------------
bool BinTree::insert(NodeData* toInsert) {
   bool success = true;
   root = insertHelper(root, toInsert, success);
   return success;
}

//------------------------------ insertHelper --------------------------------
// The recursive al
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
BinTree::Node* BinTree::insertHelper(Node* node, NodeData* toInsert, bool& success) { 
   //if node is null, add the object
   if (node == NULL) {
      node = new Node;
      node->data = toInsert;
      node->left = NULL;
      node->right = NULL;
      size++;
   }

   // if the object is greater than current, go right
   else if (*toInsert > *node->data) node->right = insertHelper(node->right, toInsert, success);
   // if the object is less than current, go left
   else if (*toInsert < *node->data) node->left = insertHelper(node->left, toInsert, success);
   else {
      success = false;
   }
   return node;
}

//-------------------------------- retrieve ----------------------------------
// 
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData& toGet, NodeData*& toSet) const {
   bool success = false;
   retrieveHelper(toGet, toSet, root, success);
   return success;
}

//----------------------------- retrieveHelper -------------------------------
// Recursive function for retrieve.
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
void BinTree::retrieveHelper(const NodeData& toGet, NodeData*& toSet, 
   Node* node, bool& success) const {
   if (node != NULL) {
      if (*node->data != toGet) {
         retrieveHelper(toGet, toSet, node->left, success);
         retrieveHelper(toGet, toSet, node->right, success);
      }
      else {
         toSet = node->data;
         success = true;
      }
   }
}

//-------------------------------- getHeight ---------------------------------
// 
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
int BinTree::getHeight(const NodeData& heightOf) const {
   int height = 0;
   getHeightHelper(root, heightOf, height, 0);
   return height;
}

//----------------------------- getHeightHelper ------------------------------
// Recursive helper function for getHeight.
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
void BinTree::getHeightHelper(const Node* node, const NodeData& heightOf,
   int& height, int lvl) const {
   if (node != NULL) {
      if (*node->data == heightOf) height = lvl;
      else {
         getHeightHelper(node->left, heightOf, height, lvl + 1);
         getHeightHelper(node->left, heightOf, height, lvl + 1);
      }
   }
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
   sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const {
   if (current != NULL) {
      level++;
      sideways(current->right, level);

      // indent for readability, 4 spaces per depth level 
      for (int i = level; i >= 0; i--) {
         cout << "    ";
      }

      cout << *current->data << endl;        // display information of object
      sideways(current->left, level);
   }
}

//------------------------------- makeEmpty ----------------------------------
// Deletes all the nodes and their data in the tree.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
void BinTree::makeEmpty() {
   makeEmptyHelper(root);
   size = 0;
}

//---------------------------- makeEmptyHelper -------------------------------
// The recursive helper function for makeEmpty. If the passed node is not
// null, recurses left, then right, then deletes the data and the node.
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
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

BinTree BinTree::operator=(const BinTree& toCopy) {
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
void BinTree::copyHelper(Node*& thisNode, Node* otherNode) {
   if (otherNode != NULL) {
      Node* thisNode = new Node;
      *thisNode->data = NodeData(*otherNode->data);
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
bool BinTree::operator==(const BinTree& toCompare) const {
   bool isEqual = true;
   isEqualHelper(root, toCompare.root, isEqual);
   return isEqual;
}

//----------------------------- isEqualHelper --------------------------------
//
//----------------------------------------------------------------------------
// Precondition: 
//----------------------------------------------------------------------------
void BinTree::isEqualHelper(Node* node, Node* otherNode,
   bool& isEqual) const {
   if (node == NULL && otherNode == NULL) return;
   else if ((node == NULL && otherNode != NULL) || (node != NULL && 
      otherNode == NULL)) {
      isEqual = false;
      return;
   }
   else if (*node->data != *otherNode->data) {
      isEqual = false;
      return;
   }
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
bool BinTree::operator!=(const BinTree& toCompare) const {
   bool isEqual = (*this == toCompare);
   return (isEqual == false);
}

//------------------------------ Operator << ---------------------------------
// Outputs all the data of the tree in the tree in order.
//----------------------------------------------------------------------------
// Precondition: Assumes ostream output and toOutput are initialized.
//----------------------------------------------------------------------------
ostream& operator<<(ostream& output, BinTree& toOutput) {
   outputHelper(output, toOutput.root);
   output << endl;
   return output;
}
 
//------------------------------ outputHelper --------------------------------
// Recursive helper method for the output operator <<. 
//----------------------------------------------------------------------------
// Precondition: Assumes ostream output and toOutput are initialized.
//----------------------------------------------------------------------------
void outputHelper(ostream& output, BinTree::Node* node) {
    if (node != NULL) {
       outputHelper(output, node->left);
       output << *node->data << " ";
       outputHelper(output, node->right);
    }
 }

//------------------------------ bstreeToArray -------------------------------
// Recursive helper method for the output operator <<. 
//----------------------------------------------------------------------------
// Precondition: Assumes valueArray is a dynamic array and the number of nodes
// is not greater than 100. All values of valueArray is NULL.
//----------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* valueArray[]) {
   int index = 0;
   bstreeToArrayHelper(index, valueArray, root);
}

//--------------------------- bstreeToArrayHelper ----------------------------
// Recursive helper method for bstreeToArray function. 
//----------------------------------------------------------------------------
// Precondition: None.
//----------------------------------------------------------------------------
void BinTree::bstreeToArrayHelper(int& index, NodeData* valueArray[], Node*& node) {
   if (node != NULL) {
      bstreeToArrayHelper(index, valueArray, node->left);
      valueArray[index] = node->data;
      index++;
      bstreeToArrayHelper(index, valueArray, node->right);
      delete node;
      node = NULL;
      size--;
   }
}

void BinTree::arrayToBSTree(NodeData* valueArray[]) {
   int arraySize = 0;
   while (valueArray[arraySize] != NULL) {
      arraySize++;
   }
   arrayToBSTreeHelper(0, arraySize - 1, valueArray);
}

//--------------------------- arraytoBSTreeHelper ----------------------------
// Recursive helper method for the output operator <<. 
//----------------------------------------------------------------------------
// Precondition: Assumes valueArray is a dynamic array.
//----------------------------------------------------------------------------
void BinTree::arrayToBSTreeHelper(int low, int high, NodeData* valueArray[]) {
   int index = (low + high) / 2;
   if (valueArray[index] != NULL) {
      insert(valueArray[index]);
      valueArray[index] = NULL;

      arrayToBSTreeHelper(low, index - 1, valueArray);
      arrayToBSTreeHelper(index + 1, high, valueArray);
   }
}