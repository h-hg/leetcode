/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	int getDepth(TreeNode *root) {
		if(root == nullptr)
			return 0;
		return 1 + std::max(getDepth(root->left), getDepth(root->right));
	}
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        else if(abs(getDepth(root->left) - getDepth(root->right)) > 1)
        	return false;
       	else
       		return isBalanced(root->left) && isBalanced(root->right);
    }
};

//Reduce repeat counting of height
class Solution {
private:
	std::map<TreeNode*, int> depths;
	//a function to calculate the height of every node, only one pass
	void getDepth(TreeNode * root) {
		if(root == nullptr)
			return;
		if(root->left == nullptr && root->right == nullptr) {
			depths[root] = 1;
			return;
		}
		getDepth(root->left);
		getDepth(root->right);
		depths[root] = std::max(depths[root->left], depths[root->right]) + 1;
	}
	bool helper(TreeNode * root) {
		if(root == nullptr)
			return true;
		else if(abs(depths[root->left] - depths[root->right]) > 1)
			return false;
		else
			return helper(root->left) && helper(root->right);
	}
public:
	bool isBalanced(TreeNode * root) {
		getDepth(root);
		return helper(root);
	}
};

//combine two fucntions: getDepth and isBalanced
class Solution{
private:
	//return the depth of root, return -1 when root is unbalanced
	int dfs(TreeNode* root) {
		if(root == nullptr)
			return 0;
		int ldepth = dfs(root->left);
		if(ldepth == -1)
			return -1;
		int rdepth = dfs(root->right);
		if(rdepth == -1)
			return -1;
		return abs(ldepth - rdepth) > 1 ? -1 : std::max(ldepth, rdepth) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {
		return dfs(root) != -1;
	}
};