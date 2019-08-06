#include <string>
class Solution {
public:
	inline bool isPalindrome(const std::string &s,int l,int r) {
		--r;
		while(l < r)
			if(s[l++] != s[r--])
				return false;
		return true;
	}
    std::string longestPalindrome(std::string &s) {
    	if(s.size()  == 0 || s.size() == 1)
    		return s;
        int maxlen = 0,ans_l = 0;
        for(int l = 0;l < s.size();++l)
        	for(int r = s.size(); r - l > maxlen;--r)
        		if(isPalindrome(s,l,r)) {
    				ans_l = l;
    				maxlen = r - l;
    			}
    	return maxlen ? std::string(s,ans_l,maxlen) : std::string();
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        
        // edge cases
        if(s.length() == 0 || s.length() == 1) return s;
        
        // to hold max len and its starting index
        int maxLenBeginIndex = 0;
        int maxLen = 1;
        
        int mid = 0;
        while(mid < s.length()){
            
            // calculating middle window
            
            int midBegin = mid;
            int midEnd = mid;
            
            // handling even length palindromes; the middlemost chars will trivially match in even length case
            // so expand the middle window as long as possible
            while( midEnd + 1 < s.length() && s[midEnd] == s[midEnd + 1]){ midEnd++ ; }
            
            // for next iteration
            mid = midEnd + 1;
            
            // starting comparison in left and right windows
            
            // in case of odd len palindrome; both start from mid;
            // in case of even; midBegin and midEnd handles it all
            int leftWindow = midBegin;
            int rightWindow = midEnd;
            
            // expand the windows left and right simultaneously
            while(leftWindow - 1 >= 0 && rightWindow + 1 < s.length() && s[leftWindow - 1] == s[rightWindow + 1]){
                    leftWindow--;
                    rightWindow++;
            }
            
            // update maxLen is currLen > maxLen
            int currLen = rightWindow - leftWindow + 1;
            if( currLen  > maxLen ){
                maxLenBeginIndex = leftWindow;
                maxLen = currLen;
            }
        }
        
        return s.substr(maxLenBeginIndex, maxLen);
    }
};