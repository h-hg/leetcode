#include <vector>
#include <algorithm>
//bfs
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if(root == nullptr)
            return ans;
        //init
        std::queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            int n = q.size();
            ans.push_back(std::vector<int>());//push an empty vector
            auto &v = ans.back();
            v.reserve(n);
            for(int i = 0; i < n;++i){
                auto ptr = q.front();
                q.pop();
                v.push_back(ptr->val);
                if(ptr->left != nullptr)
                    q.push(ptr->left);
                if(ptr->right != nullptr)
                    q.push(ptr->right);
            }
            
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

//dfs
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        dfs(ans, root, 0);
        std::reverse(ans.begin(), ans.end());
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