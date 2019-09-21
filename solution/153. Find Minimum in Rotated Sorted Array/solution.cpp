class Solution {
public:
    int findMin(std::vector<int>& nums) {
        if(nums.size()==1 || nums.front() < nums.back())
            return nums[0];
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = l + ((r-l)>>1);
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid] < nums[mid-1])
                return nums[mid];
            if(nums[l] < nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};