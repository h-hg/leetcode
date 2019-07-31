//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//method 1
#include <vector>
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1);

    }
    TreeNode* buildTree(std::vector<int> &preorder,int pre_l, int pre_r, std::vector<int> &inorder, int in_l, int in_r) {
    	if(pre_l > pre_r)
    		return nullptr;
    	int val = preorder[pre_l];
    	TreeNode *root = new TreeNode(val);
    	int root_idx = in_l;//root_idx is index of root in the inorder
    	while(root_idx <= in_r && inorder[root_idx] != val)
    		++root_idx;
    	//if(root_idx > in_r) throw error;
    	int leftNodes = root_idx - in_l;
    	root->left = buildTree(preorder, pre_l+1, pre_l+leftNodes, inorder, in_l, root_idx-1);
    	root->right = buildTree(preorder, pre_l+1+leftNodes, pre_r, inorder, root_idx+1, in_r);
    	return root;
    }
};

//methdd 2: simplify method 1, use root_idx to replace pre_l and pre_r, at the same the time, use map to speed up finding
#include <map>
class Solution {
private:
    std::map<int,int> val2pos;

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if(preorder.size() == 0)
            return nullptr;
    	for(int i = 0;i < inorder.size();++i)
    		val2pos[inorder[i]] = i;
        return buildTree(preorder, 0, inorder, 0, inorder.size()-1);

    }
    TreeNode* buildTree(std::vector<int> &preorder, int root_idx, std::vector<int> &inorder, int in_l, int in_r)//root_idx is index of root in the preorder
    {
    	if(in_l > in_r)
    		return nullptr;
    	int val = preorder[root_idx];
    	TreeNode *root = new TreeNode(val);
    	int idx = val2pos[val],
    		leftNodes = idx - in_l;
    	root->left = buildTree(preorder,root_idx+1, inorder, in_l, idx - 1);
    	root->right = buildTree(preorder, root_idx+1+leftNodes, inorder, idx + 1, in_r);
        return root;
    }
};