#include <map>
#include <vector>
#include <functional>
#include <algorithm>
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> val2cnt;
        for(auto val:nums)
            ++val2cnt[val];
        std::vector<std::pair<int,int>> v(val2cnt.begin(),val2cnt.end());
        
        std::sort(
            v.begin(),
            v.end(),
            [](const std::pair<int,int> &x, const std::pair<int,int> &y)->bool{
                return x.second > y.second;  
            }
        );
        std::vector<int> ans;
        ans.reserve(k);
        for(auto iter = v.begin();k--;++iter)
            ans.push_back(iter->first);
        return ans;
    }
};

//using multimap to replace sort, to make it easier to read
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int,int> val2cnt;
        for(auto val:nums)
            ++val2cnt[val];
        std::multimap<int,int> cnt2val;
        for(auto &val: val2cnt)
            cnt2val.emplace(val.second, val.first);
        std::vector<int> ans;
        ans.reserve(k);
        for(auto iter = cnt2val.rbegin();k--;++iter)
            ans.emplace_back(iter->second);
        return ans;
    }
};
