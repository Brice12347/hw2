#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include "product.h"
#include <string>

class movie: public Product{
	public:
		movie(std::string genre, std::string rating, std::string prodName, double price, int qty,const std::string category);
		//write getters and setters
		~movie();
			// delete book;
		std::string displayString() const;
		void dump(std::ostream& os) const;
		bool isMatch(std::vector<std::string>& searchTerms) const;
		std::set<std::string> keywords() const;

	private:
	std::string genre_;
	std::string rating_;

};
#endif