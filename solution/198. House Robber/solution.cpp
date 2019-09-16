#include <vector>
//dp space O(n)
class Solution {
public:
    int rob(std::vector<int>& nums) {
        //special case
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        //dp: dp[i] = max{dp[i-2]+nums[i], dp[i-1]}
        std::vector<int> dp(nums.size());
        dp[0] = nums.front();
        dp[1] = std::max(dp[0],nums[1]);
        for(int i = 2;i < nums.size();++i)
            dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
        return dp.back();
    }
};

//dp space O(1)
class Solution {
public:
    int rob(std::vector<int>& nums) {
        int prev1 = 0, prev2 = 0, cur = 0;
        for (auto num:nums) {
            cur = std::max(prev2, prev1 + num);
            prev1 = prev2;
            prev2 = cur;
        }
        return cur;
    }
};