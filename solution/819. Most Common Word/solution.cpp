#include <string>
#include <algorithm>
#include <vector>
#include <map>
class Solution {
private:
	inline std::vector<std::string> toWords(const std::string &paragraph){
		std::vector<std::string> words;
		std::string word;
		for(auto c:paragraph)
			if('a' <= c && c <= 'z')
				word.push_back(c);
			else if('A' <= c && c <= 'Z')
				word.push_back(c - 'A' + 'a');
			else {
				if(word.empty())
					continue;
				words.push_back(word);
				word.clear();
			}
		if(word.size())
			words.push_back(word);
		return words;
	}
public:
    std::string mostCommonWord(std::string &paragraph, std::vector<std::string>& banned) {
        std::sort(banned.begin(), banned.end());
        auto words = toWords(paragraph);
        std::map<std::string, int> word2cnt;
        int mostfreq = 0;
        std::string *pans = nullptr;
        for(auto &str:words)
        	if(std::binary_search(banned.begin(), banned.end(), str) == false) {
        		int freq = ++word2cnt[str];
        		if(freq > mostfreq) {
        			mostfreq = freq;
        			pans = &str;
        		}

        	}
        return *pans;
    }
};