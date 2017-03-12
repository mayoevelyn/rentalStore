//-----------------------------------------------------------------------------
// Title:            HashTable class
// Files:            hashtable.h
//-----------------------------------------------------------------------------
// HashTable class: makes a hash table with the given number of buckets.
//  Is a template of any object type.
//  Includes the following functions:
//  -- insert object
//  -- remove object by identifying object
//  -- remove object by index
//  -- retrieve object by identifying object
//  -- retrieve object by index
//-----------------------------------------------------------------------------


#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename T>
class HashTable {
public:
   HashTable(int defaultSize = 100);
   HashTable(const HashTable&);
   ~HashTable();

   void insert(T*); 
   void remove(const T*&);
   void remove(int);
   T* retrieve(int);
   T* retrieve(const T*&);

private:
   struct Node {
      T* data;
      Node* next;
   };

   int size;
   Node<T>* buckets:
};

#endif
