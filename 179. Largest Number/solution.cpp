#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iostream>
class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> strnums;
        strnums.reserve(nums.size());
        std::transform(
        	nums.begin(),
        	nums.end(),
        	std::back_inserter(strnums),
        	[](int num) {
        		return std::to_string(num);
        	}
        );

        //small change in the dictionary sort
        std::sort(
        	strnums.begin(),
        	strnums.end(),
        	[](const std::string &x, const std::string &y)->bool{
        		if(x.size() == y.size())
        			return x < y;
        		auto a = x + y, b = y + x;
        		return a < b;
        	}
        );

        if(strnums.back() == "0")
        	return "0";
        return std::accumulate(strnums.rbegin(), strnums.rend(), std::string(""));
    }
};