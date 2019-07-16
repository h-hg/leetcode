#include <string>
class Solution {
public:
    bool isValid(std::string &s) {
    	char map[1 << sizeof(char)*8];
    	map[')'] = '(';
    	map['}'] = '{';
    	map[']'] = '[';
        std::string stack;
        for(auto c:s) {
        	switch(c) {
	        	case '(':
	        	case '{':
	        	case '[':
	        		stack.push_back(c);
	        		break;
	        	case ')':
	        	case '}':
	        	case ']':
	        		if(stack.empty() == false && stack.back() == map[c]) {
	        			stack.pop_back();
	        			break;
	        		}
	        		return false;
	        }
        }
        return stack.empty();
    }
};
#include <vector>
#include <iostream>
int main()
{
	std::vector<std::string> v = {"()","()[]{}","(]","([)]", "{[]}"};
	Solution solution;
	for(int i = 0;i < v.size();++i)
		std::cout << i << ". " << v[i] << ": " << solution.isValid(v[i]) << std::endl;
	return 0;
}