#include <algorithm>
#include <map>
#include <vector>
//Mine
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> ans(2);
    	std::map<int,int> val2pos;
    	for(std::size_t i = 0;i < nums.size();++i)
    		val2pos[nums[i]] = i;
    	for(std::size_t i = 0;i < nums.size();++i) {
    		auto diff = target - nums[i];
    		auto res = val2pos.find(diff);
    		if(res != val2pos.end() && res->second != i) {
    			//res -> second != i make sure that it isn't itself
    			ans[0] = i;
    			ans[1] = res->second;
    			break;
    		}
    	}
    	return ans;
    }
};


//Leetcode solution 3 - one-pass
/*
 虽然在边建立hash表边查找diff，前面的不一定的找得到，但是后面的一定找得到
*/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> ans(2);
    	std::map<int,int> val2pos;
    	for(std::size_t i = 0;i < nums.size();++i) {
    		auto diff = target - nums[i];
    		auto res = val2pos.find(diff);
    		if(res != val2pos.end() && res->second != i) {
    			ans[0] = res->second;
    			ans[1] = i;
    			break;
    		}
    		val2pos[nums[i]] = i;
    	}
    	return ans;
    }
};