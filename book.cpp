// product.cpp and change virtual
#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
using namespace std;

book::book(std::string author, std::string isbn, std::string prodName, double price, int qty,const std::string category) :
    name_(prodName),
    price_(price),
    qty_(qty),
    category_(category)
{
	author_ = author;
	isbn_ = isbn;
}

book::~book()
{

}


double book::getPrice() const
{
    return price_;
}

std::string book::getName() const
{
    return name_;
}

void book::subtractQty(int num)
{
    qty_ -= num;
}

int book::getQty() const
{
    return qty_;
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
		string result = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + price_ + " " + qty_ + " left.";
		return result;
}
set<std::string> book::keywords() const{
		set<string> result; 
		result = setUnion(parseStringToWords(convToLower(name_)), result);
		result = setUnion(parseStringToWords(convToLower(author_)), result);
		result.insert(isbn_);
		return result;
}




