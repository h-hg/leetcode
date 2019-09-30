/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> ans;
        if(root == nullptr)
            return ans;
        std::queue<Node*> q;
        q.push(root);

        while(q.size()) {
            int n = q.size();
            ans.push_back(std::vector<int>{});
            ans.back().reserve(n);
            for(int i = 0;i < n;++i) {
                auto & front = *q.front();
                q.pop();
                ans.back().push_back(front.val);
                for(auto child:front.children)
                    q.push(child);
            }
        }
        return ans;
    }
};