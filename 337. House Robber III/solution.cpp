#include <map>
#include <algorithm>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  map<TreeNode *, int> tb;
  int rob(TreeNode *root) {
    if (root == nullptr)
      return 0;
    if (tb.count(root))
      return tb[root];
    auto l = root->left, r = root->right;
    int rob_it = root->val + (l ? rob(l->left) + rob(l->right) : 0) + (r ? rob(r->left) + rob(r->right) : 0);
    int not_rob = rob(l) + rob(r);
    int ans = max(rob_it, not_rob);
    tb[root] = ans;
    return ans;
  }
};