#include <vector>
#include <string>
class Solution {
private:
	//a function to judge whether acnts can make up bcnts
	static inline bool isSubSet(const std::vector<int> &acnts,const std::vector<int> &bcnts){
		for(int i = 0;i < 26;++i)
			if(acnts[i] < bcnts[i])
				return false;
		return true;
	}
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& A, std::vector<std::string>& B) {
        //a function to count the letter in the str
        auto str2cnt = [](const std::string &str) {
        	std::vector<int> cnts(26,0);
        	for(auto c:str)
        		++cnts[c-'a'];
        	return cnts;
        };
    	std::vector<int> maxbcnts(26,0);//maxbcnts[i] is the max conut of letter 'a'+i in every word of B
    	for(auto &str:B) {
    		auto iter = maxbcnts.begin();
    		for(auto cnt :str2cnt(str)) {
    			if(cnt > *iter)
    				*iter = cnt;
    			++iter;
    		}
    	}
    	//for every word in A, judge whether it is universal.
        std::vector<std::string> ans;
    	for(auto &str:A)
    		if(isSubSet(str2cnt(str), maxbcnts))
    			ans.push_back(str);
    	return ans;
    }
};