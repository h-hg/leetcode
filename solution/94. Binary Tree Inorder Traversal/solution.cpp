/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
class Solution {
private:
	void helper(TreeNode *root, std::vector<int> &ans) {
		if(root == nullptr)
			return;
		helper(root->left, ans);
		ans.push_back(root->val);
		helper(root->right, ans);
	}
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

//iterator using stack
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
    	std::vector<int> ans;
    	std::stack<TreeNode*> st;
    	auto cur = root;
    	while(cur || st.size())
    		if(cur != nullptr) {
    			st.push(cur);
    			cur = cur->left;//visit the left
    		} else {
    			cur = st.top();//get the last node visited
                st.pop();
    			ans.push_back(cur->val);//visit the iterself
    			cur = cur -> right;//visit the right
    		}
    	return ans;
    }
};