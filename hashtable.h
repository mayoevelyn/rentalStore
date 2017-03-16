//---------------------------------hashtable.h---------------------------------
// The HashTable has a default size of 101. This table uses a single hash
// to insert an object, based on a key that it is given. It can also remove
// and retrieve objects.
//-----------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

// prime number of buckets
const int TABLESIZE = 101;

using namespace std;

template <typename T>
class HashTable {
private:
    struct TableNode {
        T* data;
        bool deleted;
        int objectKey;
    };

    TableNode *objectsArray[TABLESIZE];

public:
    // constructor and destructor
    HashTable();
    ~HashTable();


    bool insert(T* toInsert, int key);   // inserts object based on key
    void remove(int key);                // removes object based on key
    bool retrieve(T*& toSet, int key);
};
#endif

//---------------------------------Constructor---------------------------------
// Constructor for the HashTable. Sets all pointers to NULL.
//-----------------------------------------------------------------------------
template <typename T>
HashTable<T>::HashTable() {
    for (int i = 0; i < TABLESIZE; i++) {
        objectsArray[i] = NULL;
    }
}

//----------------------------------Destructor---------------------------------
// Destructor for the HashTable.
// Goes through each pointer. If the pointer is not NULL, then deletes
// the node's data, then the node, then sets pointer to NULL.
//-----------------------------------------------------------------------------
template <typename T>
HashTable<T>::~HashTable() {
    for (int i = 0; i < TABLESIZE; i++) {
        if (objectsArray[i] != NULL) {
            delete objectsArray[i]->data;
            delete objectsArray[i];
            objectsArray[i] = NULL;
        }
    }
}

//-------------------------------------insert-----------------------------------
// Inserts a T object into the table based on the key. Rehashes to a new key
// if occupied. Returns false if key already exists.
//-----------------------------------------------------------------------------
template <typename T>
bool HashTable<T>::insert(T* toInsert, int key) {
    int d = 1;
    int index = key % TABLESIZE;
    for (;;) {
        if (objectsArray[index] == NULL) break;
        if (ojbectsArray[index]->key == key) return false;
        index = (key + d) % TABLESIZE;
        d++;
    }
    objectsArray[index] = new TableNode();
    objectsArray[index]->data = toInsert;
    objectsArray[index]->deleted = false;
    objectsArray[index]->objectKey = key;
}

//------------------------------------remove-----------------------------------
// Marks the T object at the given key as removed.
//-----------------------------------------------------------------------------
template <typename T>
void HashTable<T>::remove(int key) {
    int d = 1;
    int index = key % TABLESIZE;
    for (;;) {
        if (objectsArray[index] == NULL) return; // not existent
        if (objectsArray[index]->objectKey == key) break;
        index = (key + d) % TABLESIZE;
        d++;
    }
    objectsArray[index]->deleted = true;
}

//----------------------------------retrieve-----------------------------------
// Marks the T object at the given key as removed.
//-----------------------------------------------------------------------------
template <typename T>
bool HashTable<T>::retrieve(T*& toSet, int key) {
    int d = 1;
    int index = key % TABLESIZE;
    for (;;) {
        if (objectsArray[index] == NULL) return false; // not existent
        if (objectsArray[index]->objectKey == key) break;
        index = (key + d) % TABLESIZE;
        d++;
    }
    if (objectsArray[index]->deleted == true) return false; // deleted
    toSet = objectsArray[index]->data;
    return true;
}
