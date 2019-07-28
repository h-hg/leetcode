#include <algorithm>
#include <vector>
#include <set>

//dfs, backtracing

class Solution {
    std::vector<std::vector<int>> res;
    void dfs(std::vector<int> &cur,int target, const std::vector<int> &candidates, int startIndex, int border, std::vector<std::vector<int>> &ans) {
        if (target == 0) 
            ans.push_back(cur);
        else if(startIndex > border)
            return;
        else {
            int val = candidates[startIndex],
                newtarget = target - val;
            if(newtarget < 0)
                return;
            cur.push_back(val);
            //deep search
            dfs(cur, newtarget, candidates, startIndex+1, border, ans);
            //skip the same value
            while(startIndex <= border && candidates[startIndex] == val)
                ++startIndex;
            dfs(cur, target, candidates, startIndex, border, ans);
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> cur;cur.reserve(candidates.size());
        //init
        int border = candidates.size() - 1;//border is the last index of the value that is less or equal than target
        while(candidates[border] > target && border > 0) // for candidates[i] are positive and unique
            --border;
        dfs(cur,target,candidates,0,border,ans);
        return ans;
    }
};