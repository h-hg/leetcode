#include <string>
class Solution {
public:
    int lengthOfLastWord(std::string &s) {
        if(s.empty())
        	return 0;//eg ""
        int r = s.size() - 1;
        while(s[r] == ' ' && r > 0)
        	--r;
        if(r == 0)
        	if(s[r] == ' ')
        		return 0;//eg " "
        	else
        		return 1;//eg "a "

        int l = r - 1;
        while(s[l] != ' ' && l > 0)
        	--l;
        if(l == 0)
            if(s[l] == ' ')
    		    return r;//eg " a"
            else
                return r + 1;//eg "ab"
        return r - l;//eg "a b"
    }
};