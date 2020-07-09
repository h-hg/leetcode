#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>
using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = 1;
    for(auto &num : nums) {
      if(ans > num)
        continue;
      else if(num == ans)
        ++ans;
      else
        return ans;
    }
    return ans;
  }
};