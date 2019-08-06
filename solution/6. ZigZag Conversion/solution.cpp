#include <string>
#include <vector>
class Solution {
public:
    std::string convert(std::string &s, int numRows) {
        if(numRows == 1)//to avoid division by zero
            return s;
        int T = numRows * 2 - 2;//T == circle
        std::vector<std::string> m(numRows);
        for(int i = 0;i < s.size();++i) {
            int tmp = i % T;
            int row = tmp < numRows ? tmp : (numRows - 1)- (tmp + 1 - numRows);
            m[row].push_back(s[i]);
        }
        std::string ans;
        for(auto str:m)
            ans += str;
        return ans;
    }
};