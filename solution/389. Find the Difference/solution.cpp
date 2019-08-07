#include <vector>
#include <string>
class Solution {
public:
    char findTheDifference(std::string &s, std::string &t) {
        int val2cnt['z'+1];
        memset(val2cnt, 0, sizeof(val2cnt));
        //std::vector<int> val2cnt('z'+1,0);
        for(auto c:s)
            ++val2cnt[c];
        for(auto c:t)
            if(--val2cnt[c] < 0)
                return c;
        return 0;//unused
    }
};