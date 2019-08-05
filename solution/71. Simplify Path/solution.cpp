#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
class Solution {
public:
    std::string simplifyPath(std::string &path) {
		std::vector<std::string> names;
		std::string name;name.reserve(path.size());
		for(auto c:path)
			if(c != '/')
				name.push_back(c);
			else if(name.empty() == false) /* c == '/' && name.empty() == false */ {
				names.push_back(name);
				name.clear();
			}
    	if(name.empty() == false)//path is not end with '/'
    		names.push_back(name);

		std::vector<std::string> namestack;namestack.reserve(names.size());
		for(auto &str:names)
			if(str == "..") {
				if(namestack.empty() == false)
					namestack.pop_back();
			}
			else if(str != ".")
				namestack.push_back(str);

        if(namestack.empty())
        	return "/";
		std::string ans;
		for(auto &str:namestack)
			ans.append("/").append(str);
		return ans;
    }
};