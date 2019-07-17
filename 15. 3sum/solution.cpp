#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
//mine - force
class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
		std::set<std::vector<int>> ans_set;
        for(int i = 0;i < nums.size() && nums[i] <= 0;++i) {
            int sum = -nums[i];
            for(int j = i + 1, k = nums.size() -1; j < k;) {
                int tmp = nums[j] + nums[k];
                if(tmp < sum)
                    ++j;
                else if(tmp > sum)
                    --k;
                else{
                    ans_set.insert(std::vector<int>{nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                }
            }
        }
        std::vector<std::vector<int>> ans;
        for(auto &x:ans_set)
            ans.push_back(x);
		return ans;
	}
};

//don't std::use set to speed up
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> ans;
        for(int i = 0;i < nums.size() && nums[i] <= 0;++i) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;//skip the same value of first number
            int sum = -nums[i];
            for(int j = i + 1, k = nums.size() -1; j < k;) {
                int tmp = nums[j] + nums[k];
                if(tmp < sum)
                    ++j;
                else if(tmp > sum)
                    --k;
                else{
                    ans.push_back(std::vector<int>{nums[i],nums[j],nums[k]});
                    int l = nums[j],r = nums[k];
                    while(j<k && nums[++j] ==l);//skip the same value
                    while(j<k && nums[--k] ==r);//skip the same value
                }
            }
        }
        return ans;
    }
};
