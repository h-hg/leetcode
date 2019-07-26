#include <vector>
//a simple solution, average O(logn)
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while( l <= r) {
        	int mid =  l + (r - l) / 2;
        	if(nums[mid] < target)
        		l = mid + 1;
        	else if(nums[mid] > target)
        		r = mid - 1;
        	else {
        		int ans_l = l, ans_r = r;
        		while(nums[ans_l] != target)
        			++ans_l;
        		while(nums[ans_r] != target)
        			--ans_r;
        		return std::vector<int>{ans_l,ans_r};
        	}
        }
        return std::vector<int>{-1,-1};
    }
};
//binary search using STL, O(logn)
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
		auto first = lower_bound(begin(nums), end(nums), target);
		if(first == end(nums) || *first != target)
			return {-1, -1};
		auto last = --(upper_bound(begin(nums), end(nums), target));
		return {first - begin(nums), last - begin(nums)};
    }
};
//binary search with small change
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
    	std::vector<int> ans = {-1, -1};
    	if(nums.size() == 0)
    		return ans;
        //find the leftmost target
        int l = 0, r = nums.size() - 1;
        while( l <= r) {
        	int mid =  l + (r - l) / 2;
        	if(nums[mid] < target)
        		l = mid + 1;
        	else //nums[mid] >= target
        		r = mid - 1;
        }
        if(l < nums.size() && nums[l] != target)//l < nums.size() for case input = [2,2], 3
        	return ans;
        else
        	ans[0] = l;
    	//find the rightmost target
    	r = nums.size() - 1;
    	while( l <= r) {
    		int mid = l + (r - l) / 2;
    		if(nums[mid] > target)
    			r = mid - 1;
    		else //nums[mid] <= target
    			l = mid + 1;
    	}
    	ans[1] = r;
        return ans;
    }
};