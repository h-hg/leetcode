#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> ans;
  void pancakeSort(vector<int> &A, int n) {
    if(n <= 1)
      return;
    int maxPos = distance(A.begin(), max_element(A.begin(), A.begin() + n)) + 1;
    if(maxPos != n) {
      std::reverse(A.begin(), A.begin() + maxPos);
      ans.push_back(maxPos);
      std::reverse(A.begin(), A.begin() + n);
      ans.push_back(n);
    }
    pancakeSort(A, n - 1);
  }
  vector<int> pancakeSort(vector<int> &A) {
    pancakeSort(A, A.size());
    return ans;
  }
};