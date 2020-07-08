#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if(n == 0)
      return 0;
    //dp[i] is max length of subsequence of nums [0, i]
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j])
          dp[i] = max(dp[j] + 1, dp[i]);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};