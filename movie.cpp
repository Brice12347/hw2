// product.cpp and change virtual
#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
#include "util.h"
using namespace std;

movie::movie(std::string genre, std::string rating, std::string prodName, double price, int qty,const std::string category) :
    Product(category,prodName,price,qty)
{
	genre_ = genre;
	rating_ = rating;
}

movie::~movie()
{

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
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n"<< genre_<< "\n" << rating_ <<  endl;
}

string movie::displayString() const{
		string result = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_)+ " " + to_string(qty_) + " left.";
		return result;
}
set<std::string> movie::keywords() const{
		set<string> result; 
        set<string> temp;
        
		result = parseStringToWords(convToLower(name_));
		// temp = parseStringToWords(convToLower(genre_));
        // for(set<string> :: iterator it = temp.begin(); it != temp.end(); ++it){
        //     result.insert(*it);
        // }
		result.insert(convToLower(genre_));
		return result;
}




