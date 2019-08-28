/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//dsf
class Solution {
private:
	std::map<Node*, Node*> old2new;
	Node* dfs(Node *node){
		//whether existing
		auto res = old2new.find(node);
		if(res != old2new.end())
			return res->second;
		//construct a new node
		auto ret = new Node(node->val,std::vector<Node*> ());
		old2new[node] = ret;//establish mapping, it also means that you have visited this node
		//construct the neighbots
		(ret->neighbors).reserve( (node->neighbors).size() );
		for(auto neighbor:node->neighbors)
			(ret->neighbors).push_back(dfs(neighbor));
		return ret;
	}
public:
    Node* cloneGraph(Node* node) {
    	//init the map
    	old2new[nullptr] = nullptr;
    	return dfs(node);
    }
};