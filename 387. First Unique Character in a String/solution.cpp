class Solution {
public:
    int firstUniqChar(std::string s) {
       int char2cnt[256];
        memset(char2cnt + int('a'), 0, sizeof(int)*26);
        for(auto c:s)
            ++char2cnt[c];
        for(auto iter = s.begin();iter != s.end(); ++iter)
            if(char2cnt[*iter] == 1)
                return iter - s.begin();
        return -1;
    }
};