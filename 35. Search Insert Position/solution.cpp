#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = l + (r - l) /2;
        while(l < r) {
        	if(nums[ans] == target)
        		break;
        	else if(nums[ans] < target)
        		l = ans + 1;
        	else
        		r = ans -1;
        	ans = l + (r - l) / 2;
        }
        if(nums[ans] == target)
        	return ans;
        //find first position p ∈[0,nums.size()] that nums[p] > target
        if(nums[ans] < target) {
        	do{
        		++ans;
        	}while(ans < nums.size() && nums[ans] < target);
        	return ans;
        }
        else { //nums[ans] > target
        	if(ans == 0)
        		return 0;
        	while(ans > 0 && nums[ans-1] > target)
        		--ans;
        	return ans;
        }
    }
};
//deal with some specification to speed up

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
    	if (nums.size() == 0 || target <= nums[0] )
			return 0;
		if (target > nums[nums.size()-1] )
			return nums.size()
        int l = 0, r = nums.size() - 1, ans = l + (r - l) /2;
        while(l < r) {
        	if(nums[ans] == target)
        		break;
        	else if(nums[ans] < target)
        		l = ans + 1;
        	else
        		r = ans -1;
        	ans = l + (r - l) / 2;
        }
        if(nums[ans] == target)
        	return ans;
        //find first position p ∈[0,nums.size()] that nums[p] > target
        if(nums[ans] < target) {
        	do{
        		++ans;
        	}while(ans < nums.size() && nums[ans] < target);
        	return ans;
        }
        else { //nums[ans] > target
        	while(ans > 0 && nums[ans-1] > target)
        		--ans;
        	return ans;
        }
    }
};