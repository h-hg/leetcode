/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr)
            return q == p;
        if(p->val != q->val)
            return false;
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};


//method 2: iterator in leetcode's solution
#include <queue>
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(q.empty() == false){
            auto p1 = q.front();
            q.pop();
            auto p2 = q.front();
            q.pop();
            if(p1 == nullptr && p2 == nullptr)
                continue;
            if(p1 == nullptr || p2 == nullptr)
                return false;
            if(p1->val != p2->val)
                return false;
            q.push(p1->left);
            q.push(p2->right);
            q.push(p1->right);
            q.push(p2->left);
        }
        return true;
    }
};

//method 3： optimization of method 2
/*
    In method 2, every node is checked twice, reduce this to once.
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(q.empty() == false){
            auto p1 = q.front();
            q.pop();
            auto p2 = q.front();
            q.pop();
            if(p1 == nullptr && p2 == nullptr)
                continue;
            if(p1 == nullptr || p2 == nullptr)
                return false;
            if(p1->val != p2->val)
                return false;
            q.push(p1->left);
            q.push(p2->right);
            q.push(p1->right);
            q.push(p2->left);
        }
        return true;
    }
};