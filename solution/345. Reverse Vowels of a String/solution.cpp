//two pointer
#include <string>
class Solution {
private:
    inline bool isVowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    std::string reverseVowels(std::string &s) {
        if(s.empty())
            return s;
        auto l = s.begin(), r = --s.end();
        while(l < r) {
            if(isVowels(*l) == false)
                ++l;
            else if(isVowels(*r) == false)
                --r;
            else
                std::swap(*l++, *r--);
        }
        return s;
    }
};

//stack
class Solution {
private:
    inline bool isVowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    std::string reverseVowels(std::string &s) {
    	std::string vs;//vowels' stack
    	vs.reserve(s.size());
    	for(auto c:s)
    		if(isVowels(c))
    			vs.push_back(c);
    	for(auto &c:s)
    		if(isVowels(c)){
    			c = vs.back();
    			vs.pop_back();
    		}
    	return s;
    }
};