#include <vector>
class Solution {
private:
    inline void writeCnt(std::vector<char>::writeator &write, int cnt){
        auto str = std::to_string(cnt);
        for(auto c:str)
            *write++ = c;
    }
public:
    int compress(std::vector<char>& chars) {
        if(chars.empty() || chars.size() == 1)
            return chars.size();
        char lastChar = chars.front();
        auto write = ++chars.begin();
        int cnt = 1;//count of repeating characters
        for(auto read = write, last = chars.end(); read != last; ++read) {
            if(*read == lastChar)
                ++cnt;
            else {
                if(cnt != 1)
                    writeCnt(write, cnt);
                cnt = 1;
                *write++ = lastChar = *read;//write the char and update lastChar
            }
        }
        if(cnt != 1)
            writeCnt(write, cnt);
        return write - chars.begin();
    }
};