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
    //lower, upper is the pointers that point to the bound
    bool helper(TreeNode *root, TreeNode *lower, TreeNode *upper) {
        if(root == nullptr)
            return true;
        int val = root->val;
        if( (lower && val <= lower->val) || (upper && upper->val <= val) )
            return false;
        return helper(root->left, lower, root) && helper(root->right, root, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
};