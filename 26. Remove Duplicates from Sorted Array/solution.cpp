class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int len = 1, lastnum = nums[0];
		for(int i = 1;i < nums.size();++i)
			if(nums[i] != lastnum)
				lastnum = nums[len++] = nums[i];
		return len;      
    }
};