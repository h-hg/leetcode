#include <string>
#include <cstring>
class Solution {
public:
    bool canConstruct(std::string &ransomNote, std::string &magazine) {
        if(ransomNote.size() > magazine.size())
        	return false;
        int char2cnt[256];
        memset(char2cnt + int('a'), 0, sizeof(int)*26);
        for(auto c:ransomNote)
        	++char2cnt[c];
        for(auto c:magazine)
        	--char2cnt[c];
        for(auto iter = char2cnt + int('a'), end = iter + 26;iter != end;++iter)
        	if(*iter > 0)
        		return false;
        return true;
    }
};