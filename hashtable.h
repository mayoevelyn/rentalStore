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
   T* retrieve(const T*&)

private:
   struct Node {
      T* data;
      Node* next;
   };

   int size;
   Node<T>* buckets:
};

#endif
