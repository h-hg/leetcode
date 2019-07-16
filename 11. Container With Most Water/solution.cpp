#include <vector>
#include <iostream>
#include <algorithm>
//more info see proof.md
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int ans = 0;
        for(int l =0, r = height.size()-1;l < r;)
        	if(height[l] < height[r]){
        		ans = std::max(ans,(r-l)*height[l]);
        		++l;
        	} else {
        		ans = std::max(ans,(r-l)*height[r]);
        		--r;
        	}
        return ans;
    }
};