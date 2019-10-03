
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//bfs
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if(root == nullptr)
			return false;
		std::queue<TreeNode*> q;
		q.push(root);
		std::queue<int> sums;
		sums.push(0);
		while(q.size())
			for(int i = 0,n = sums.size();i < n;++i) {
				auto ptr = q.front();
				q.pop();
				int _sum = sums.front() + ptr->val;
				sums.pop();
				if(ptr->left == nullptr && ptr->right == nullptr) {
					if(_sum == sum)
						return true;
					continue;
				}
				if(ptr->left) {
					q.push(ptr->left);
					sums.push(_sum);
				}
				if(ptr->right) {
					q.push(ptr->right);
					sums.push(_sum);
				}
			}
		return false;
    }
};

//dfs
class Solution {
private:
	bool helper(TreeNode *root, int target) {
		target -= root->val;
		if(root->left == nullptr && root->right == nullptr)
			return target == 0;
		else if(root->left == nullptr)
			return helper(root->right, target);
		else if(root->right == nullptr)
			return helper(root->left, target);
		else
			return helper(root->left, target) || helper(root->right, target);
	}
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root == nullptr)
    		return false;
    	return helper(root, sum);
    }
};