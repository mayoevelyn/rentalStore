//----------------------------------store.cpp----------------------------------
// Store class: This is the class for a store of DVD itmes. It has three kinds
// of DVDs, classic, drama, and comedy. It also has a list of customers/users
// who may borrow and return these DVDs. 
//-----------------------------------------------------------------------------
#include "store.h"

//----------------------------------Constructor--------------------------------
// Initializes the classic, comedy and drama inventories, as well as the users.
//-----------------------------------------------------------------------------
Store::Store() {
    classicInven = new BinTree<DVD>;
    comedyInven = new BinTree<DVD>;
    dramaInven = new BinTree<DVD>;
    users = new HashTable<User>;
}

//----------------------------------Destructor---------------------------------
// Destroys all classic, comedy and drama inventories, as well as the users.
// Sets pointers to NULL.
//-----------------------------------------------------------------------------
Store::~Store() {
    delete classicInven;
    classicInven = NULL;
    delete dramaInven;
    dramaInven = NULL;
    delete comedyInven;
    comedyInven = NULL;
    delete users;
    users = NULL;
}

//--------------------------------buildInventory-------------------------------
// Takes in a file and builds inventory of DVDs. Assumes inputs are of valid 
// reading format, though not necessarily valid content.
//-----------------------------------------------------------------------------
void Store::buildInventory(ifstream& infile) {
    DVD* ptr;
    char dvdType;
    string str;

    // while there is still data
    for (;;) {
        // reads one line
        getline(infile, str);

        if (infile.eof()) break;

        // extracts the first char for dvdType
        dvdType = str[0];

        // use factory to create appropriate DVD type
        ptr = dvdFactory.makeDVD(dvdType);

        // don't add to inventory if no DVD is made
        if (ptr == NULL) continue;

        // set the DVD data
        ptr->setData(str);
        
        BinTree<DVD>* inventory = NULL;
        // get the correct tree to add to
        switch (dvdType) {
        case 'F': inventory = comedyInven;
            break;
        case 'D': inventory = dramaInven;
            break;
        case 'C': inventory = classicInven;
            break;
        default:
            // if incorrect movie type, continue
            cout << "Invalid movie type " << dvdType << endl;
            delete ptr;
            ptr = NULL;
            continue;
        }
        
        DVD* addTo = NULL;
        bool dvdExists = inventory->retrieve(*ptr, addTo);
        if (dvdExists) {
            addTo->addStock(ptr);
            delete ptr;
        }
        else {
            inventory->insert(ptr);
        }
    }
}

//----------------------------------buildUsers---------------------------------
// Takes in a file and adds users. Assumes inputs are of valid format: user ID,
// last name, then first name. Example: "3333 Mouse Minnie"
//-----------------------------------------------------------------------------
void Store::buildUsers(ifstream& infile) {
	User* ptr;
	string str;

	// while there is still data
    for (;;) {
		// read one line
		getline(infile, str);

        if (infile.eof()) return;

        ptr = new User;
		// pass the line into setData
		ptr->setData(str);
		// try to insert user
		bool success = users->insert(ptr, ptr->getID());
		// if insert unsuccessful, delete the ptr
		if (!success) delete ptr;
	}
}

//-----------------------------applyTrasactions--------------------------------
// Takes in a file of commands. Does not apply commands if they are of invalid
// format. Currently only takes in D (DVD) type transactions.
//-----------------------------------------------------------------------------
void Store::applyTransactions(ifstream& infile) {
	Transaction* t = NULL;
	char transType = ' ';
	string str = "";

	for (;;) {
        getline(infile, str);
        // do not continue if eof
        if (infile.eof()) break;

        transType = str[0];
		t = transFactory.makeTransaction(transType);

        // jump to next loop if not valid transaction type
		if (t == NULL) {
			cout << "Invalid transaction type " << transType << endl;
            continue;
		}
		else {
			t->setData(str);
			bool executed = t->execute(dynamic_cast<Store*>(this));
            if (transType == 'I' || !executed) delete t;
		}
	}
}

//-----------------------------------getUsers----------------------------------
// Returns a pointer to users.
//-----------------------------------------------------------------------------
HashTable<User>* Store::getUsers() const {
    return users;
}

//---------------------------------getComedyInven------------------------------
// Returns a pointer to comedy DVD inventory.
//-----------------------------------------------------------------------------
BinTree<DVD>* Store::getComedyInven() const {
    return comedyInven;
}

//---------------------------------getClassicInven-----------------------------
// Returns a pointer to classic DVD inventory.
//-----------------------------------------------------------------------------
BinTree<DVD>* Store::getClassicInven() const {
    return classicInven;
}

//----------------------------------getDramaInven------------------------------
// Returns a pointer to drama DVD inventory.
//-----------------------------------------------------------------------------
BinTree<DVD>* Store::getDramaInven() const {
    return dramaInven;
}

//-----------------------------------getStoreName------------------------------
// Returns store name.
//-----------------------------------------------------------------------------
string Store::getStorename() const {
    return storeName;
}
