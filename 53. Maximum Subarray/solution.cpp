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

	    int min = nums[0], max = nums[0];//max = max{ nums[j] - nums[i] }, i < j, min = min{ num[si] }
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
int main()
{
	std::vector<int> nums = {-2,-1};
    Solution solution;
    std::cout << solution.maxSubArray(nums) << std::endl;
	return 0;
}