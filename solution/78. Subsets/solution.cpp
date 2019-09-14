#include <vector>
//bfs
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        ans.reserve(1 << nums.size());
        ans.push_back(std::vector<int>());//empty set
        if(nums.empty())
            return ans;
        ans.push_back(std::vector<int>{nums.front()});
        for(int i = 1;i < nums.size();++i) {
            int n = ans.size();
            for(int j = 0;j < n;++j) {
                auto tmp(ans[j]);
                tmp.push_back(nums[i]);//the i-th element is chosen
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};