#include <string>
#include <map>
#include <queue>
#include <iostream>

//greedy, time:O(nlogn)
class Solution {
private:
	class cmp{
	public:
		inline bool operator()(const std::pair<char,int> &x, const std::pair<char,int> &y) {
			return x.second < y.second;
		}
	};
public:
    std::string reorganizeString(std::string &S) {
    	std::map<char,int> val2cnt;
    	for(auto c:S)
    		++val2cnt[c];
    	std::priority_queue<
    		std::pair<char,int>,
    		std::vector<std::pair<char,int>>,
    		cmp
    	> q(val2cnt.begin(), val2cnt.end());

    	std::string ans;
    	ans.reserve(S.size());
    	while(q.size() >= 2) {
    		auto val1 = q.top();//the char with the largest count
    		q.pop();
    		auto val2 = q.top();//the char with the second count
    		q.pop();
    		//append
    		for(int i = 0;i < val2.second;++i) {
    			ans.push_back(val1.first);
    			ans.push_back(val2.first);
    		}

    		if( (val1.second -= val2.second) > 0)
    			q.push(val1);
    	}
        if( q.empty() )
        	return ans;
        else if(q.top().second == 1) {
        	ans.push_back(q.top().first);
        	return ans;
        } else
    		return "";
    }
};