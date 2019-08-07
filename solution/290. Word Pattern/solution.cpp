#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
class Solution {
public:
	bool wordPattern(std::string &pattern, std::string &str)
	{
		//std::map<char, std::string> p2str;//pattern to string
		std::vector<std::string> p2str(26);//as pattern only contain lowercase letters, use vector to speed up
        std::set<std::string> words;
		auto iter_word = str.begin();
		for(auto iter_p = pattern.begin();iter_p !=  pattern.end();++iter_p) {
			if(iter_word == str.end())
				return false; // pattern.size() != words in str
			//get the word
			auto iter_word_end = iter_word;
            do{
				++iter_word_end;
            } while(*iter_word_end != ' ' && iter_word_end != str.end());
			std::string word(iter_word,iter_word_end);
            //judge
			int idx = *iter_p - 'a';
			if(p2str[idx].empty()) {
                if(words.count(word))//there are two or more letters is mapping to the same word
                    return false;
                words.insert(word);
				p2str[idx].swap(word);//using swap to reduce cost
            } else if ( p2str[idx] != word )
				return false;
			//update iter_word
            iter_word = iter_word_end != str.end() ? ++iter_word_end : iter_word_end;
		}
		return iter_word == str.end();//to judge whethre words is more than pattern.size()
	}
};