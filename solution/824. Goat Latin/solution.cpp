#include <string>
#include <vector>
class Solution {
public:
    std::string toGoatLatin(std::string &S) {
    	//split
 		std::vector<std::string> words;
		std::string word;
		for(auto c:S)
			if( ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') )
				word.push_back(c);
			else {
				words.push_back(word);
				word.clear();
			}
		if(word.size())
			words.push_back(word);
		//process
		int i = 1;
		for(auto &str:words) {
			char c = str.front();
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
				str.append("ma").append(i, 'a');
			else
				str = str.substr(1, str.size() - 1).append(1,c).append("ma").append(i, 'a');
			++i;
		}
		//merge
		std::string ans = words.front();
		for(int i = 1;i < words.size();++i)
			ans.append(1,' ').append(words[i]);
		return ans;
    }
};