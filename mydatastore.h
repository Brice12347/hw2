#ifndef MY_DATASTORE_H
#define MY_DATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include <map>

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);


	private:
		std::map<std::string, std::set <Product*> >searchResults;
		std::map<std::string, User*> users;
		//user and product*
		std::map<std::string, std::vector<Product*> > cart;
		std::vector<Product*> allProducts; 

    public:
    //use these in amazon.cpp
        std::map<std::string, std::vector<Product*> >* getCart();
        std::map<std::string, User*>* getUsers();
        bool isValidName(std::string name);
        void addToCart(std::string name, Product* p);
        void buyItem(std::string name,Product* p);
        double balance(std::string name);
        //nevermind
        //void insertPair(string name, vector<Product*> values);


	
};


#endif