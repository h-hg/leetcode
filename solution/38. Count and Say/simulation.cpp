#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
  string countAndSay(int n) {
    string ans = "1";
    while (--n) {
      string curStr = "";
      //get the next count-and-say
      for (int i = 0, n = ans.size(); i < n; ++i) {
        int cnt = 1;
        while (ans[i] == ans[i + 1] && i + 1 < n) {
          ++cnt;
          ++i;
        }
        curStr += to_string(cnt);
        curStr.push_back(ans[i]);
      }
      swap(ans, curStr);
    }
    return ans;
  }
};