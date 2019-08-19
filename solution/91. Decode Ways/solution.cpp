#include <string>

//dfs: timeout
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

//bfs, ans[i] = endval(ans[i-1]) + s.back() : timeout
class Solution {
public:
    int numDecodings(std::string &s){
        if(s.empty() || s.front() == '0')
            return 0;
        std::queue<int> endvals;
        endvals.push(s.front()-'0');
        for(auto iter = ++s.begin(), last = s.end(); iter != last; ++iter){
            int val = *iter - '0', n = endvals.size();
            for(int i = 0;i < n;++i) {
                int newVal = endvals.front() * 10 + val;
                endvals.pop();
                //combine
                if(newVal <= 26)
                    endvals.push(newVal);
                //single
                if(val != 0)
                    endvals.push(val);
            }
        }
        return endvals.size();
    }
};


class Solution {
public:
    int numDecodings(std::string &s){
        if(s.empty() || s.front() == '0')
            return 0;
        int lastVal = s.front() - '0',
            endValCnts[2] = {1,0},//endValCnts[0]: count of 1-bit number (eg. 1), endValCnts[1]: count of 2-bit number(eg. 12)
            newEndValCnts[2];
        for(int i = 1;i < s.size();++i){
            int val = s[i] - '0';
            //single
            newEndValCnts[0] = val != 0 ? endValCnts[0] + endValCnts[1] : 0;
            //combine
            newEndValCnts[1] = (lastVal != 0 && lastVal * 10 + val <= 26) ? endValCnts[0] : 0;
            //update
            lastVal = val;
            std::swap(endValCnts, newEndValCnts);
        }
        return endValCnts[0] + endValCnts[1];
    }
};