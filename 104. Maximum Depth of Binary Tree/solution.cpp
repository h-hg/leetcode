
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//iterator (dfs)
#include <algorithm>
class Solution {
private:
	int ans = 0;
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        	return 0;
        return std::max( maxDepth(root->left), maxDepth(root->right) ) + 1;
    }
};
//bfs
#include <queue>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        	return 0;
        int ans = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
        	int n = q.size();
        	for(int i = 0;i < n;++i) {
        		auto ptr = q.front();
        		if(ptr->left != nullptr)
        			q.push(ptr->left);
        		if(ptr->right != nullptr)
        			q.push(ptr->right);
        	}
        	++ans;
        }
        return ans;
    }
};
//dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        	return 0;
    }
};

//dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        	return 0;
    }
    void dfs(TreeNode *p, int &leverl)
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        dfs(ans, root, 0);
        return ans;
    }
    
    void dfs(std::vector<std::vector<int>>& ans, TreeNode* root, int level){
        if(!root)
        	return;
        if(level == ans.size())
        	ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        dfs(ans, root->left, level + 1);
        dfs(ans, root->right, level + 1);
    }
};