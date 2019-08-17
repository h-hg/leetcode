class Solution {
public:
    int longestPalindrome(std::string &s) {
        std::map<int,int> val2cnt;
        for(auto c:s)
            ++val2cnt[c];
        int ans = 0;
        bool flag = false;
        for(auto &p:val2cnt)
            if(p.second & 1){
                flag = true;
                ans += p.second -1;
            }
            else
                ans += p.second;
        return flag ? ans + 1 : ans;       
    }
};