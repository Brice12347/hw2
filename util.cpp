#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
	//where do i make lowercase
	stringstream ss(rawWords);
	string temp;
	string placeholder = "";
	set<std::string> result;
	//try check use
	//for every word in rawWords
	while(ss >> temp){
		//for every letter in the word
		for(int i = 0; i < temp.length(); i++){
			//if the letter wasnt a punctuation
				if(!ispunct(temp[i]) ){
					//add it to the placeholder
				placeholder+=temp[i];
		} else{
			//when we run into a punctuation
				if(placeholder.length() > 1){
					//if the place holder isnt a single letter add it to result
						result.insert(placeholder);
				}
				placeholder = "";
		}
				
		}
		
		if(placeholder.length() > 1){
				result.insert(placeholder);
		}
		placeholder = "";

	}

	return result;


}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
