#include <vector>
#include <string>
#include <algorithm>
//don't std::use set to speed up
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> ans;
        //in 15.3sum: I use nums[i] <= 0, but in this, we can't use nums[i] <= target is error, for target meybe less than zero, eg [1,-2,-5,-4,-3,3,3,5], target = -11
        for(int i = 0;i < nums.size();++i) 
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;//skip the same value of 1st number
            for(int j = i + 1;j < nums.size();++j) {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;//skip the same value of 2nd number
                int sum = target - nums[i] - nums[j];
                for(int k = j + 1, l = nums.size() -1; k < l;) {
                    int tmp = nums[k] + nums[l];
                    if(tmp < sum)
                        ++k;
                    else if(tmp > sum)
                        --l;
                    else{
                        ans.push_back(std::vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        int lval = nums[k],rval = nums[l];
                        while(k<l && nums[++k] ==lval);//skip the same value
                        while(k<l && nums[--l] ==rval);//skip the same value
                    }
                }

            }
        }
        return ans;
    }
};
#include <iostream>
#include <iterator>
int main()
{
    std::vector<int> v = {0,0,0,0};
    int target = 0;
    Solution solution;
    auto ans = solution.fourSum(v,target);
    for(auto x:ans){
        std::copy(x.begin(),x.end(),std::ostream_iterator<int>(std::cout," "));
        std::cout << std::endl;
    }
    return 0;
}