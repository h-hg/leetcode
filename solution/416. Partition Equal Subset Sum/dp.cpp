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
    sum /= 2;
    int n = nums.size();
    //0-1 package dp[i][j] means whether the package with space j can be fill fully with nums [0, i)
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for(int i = 0; i <= n; ++i)
      dp[i][0] = true;
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= sum; ++j)
        if (j - nums[i - 1] < 0)
          dp[i][j] = dp[i - 1][j]; 
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j-nums[i-1]];
    return dp[n][sum];
  }
};