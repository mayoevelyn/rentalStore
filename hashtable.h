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

    HashTable() {
        for (int i = 0; i < TABLESIZE; i++) {
            objectsArray[i] = NULL;
        }
    }

    //----------------------------------Destructor---------------------------------
    // Destructor for the HashTable.
    // Goes through each pointer. If the pointer is not NULL, then deletes
    // the node's data, then the node, then sets pointer to NULL.
    //-----------------------------------------------------------------------------
    ~HashTable() {
        for (int i = 0; i < TABLESIZE; i++) {
            if (objectsArray[i] != NULL) {
                delete objectsArray[i]->data;
                delete objectsArray[i];
                objectsArray[i] = NULL;
            }
        }
    }

    bool insert(T* toInsert, int key) {
        int d = 1;
        int index = key % TABLESIZE;
        for (;;) {
            if (objectsArray[index] == NULL) break;
            if (objectsArray[index]->objectKey == key) return false;
            index = (key + d) % TABLESIZE;
            d++;
        }
        objectsArray[index] = new TableNode();
        objectsArray[index]->data = toInsert;
        objectsArray[index]->deleted = false;
        objectsArray[index]->objectKey = key;
        return true;
    }


    void remove(int key) {
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

    bool retrieve(T*& toSet, int key) {
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
};
#endif
