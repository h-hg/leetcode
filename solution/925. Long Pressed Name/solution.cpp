//Group into Blocks
//eg aaacc -> a 3 c 3
class Solution {
private:
	inline std::vector<std::pair<char, int>> str2IR(const std::string &str) {
		char lastchar = '\0';//a tag which won't be in the string
		std::vector<std::pair<char, int>> ret;
		for(auto c:str)
			if(c == lastchar)
				++ret.back().second;
			else {
				ret.push_back(std::pair<char,int>{c, 1});
				lastchar = c;
			}
		return ret;
	}
public:
    bool isLongPressedName(std::string &name, std::string &typed) {
    	auto nameIR = str2IR(name), typedIR = str2IR(typed);
    	if(nameIR.size() != typedIR.size())
    		return false;
    	for(int i = 0;i < nameIR.size();++i)
    		if(nameIR[i].first != typedIR[i].first)
    			return false;
    		else if(nameIR[i].second > typedIR[i].second)
    			return false;
    	return true;
    }
 };
 
//two pointer : time: O(n), space: O(1)
class Solution {
public:
    bool isLongPressedName(std::string &name, std::string &typed) {
        if(name.empty() || typed.empty())
        	return name.size() == typed.size();
        char lastchar = '\0';//a tag which won't be in name
        auto first1 = name.begin(), last1 = name.end(),
             first2 = typed.begin(), last2 = typed.end();
        while(first1 != last1 && first2 != last2)
        	if(*first1 == *first2) {
        		lastchar = *first1;
        		++first1;
        		++first2;
        	} else if(lastchar == *first2)
				++first2;
        	else
    			return false;
    	if(first1 != last1)
    		return false;
    	while(first2 != last2)
    		if(*first2++ != lastchar)
    			return false;
    	return true;
    }
};