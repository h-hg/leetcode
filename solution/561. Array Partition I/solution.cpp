class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i < nums.size(); i+=2)
        	ans += nums[i];
        return ans;
    }
};