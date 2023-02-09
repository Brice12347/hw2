// product.cpp and change virtual
#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"
using namespace std;

clothing::clothing(std::string size, std::string brand, std::string prodName, double price, int qty,const std::string category) :
    name_(prodName),
    price_(price),
    qty_(qty),
    category_(category)
{
	size_ = size;
	brand_ = brand;
}

clothing::~Product()
{

}


double clothing::getPrice() const
{
    return price_;
}

std::string clothing::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{	
    return false;
}

void Product::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << size_ << brand_ << endl;
}

string Product::displayString() const{
	string result = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + price_ + " " + qty_ + " left.";
	return result;
}
set<std::string> Product::keywords() const{
		set<string> result; 
		result = setUnion(parseStringToWords(convToLower(brand_)), result);
		result = setUnion(parseStringToWords(convToLower(name_)), result);
		return result;
}




