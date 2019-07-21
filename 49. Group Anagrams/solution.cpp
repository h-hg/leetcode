#include <vector>
#include <string>
#include <algorithm>
#include <map>
//Approach 1: Categorize by Sorted String
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if(strs.size() == 0)
        	return std::vector<std::vector<std::string>>();	
        std::map<std::string, std::vector<std::string> > m;
        for(auto &str : strs) {
        	auto str_c = str;
        	std::sort(str_c.begin(), str_c.end());
        	m[str_c].push_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        ans.reserve(m.size());
        for(auto & v : m)
        	ans.push_back(v.second);
        return ans;
    }
};
//Approach 2: Categorize by Count
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if(strs.size() == 0)
        	return std::vector<std::vector<std::string>>();	
        std::map<std::string, std::vector<std::string> > m;
        for(auto &str : strs) {
        	std::vector<int> counts(26,0);
        	for(auto c:str)
        		++counts[c-'a'];
        	std::string key;
       		for(auto val:counts)
       			key.append(std::to_string(val)).push_back('#');
        	m[key].push_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        ans.reserve(m.size());
        for(auto & v : m)
        	ans.push_back(v.second);
        return ans;
    }
};