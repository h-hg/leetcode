//91. Time Limit Exceeded
#include <string>
class Solution {
private:
    int ans = 0;
    inline bool isVaild(int val)
    {
        return 0 < val && val <= 26;
    }
    void dfs(std::string::iterator iter, std::string::iterator last, int endval)
    {
        if(isVaild(endval) == false)
            return;
        if(iter == last) {
            ++ans;
            return;
        }

        int val = *iter++ - '0';
        //single
        dfs(iter, last, val);
        //combine
        dfs(iter, last, endval * 10 + val);

    }    
public:
    int numDecodings(std::string &s) {
        if(s.empty())
            return 0;
        dfs(++s.begin(), s.end(), s[0] - '0');
        return ans;
    }
};

class Solution
{
private:
    inline bool isVaild(int val)
    {
        return 0 < val && val <= 26;
    }
public:
    int numDecodings(std::string &s) {
        if(s.empty())
            return 0;
        std::string::iterator iter = ++s.begin(), last = s.end();
        int ans = 0, endval = s[0] - '0';
        while(1){
            if(isVaild(endval) == false)
                continue;
            if(iter == last) {
                ++ans;
                continue;
            }
            int val = *iter++ - '0';
            
        }        
    }    
};