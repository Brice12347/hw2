// product.cpp and change virtual
#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
using namespace std;

movie::movie(std::string genre, std::string rating, std::string prodName, double price, int qty,const std::string category) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{
	genre_ = genre;
	rating_ = rating;
}

movie::~movie()
{

}


double movie::getPrice() const
{
    return price_;
}

std::string movie::getName() const
{
    return name_;
}

void movie::subtractQty(int num)
{
    qty_ -= num;
}

int movie::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool movie::isMatch(std::vector<std::string>& searchTerms) const
{	
    return false;
}

void movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << genre_ << rating_ << brand_ << endl;
}

string movie::displayString() const{
		string result = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + price_ + " " + qty_ + " left.";
		return result;
}
set<std::string> movie::keywords() const{
		set<string> result; 
		result = setUnion(parseStringToWords(convToLower(genre_)), result);
		result = setUnion(parseStringToWords(convToLower(name_)), result);
		return result;
}




