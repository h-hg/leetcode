
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
class Solution {
	std::vector<vector<int>> ans;
private:
	void helper(TreeNode *root, int target, std::vector<int> &cur) {
		target -= root->val;
		cur.push_back(root->val);
		if(root->left == nullptr && root->right == nullptr) {
			if(target == 0)
				ans.push_back(cur);
		} else if(root->left == nullptr)
			helper(root->right, target, cur);
		else if(root->right == nullptr)
			helper(root->left, target, cur);
		else {
			helper(root->left, target, cur);
			helper(root->right, target, cur);
		}
		cur.pop_back();//backtracing
	}
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
        	return ans;
        std::vector<int> cur;
        helper(root, sum, cur);
        return ans;
    }
};