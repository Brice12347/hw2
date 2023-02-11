// product.cpp and change virtual
#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"
#include "util.h"
using namespace std;

clothing::clothing(std::string size, std::string brand, std::string prodName, double price, int qty,const std::string category) :
    Product(category,prodName,price,qty)
{
	size_ = size;
	brand_ = brand;
}

clothing::~clothing()
{

}



/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool clothing::isMatch(std::vector<std::string>& searchTerms) const
{	
    return false;
}

void clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n"<< size_ << "\n"<< brand_ << endl;
}

string clothing::displayString() const{
	string result = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
	return result;
}
set<std::string> clothing::keywords() const{
		set<string> result; 
        set<string> temp;
        
		result = parseStringToWords(convToLower(name_));
		temp = parseStringToWords(convToLower(brand_));
        for(set<string> :: iterator it = temp.begin(); it != temp.end(); ++it){
            result.insert(*it);
        }

		return result;
}




