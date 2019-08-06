//using set
#include <set>
#include <vector>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> s;
        for(auto val:nums){
            if(s.count(val))
                return true;
            s.insert(val);
        }
        return false;
    }
};

//using sort
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
    	std::sort(nums.begin(), nums.end());
    	for(int i = 1;i < nums.size();++i)
    		if(nums[i] == nums[i-1])
    			return true;
    	return false;
    }
};