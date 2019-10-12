
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//dfs
class Solution {
private:
	std::vector<int> ans;
	int maxLevel = 0;
	void helper(TreeNode *root, int level) {
		if(root == nullptr)
			return;
		if( level >= maxLevel) {
			ans.push_back(root->val);
			maxLevel = level + 1;
		}
		helper(root->right, level + 1);
		helper(root->left, level + 1);

	}
public:
    std::vector<int> rightSideView(TreeNode* root) {
		helper(root, 0);
		return ans;        
    }
};


//bfs
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
		std::vector<int> ans;
		if(root == nullptr)
			return ans;
		std::queue<TreeNode*> q;
		q.push(root);
		while(q.size()) {
			ans.push_back(q.back()->val);
			for(int i = 0, n = q.size();i < n; ++i) {
				auto ptr = q.front();
				q.pop();
				if(ptr->left)
					q.push(ptr->left);
				if(ptr->right)
					q.push(ptr->right);
			}
		}	
		return ans;        
    }
};