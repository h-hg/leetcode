
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursive
class Solution {
private:
    std::vector<int> ans;
    void helper(TreeNode*root) {
        if(root == nullptr)
            return;
        helper(root->left);
        helper(root->right);
        ans.push_back(root->val);
    }
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};


//iterative
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        std::stack<TreeNode *> st;
        st.push(root);
        while(st.size()) {
            autp ptr = st.top();
            st.pop();
            if(ptr == nullptr)
                continue;
            
        }
    }
};