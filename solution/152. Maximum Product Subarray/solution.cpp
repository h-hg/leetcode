#include <vector>
#include <algorithm>
//dp space O(1)
class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        int curmin = 1, curmax = 1, ans = INT_MIN;
        for(auto num:nums) {
            if(num < 0)
                std::swap(curmin,curmax);
            curmax = std::max(curmax*num,num);
            curmin = std::min(curmin*num,num);
            ans = std::max(ans, curmax);
        }
        return ans;
    }
};