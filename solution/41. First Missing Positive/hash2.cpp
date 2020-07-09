#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size() + 1;
    vector<bool> hash(n, false);
    for(auto &num : nums)
      if(0 < num && num < n)
        hash[num] = true;
    return distance(hash.begin(), find(hash.begin() + 1, hash.end(), false));
  }
};