//using library's function
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        std::sort(nums.begin(),nums.end());
        do{
            ans.push_back(nums);
        }while(std::next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};


//dfs (backtracking)
class Solution {
private:
	void dfs(std::vector<int> &cur, int idx, std::vector<std::vector<int>> &ans)
	{
		if(idx == cur.size()) {
			ans.push_back(cur);
			return;
		}
		for(int i = idx; i < cur.size(); ++i) {
			std::swap(cur[i],cur[idx]);
			dfs(cur, idx+1, ans);
			std::swap(cur[i], cur[idx]);
		}
	}
public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums) {
		std::vector<std::vector<int>> ans;
		if(nums.size() == 0)
			return ans;
		dfs(nums,0,ans);
		return ans;
	}
};