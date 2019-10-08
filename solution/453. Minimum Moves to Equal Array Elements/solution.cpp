class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int minval = nums.front();
        for(auto num:nums)
            minval = std::min(num, minval);
        int ans = 0;
        for(auto num:nums)
            ans += num - minval;
        return ans;
    }
};