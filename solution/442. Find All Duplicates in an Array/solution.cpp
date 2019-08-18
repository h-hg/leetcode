#include <vector>
#include <cmath>
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> ans;
        for(auto val:nums) 
            if(nums[abs(val)-1] > 0)
                nums[abs(val)-1] *= -1;
            else
                ans.push_back(abs(val));
        return ans;
    }
};