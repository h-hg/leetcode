#include <string>
#include <algorithm>
class Solution {
public:
    std::string reverseWords(std::string &s) {
        int first = 0, last = 0;
        for(auto c:s){
        	if(c == ' ') {
        		std::reverse(s.begin() + first, s.begin() + last);
        		first = last + 1;
        	}
        	++last;
        }
        std::reverse(s.begin() + first, s.end());
        return s;
    }
};