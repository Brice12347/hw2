#ifndef MY_DATASTORE_H
#define MY_DATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore: public DataStore{
	virtual ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile);
	private:
		map<std::string, set <Product*>>searchResults;
		map<std::string, User*> users;
		//user and product*
		map<std::string, vector<Product*>> cart;
		vector<Product*> allProducts; 
	
};


#endif