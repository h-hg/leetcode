#include <vector>
#include<cstdio>
#include <iostream>
#include <iterator>
#include <algorithm>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
	    //nums = prefix_sum, prefix_sum[i] = nums[0] + nums[1] + ... + nums[i]
	    for(int i = 1; i < nums.size();++i)
	    	nums[i] += nums[i-1];

	    int min = nums[0], max = nums[0];//max = max{ nums[i] - nums[j], nums[i] }, j < i, min = min{ nums[i] }
	    for(int i = 1;i < nums.size();++i) {
	    	max = std::max(max,std::max(nums[i]-min,nums[i]));
	    	if(nums[i] < min)
	    		min = nums[i];
	    }

	    return max;
    }
};
//base on above, convert two pass to one pass
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
    	int max = nums[0], min = nums[0];
    	for(int i = 1;i < nums.size();++i) {
    		nums[i] += nums[i-1];
    		max = std::max(max, std::max(nums[i]-min,nums[i]));
    		if(nums[i] < min)
    			min = nums[i];
    	}

	    return max;
    }
};

//dp space O(n)
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size());//dp[i] is the maxSubArray of nums[0,i] which must include nums[i]
        int ans = dp.front() = nums.front();
        for(int i = 1;i < nums.size();++i) {
            dp[i] = std::max(nums[i],nums[i]+dp[i-1]);
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};

//dp space O(1)
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int dp = nums.front(), ans = dp;
        for(int i = 1;i < nums.size();++i) {
            dp = std::max(nums[i],nums[i]+dp);
            ans = std::max(ans, dp);
        }
        return ans;
    }
};