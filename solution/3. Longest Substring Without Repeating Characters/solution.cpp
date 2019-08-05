#include <string>
//force - mine, similar to leetcode solution 2 - sliding windows, [l,r)
class Solution {
public:
    int lengthOfLongestSubstring(std::string &s) {
    	if(s.size() < 2)
    		return s.size();
		int ans = 0,l = 0,r = 0;
		for(r = 1;r < s.size();++r) {
			//judge: ∃ i ∈ [l,r), s[i] == s[r]
			int i;
			for(i = l;i < r;++i)
				if(s[i] == s[r])
					break;
			if(i == r)
				continue;
			ans = std::max(ans,r - l);
			l = i + 1;//not ++l
		}
    	return max(ans,r-l);
    }
};

//using set to speed up
#include <set>
#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string &s) {
    	if(s.size() < 2)
    		return s.size();
    	std::map<char,int> val2pos;
		int ans = 0,l = 0,r = 0;
		for(r = 1;r < s.size();++r) {
			
		}
    	return max(ans,r-l);
    }
};