#include <vector>
#include <string>
#include <utility>
#include <algorithm>
class Solution {
private:
	typedef std::pair<char,int> elem;
	typedef std::vector<elem> IR;//Intermediate representation 
	static inline IR str2IR(const std::string &str) {
		IR ret;
		char lastchar = str.front();
		ret.push_back(elem{lastchar,1});
		for(int i = 1;i < str.size();++i) {
			if(str[i] == lastchar)
				++ret.back().second;
			else
				ret.push_back(elem{str[i],1});
			lastchar = str[i];
		}
		return ret;
	}
	inline bool isStretchy(const IR &S, const IR &word){
		if(word.size() != S.size())
			return false;
		auto iter1 = S.begin(), last1 = S.end(), iter2 = word.begin();
		while(iter1 != last1) {
			if(iter1->first != iter2->first)
				return false;
			if(iter1->second < iter2->second)
				return false;
			if(iter1->second != iter2->second && iter1->second < 3)
				return false;
			++iter1;
			++iter2;
		}
		return true;
	}
public:
    int expressiveWords(std::string S, std::vector<std::string>& words) {
        auto SIR = str2IR(S);
        std::vector<IR> wordsIR(words.size());
        std::transform(words.begin(), words.end(), wordsIR.begin(), str2IR);
        int ans = 0;
        for(auto &wordIR:wordsIR)
        	if(isStretchy(SIR, wordIR))
        		++ans;
        return ans;
    }
};