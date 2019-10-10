#include <string>
#include <vector>
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> nums;
        std::set<std::string> s = {"+", "-", "*", "/"};
        for(auto &token: tokens)
        	if(s.count(token) == 0)
        		nums.push(stoi(token));
        	else {
        		auto x = nums.top(); nums.pop();
        		switch(token.front()) {
        			case '+':
        				nums.top() += x;
        				break;
        			case '-':
        				nums.top() -= x;
        				break;
        			case '*':
        				nums.top() *= x;
        				break;
        			case '/':
        				nums.top() /= x;
        				break;
        		}
        	}
        return nums.top();
    }
};