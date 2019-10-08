
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int ans = 0;
	//preorder
	void helper(TreeNode *root, int num) {
		num = num * 10 + root->val;
		if(root->left == nullptr && root->right == nullptr) {
			ans += num;
			return;
		}
		if(root->left)
			helper(root->left, num);
		if(root->right)
			helper(root->right, num);
	}
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        helper(root, 0);
        return ans;
    }
};