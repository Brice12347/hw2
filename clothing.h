#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
#include <iostream>
#include "product.h"
#include <string>

class clothing: public Product{
	public:
		clothing(std::string size, std::string brand, std::string prodName, double price,int qty,const std::string category);
		//write getters and setters
		~clothing();

		std::string displayString() const;
		void dump(std::ostream& os) const;
		bool isMatch(std::vector<std::string>& searchTerms) const;
		std::set<std::string> keywords() const;

	private:
	std::string size_;
	std::string brand_;

};
#endif