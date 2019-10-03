#include <vector>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
	TreeNode* helper(int l, int r, std::vector<int> &nums) {
		if(!(l <= r))
			return nullptr;
		int mid = (l+r) >> 1;
		auto ret = new TreeNode(nums[mid]);
		ret->left = helper(l, mid - 1, nums);
		ret->right = helper(mid + 1, r, nums);
		return ret;
	}
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};