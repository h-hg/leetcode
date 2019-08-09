#include <algorithm>
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        int ans = 0;
        for(auto val:citations){
            if(val <= ans) //it means that there are ans or ans+1 values that are >= ans
                return ans;
            ++ans;
        }   
        return ans;
    }
};