#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
//tree
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string &digits) {
        if(digits.size() == 0)
            return std::vector<std::string>();
        std::vector<std::string> table = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};// a map, digit to string
        std::list<std::string> q;//queue
        //init
        for(auto c:table[digits[0]-'0'])
            q.push_back(std::string(1,c));
        //for each digit except the first
        for(int idx = 1; idx < digits.size(); ++idx) {
            int digit = digits[idx] - '0';
            
            int n = q.size();
            //for every current string
            for(int j = 0; j < n; ++j) {
                auto front = q.front();//why error when use auto &front = q.front();
                q.pop_front();
                
                //for each letter
                for(auto c:table[digit])
                    q.push_back(std::string(front).append(1,c));
            }

        }
        //list -> vector
        std::vector<std::string> ans;ans.reserve(q.size());
        ans.assign(q.begin(),q.end());
        return ans;
    }
};