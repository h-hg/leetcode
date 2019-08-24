#include <string>
#include <algorithm>
class Solution {
public:
    std::string reverseStr(std::string &s, int k) {
        for(int i = 0;i < s.size();) {
            int i_k = i + k, i_2k = i_k + k;
            if(i_2k <= s.size()) {
                std::reverse(s.begin() + i, s.begin() + i_k);
                i = i_2k;
            } else if(i_k <= s.size()) {
                std::reverse(s.begin() + i, s.begin() + i_k);
                break;
            } else{
                std::reverse(s.begin() + i, s.end());
                break;
            }
        }
        return s;
    }
};


//leetcode solution 1 - Direct
class Solution {
public:
    std::string reverseStr(std::string &s, int k) {
        for(int i = 0;i < s.size(); i += (k << 1)) {
            int j = std::min(i+k, (int)s.size());
            std::reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};