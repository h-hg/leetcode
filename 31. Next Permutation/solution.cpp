#include <vector>
#include <algorithm>
//using library's function
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        std::next_permutation(nums.begin(),nums.end());
    }
};

//principle
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
    	if(nums.size() < 2)
    		return;
    	int i = nums.size() - 2;
    	while(i >= 0 && nums[i+1] <= nums[i])
    		--i;
    	if(i > 0 || (i == 0 && nums[0] < nums[1])) {
    		int j = nums.size() - 1;
    		while(j > i && nums[j] <= nums[i])
    			--j;
    		std::swap(nums[i],nums[j]);
    	}
    	std::reverse(nums.begin() + (i + 1),nums.end());
    }
};