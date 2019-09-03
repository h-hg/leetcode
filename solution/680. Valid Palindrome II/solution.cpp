class Solution {
private:
	static inline bool isPalindrome(std::string::iterator l, std::string::iterator r){
        while(l < r && *l == *r){
        	++l;
        	--r;
        }
        return !(l < r);
	}
public:
    bool validPalindrome(std::string &s) {
        auto l = s.begin(), r = --s.end();
       	while(l < r && *r == *l) {
       		++l;
       		--r;
       	}
       	return !(l < r) || isPalindrome(l+1, r) || isPalindrome(l,r-1);
    }
};