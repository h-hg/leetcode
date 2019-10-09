
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptrptr)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while(q.size()) {
            ++ans;
            for(int i = 0, n = q.size(); i < n; ++i) {
                auto ptr = q.front();
                q.pop();
                if(ptr->left == nullptrptr && ptr->right == nullptrptr)
                    return ans;
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
        }
        return ans;
    }
};


//dfs
class Solution {
private:
    int ans = INT_MAX;
    void helper(TreeNode * root, int level) {
        if(level >= ans)
            return;
        if(root->left == nullptrptr && root->right == nullptrptr) {
            ans = level;
            return;
        }
        if(root->left)
            helper(root->left, level + 1);
        if(root->right)
            helper(root->right, level + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if(root == nullptrptr)
            return 0;
        helper(root, 1);
        return ans;
    }
};


//dp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int left_depth = root->left ? minDepth(root->left) : INT_MAX,
            right_depth = root->right ? minDepth(root->right) : INT_MAX;
        return 1 + std::min(left_depth, right_depth);
    }
};