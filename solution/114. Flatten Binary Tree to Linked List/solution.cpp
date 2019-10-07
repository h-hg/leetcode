
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



//using vector, time: O(n), space O(n)
#include <vector>
class Solution {
private:
	std::vector<TreeNode *> l;
	void helper(TreeNode *root) {
		if(root == nullptr)
			return;
		l.push_back(root);
		helper(root->left);
		helper(root->right);
	}
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
        	return;
        helper(root);
        for(int i = 0, n = l.size() - 1;i < n;++i) {
        	l[i]->left = nullptr;
        	l[i]->right = l[i+1];
        }
        l.back()->left = l.back()->right = nullptr;
    }
};


//time: O(n), space:O(1)
class Solution {
private:
	//flatten the root, return the last node when root is not nullptr
	TreeNode* helper(TreeNode * root) {
		auto lc = root->left, rc = root->right;
		if(lc == nullptr && rc == nullptr)
			return root;
		if(lc) {
			root->left = nullptr;
			root->right = lc;
			if(rc == nullptr)
				rc = lc;
			else
				helper(lc)->right = rc;
		}
		return helper(rc);
	}
public:
	void flatten(TreeNode *root) {
		if(root == nullptr)
			return;
		helper(root);
	}
};