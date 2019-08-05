#include <vector>
#include <algorithm>
//sort
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};


//count
#include <map>
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
    	std::map<int,int> val2cnt;
    	int n = nums.size() / 2;
        for(auto val:nums)
        	if(++val2cnt[val] > n)
        		return val;
        return 0;//redundant
    }
};


//Boyer-Moore Voting Algorithm
class Solution {
public:
	int majorityElement(std::vector<int>& nums) {
        int count = 0, candidate = 0;
        
        for (int num : nums) {
            if (count == 0)
                candidate = num;
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};