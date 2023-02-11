#include <string>
#include <set>
#include <vector>
#include <map>
#include "mydatastore.h"
#include "util.h"
#include "user.h"
#include "product.h"
//uh ph


using namespace std;
MyDataStore::MyDataStore(){
	
}

MyDataStore::~MyDataStore(){
	for(map<string, User*>::iterator it = users.begin(); it != users.end(); ++it){
		delete it->second;
	}

	for(unsigned int i = 0; i < allProducts.size(); i++){
		delete allProducts[i];
	}
}

void MyDataStore::addProduct(Product* p){
	allProducts.push_back(p);
	//get keywords from product
	set<string> temp = p->keywords();
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
	users.insert(make_pair(u->getName(),u));
	vector <Product*> vect;
	cart[u->getName()] = vect;
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type){
	if(type == 0){
		//x terms
		//for each terms 
		//the keywir
		//and
		vector<Product*> result;
		set<Product*> temp2;
		if(searchResults.find(terms[0]) == searchResults.end()){
			return result;
		}else{
			set <Product*> temp = searchResults[terms[0]];
			if(searchResults.find(terms[1]) == searchResults.end()){
				return result;
			}else{
				temp2 = setIntersection(searchResults[terms[1]], temp);
			}
		}
		
		
			
		// set <Product*> compare1 = searchResults[terms[0]];
		// set <Product*> compare2 = searchResults[terms[1]];
		// if(searchResults.find(terms[0]) != searchResults.end() && searchResults.find(terms[1]) != searchResults.end() && compare1 == compare2){
		// 	cout << "checks out" << endl;
		// 	temp = setUnion(searchResults[terms[0]], temp);
		// 	temp = setUnion(searchResults[terms[1]], temp);
		// }
		// unsigned int iterate = 0;
		// for(iterate; iterate < terms.size(); iterate++){
		// 	if(searchResults.find(terms[iterate]) != searchResults.end()){
		// 		cout << "found first word" << endl;
		// 		temp=searchResults[terms[iterate]];
		// 		break;
		// 	}
		// }
		
		// for(unsigned int i = 1; i< terms.size(); i++){
		// 	if(searchResults.find(terms[i]) != searchResults.end()){
		// 		temp2 = setIntersection(searchResults[terms[i]], temp);
		// 	}
		// }

		set<Product*>:: iterator it = temp2.begin();
		for(it; it != temp2.end(); ++it){
			result.push_back(*it);
		}
		return result;
		
		
	}else if(type == 1){

		vector<Product*> result;
		vector<string>::iterator it = terms.begin();
		set<Product*> temp;
		for(it; it != terms.end(); it++){
			if(searchResults.find(*it) != searchResults.end()){
				temp = setUnion(searchResults[*it], temp );
			}
		}
		
		for(set<Product*>:: iterator it = temp.begin(); it != temp.end(); ++it){
			result.push_back(*it);
		}
		return result;
		
	}
}

void MyDataStore::dump(ostream& ofile){
	ofile <<"<products>" << endl;
	for(vector<Product*>:: iterator it = allProducts.begin(); it != allProducts.end(); ++it){
		(*it)->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for(map<string, User*>:: iterator it = users.begin(); it !=users.end(); ++it ){
		users[it->second->getName()]->dump(ofile);
	}
	ofile << "</users>" << endl;
	
}

map<std::string, vector<Product*> >* MyDataStore::getCart(){
    return &cart;
}
map<std::string, User*>* MyDataStore::getUsers(){
    return &users;
}
bool MyDataStore::isValidName(string name){
    if(users.find(name)!= users.end()){
        return true;
    }

    return false;
}

void MyDataStore::addToCart(std::string name, Product* p){
	cart.at(name).push_back(p);
}
void MyDataStore::buyItem(std::string name,Product* p){
	p->subtractQty(1);
	users.at(name)->deductAmount(p->getPrice());
	vector<Product*>::iterator it = find(cart.find(name)->second.begin(), cart.find(name)->second.end(), p);
	cart.find(name)->second.erase(it);
}
double MyDataStore::balance(string name){
	return users.at(name)->getBalance();
}
// void MyDataStore::insertPair(string name, vector<Product*> values){
// 	cart.insert(make_pair(name,values));
// }