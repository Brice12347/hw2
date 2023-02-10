// product.cpp and change virtual
#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"
using namespace std;

book::book(std::string author, std::string isbn, std::string prodName, double price, int qty,const std::string category) :
    Product(category,prodName,price,qty)
{
	author_ = author;
	isbn_ = isbn;
}

book::~book()
{

}




/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool book::isMatch(std::vector<std::string>& searchTerms) const
{	
    return false;
}

void book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << isbn_ << author_ << endl;
}

string book::displayString() const{
		string result = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" +to_string(price_)+ " " + to_string(qty_) + " left.";
		return result;
}
set<std::string> book::keywords() const{
		set<string> result; 
        set<string> temp;
        
		result = parseStringToWords(convToLower(name_));
		temp = parseStringToWords(convToLower(author_));
        for(set<string> :: iterator it = temp.begin(); it != temp.end(); ++it){
            result.insert(*it);
        }
		result.insert(isbn_);
		return result;
}




