#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    set<int> s;
    for(auto &num : nums)
      if(num > 0)
        s.insert(num);
    int ans = 1;
    while(1) {
      if(s.count(ans))
        ++ans;
      else
        return ans;
    }
    return ans;
  }
};