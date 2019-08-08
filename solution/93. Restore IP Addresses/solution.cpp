#include <string>
#include <vector>
class Solution {
    inline bool isVaid(int val){
        return val <= 255;
    }
    void dfs(std::string::iterator iter, std::string::iterator last, std::string &cur, int endval, int pointnum, std::vector<std::string> &ans)
    {
    	if(pointnum > 3 || isVaid(endval) == false)
    		return;
        if(iter == last) {
            if(pointnum == 3)
                ans.push_back(cur);
            return;
        }

        char c = *iter++;
        int val = c - '0';
        
        cur.push_back('.');
        cur.push_back(c);
        dfs(iter, last, cur, val, pointnum+1, ans);
        cur.pop_back();
        cur.pop_back();
        if(endval == 0)
        	return;
        int new_endval = endval * 10 + val;
        cur.push_back(c);
        dfs(iter, last, cur, new_endval, pointnum, ans);
        cur.pop_back();//remember this, for a segment may have three number
        
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string &s) {
        //init
        std::vector<std::string> ans;
        if(s.size() < 4)
        	return ans;
        std::string cur;
        cur.reserve(s.size() + 4);
        cur.push_back(s[0]);
        //dfs
        dfs(s.begin()+1, s.end(), cur, s[0] - '0', 0, ans);

        return ans;
    }
};