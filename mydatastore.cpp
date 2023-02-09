#include <string>
#include <set>
#include <vector>
#include <map>
#include "mydatastore.h"
#include "util.h"
#include "user.h"
using namespace std;

void MyDataStore::addProduct(Product* p){
	allProducts.push_back(p);
	//get keywords from product
	set<string> temp = p.keywords();
	set<string>::iterator it = temp.begin();

	for(it; it != temp.end(); ++it){
			if(searchResults.find(*it) != searchResults.end()){
				searchResults[*it].insert(p);
			}else{
				set<Product*> newSet;
				newSet.insert(p);
				searchResults.insert(make_pair(*it,newSet));

			}
	}

}

void MyDataStore::addUser(User* u){
	users.insert({u.getName(),u});
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type){
	if(type == 0){
		//x terms
		//for each terms 
		//the keywir
		//and
		vector<Product*> result;
		
		set<Product*> temp = searchResults[terms[0]];
		for(unsigned int i = 1; i< terms.size(); i++){
			if(searchResults.find(terms[i]) != searchResults.end()){
				temp = setIntersection(searchResults->second, temp);
			}
		}

		set<Product*>:: iterator it = temp.begin();
		for(it; it != temp.end(); ++it){
			result.push_back(it*);
		}
		return result;
		
		
	}else if(type == 1){

		vector<Product*> result;
		vector<string>::iterator it = terms.begin();
		set<Product*> temp;
		for(it; it != terms.end(); it++){
			if(searchResults.find(*it) != searchResults.end()){
				temp = setUnion(searchResults->second, temp );
			}
		}
		set<Product*>::iterator it = temp.begin();
		for(it; it != temp.end(); ++it){
			result.push_back(it*);
		}
		return result;
		
	}
}

void MyDataStore::dump(ostream& ofile){
	ofile <<"<products>" << endl;
	for(vector<Product*>:: iterator it = allProducts.begin(); it != allProducts.end(); ++it){
		it->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for(map<string, User*>:: iterator it= users.begin(); it !=users.end(); ++it ){
		it->dump(ofile);
	}
	ofile << "</users>" << endl;
	
}