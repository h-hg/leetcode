//leetcode's solution
class Solution {
private:
	static inline bool find(const std::string &S, int idx, const std::string &src){
		if(idx + src.size() > S.size())
			return false;
		for(auto c:src)
			if(c != S[idx++])
				return false;
		return true;
	}

public:
   std::string findReplaceString(std::string &S, std::vector<int>& indexes, std::vector<std::string>& sources, std::vector<std::string>& targets) {
    	std::vector<int> match(S.size(), -1);//-1 represent unfound
        for(int i = 0; i < indexes.size(); ++i)
        	if(find(S, indexes[i], sources[i]))
        		match[indexes[i]] = i;
        std::string ans;
        for(int i = 0;i < S.size();) {
        	if(match[i] != -1) {
        		ans += targets[match[i]];
        		i += sources[match[i]].size();
        	} else
        		ans.push_back(S[i++]);
        }
        return ans;
    }
};