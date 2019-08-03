#include <string>
//two pass
class Solution {
public:
    bool isPalindrome(std::string &s) {
        std::string str;
        str.reserve(s.size());
        for(auto c:s)
        	if( ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') )
        		str.push_back(c);
        	else if('A' <= c && c <= 'Z')
        		str.push_back(c - 'A' + 'a');//lower case
        auto l = str.begin(), r = --str.end();
        while(l < r)
        	if(*l++ != *r--)
        		return false;
        return true;
    }
};

//one pass
//one pass
class Solution {
private:
	inline bool isalnum(char c){
		return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
	}
	inline char lowercase(char c) {
		return ('A' <= c && c <= 'Z') ? (c - 'A' + 'a') : c;
	}
public:

    bool isPalindrome(std::string &s) {
    	auto l = s.begin(), r = --s.end();
    	while(l < r)
    		if(isalnum(*l) == false)
    			++l;
    		else if(isalnum(*r) == false)
    			--r;
    		else if(lowercase(*l++) != lowercase(*r--))
    			return false;
        return true;
    }
};