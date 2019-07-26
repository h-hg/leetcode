#include <vector>
class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		return bsearch(nums, 0, nums.size(), target);//nums.size()-1, for input[1] 1
    }
    
    // Modified binary search: instead of trying to find the pivot point,
    // we recurse both left and right on every call.
    int bsearch(std::vector<int>& nums, int lo, int hi, int target) {
        if (hi <= lo) return -1;
        
        int mid = (hi + lo) / 2;
        
        if (nums[mid] == target) return mid;
        
        int left = bsearch(nums, lo, mid, target);
        int right = bsearch(nums, mid + 1, hi, target);
        
        // As there are no duplicates, at least one 
        // of `left` and `right` must be -1 (i.e.
        // there cannot be two `targets` in the array)
        if (left != -1)
        	return left;
        else if (right != -1)
        	return right;
        else
        	return -1;
    }
};

//c++ just straightforward binary search which checks for rotation
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
        	int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
			    //If mid is bigger than both left and right then 
			    //check on which side should target exist
                if (nums[mid] >= nums[r] && nums[mid] >= nums[l] && nums[l] > target)//eg. input = [4,5,6,7,8,0,1,2,3], nums[mid] = 8, target = 2, nums[mid] >= nums[l] means [l,mid] is asc
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
			    // The same check but if mid is less than both left and right
                if (nums[mid] <= nums[r] && nums[mid] <= nums[l] && nums[r] < target)//eg input = [5, 6, 7, 8, 0, 1, 2, 3, 4] nums[mid] = 0, target = 2
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};