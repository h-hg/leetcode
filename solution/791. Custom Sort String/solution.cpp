#include <algorithm>
#include <string>
#include <climits>
#include <vector>
class Solution {
public:
    std::string customSortString(std::string &S, std::string &T) {
    	std::vector<int> priority(256, INT_MAX);
        for(int i = 0;i < S.size();++i)
        	priority[S[i]] = i;
        std::sort(T.begin(), T.end(), [&priority](char x, char y)->bool{return priority[x] < priority[y];});
        return T;
    }
};