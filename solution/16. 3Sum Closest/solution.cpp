#include <cstdint>//INT_MAX
#include <cstdlib>//abs
#include <vector>
#include <algorithm>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int diff = INT_MAX,ans;
        std::sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-2;++i) {
        	if(i > 0 && nums[i] == nums[i-1])
        		continue;//skip the reputation
        	for(int j = i + 1, k = nums.size()-1;j < k;) {
        		int sum = nums[i]+nums[j]+nums[k];
        		int newdiff = sum -target;
        		if(newdiff < 0) {
        			++j;
        			newdiff = -newdiff;
        		}
        		else if(newdiff > 0)
        			--k;
        		else
        			return target;
        		if(newdiff < diff) {
        			ans = sum;
        			diff = newdiff;
        		}
        	}
        }
        return ans;
    }
};