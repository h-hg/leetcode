#include <vector>
#include <map>
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    	std::map<int,int> val2pos; //pos is always the large 
        for(int i = 0; i < nums.size(); ++i) {
        	auto res = val2pos.find(nums[i]);
        	if(res != val2pos.end()) {
        		if(i - res->second <= k)
        			return true;
        		else
        			res->second = i;
        	} else
                val2pos[nums[i]] = i;
        }
        return false;
    }
};