#include <vector>
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        auto dp = triangle.back();
        //mininum sum from bottom to top
        for(int level = triangle.size() - 1; level > 0;--level)
            for(int i = 1; i <= level;++i)
                dp[i-1] = std::min(dp[i],dp[i-1]) + triangle[level-1][i-1];
        return dp.front();
    }
};