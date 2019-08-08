#include <vector>
#include <string>

class Solution {
private:
	inline void getCnt(std::string &str, std::vector<int> &val2cnt)
	{
		for(auto c:str)
			++val2cnt[c-'a'];
	}
	inline void mergeCnt(std::vector<int> &c1, std::vector<int> &c2)//c1 <- c2
	{
		for(int i = 0;i < 26;++i)
			if(c1[i] > c2[i])
				c1[i] = c2[i];
	}
public:
    std::vector<std::string> commonChars(std::vector<std::string>& A) {
        std::vector<std::string> ans;
        if(A.empty())
        	return ans;
        std::vector<int> val2cnt(26, 0), tmp(26,0);
        getCnt(A[0], val2cnt);
        for(int i = 1;i < A.size();++i){
        	tmp.assign(26, 0);
        	getCnt(A[i], tmp);
        	mergeCnt(val2cnt, tmp);
        }
        for(int i = 0; i < 26; ++i)
        	for(int j = 0;j < val2cnt[i];++j)
        		ans.push_back(std::string(1,'a' + i));
        return ans;
    }
};