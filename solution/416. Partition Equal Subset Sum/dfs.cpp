#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)
      return false;
    return dfs(nums, 0, sum / 2);
  }
  bool dfs(vector<int> &nums, int idx, int sum) {
    if(sum == 0)
      return true;
    else if(idx == nums.size())
      return false;
    return dfs(nums, idx + 1, sum - nums[idx]) || dfs(nums, idx + 1, sum);
  }
};