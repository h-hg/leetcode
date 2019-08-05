#include <algorithm>
#include <vector>
#include <limits>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minval = INT_MAX, ans = 0;
        for(auto val:prices){
        	ans = std::max(ans, val - minval);
        	minval = std::min(minval, val);
        }
        return ans;
    }
};