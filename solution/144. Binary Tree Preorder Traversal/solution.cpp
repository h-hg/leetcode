/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive 
class Solution {
private:
	std::vector<int> ans;
	void helper(TreeNode *root) {
		if(root == nullptr)
			return;
		ans.push_back(root->val);
		helper(root->left);
		helper(root->right);
	}
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};

//iteratively
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
    	std::vector<int> ans;
    	std::stack<TreeNode *> st;
    	st.push(root);
    	while(st.size()) {
    		auto ptr = st.top();
    		st.pop();
    		if(ptr == nullptr)
    			continue;
    		ans.push_back(ptr->val);
    		st.push(ptr->right);
    		st.push(ptr->left);
    	}
    	return ans;
    }
};