#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include "product.h"
#include <string>

class book: public Product{
	public:
		book(std::string author, std::string isbn, std::string prodName, double price, int qty,const std::string category);
		//write getters and setters
		~book();
			// delete book;
		std::string displayString() const;
		void dump(std::ostream& os) const;
		bool isMatch(std::vector<std::string>& searchTerms) const;
		std::set<std::string> keywords() const;

	private:
	std::string author_;
	std::string isbn_;

};
#endif