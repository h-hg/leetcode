#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> pancakeSort(vector<int> &A) {
    vector<int> ans;
    for(int n = A.size(); n > 1; --n) {
      int maxPos = distance(A.begin(), max_element(A.begin(), A.begin() + n)) + 1;
      if(maxPos == n)
        continue;
      std::reverse(A.begin(), A.begin() + maxPos);
      ans.push_back(maxPos);
      std::reverse(A.begin(), A.begin() + n);
      ans.push_back(n);
    }
    return ans;
  }
};