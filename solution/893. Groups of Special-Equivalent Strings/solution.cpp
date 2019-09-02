//count
class Solution {
public:
    int numSpecialEquivGroups(std::vector<std::string>& A) {
    	std::vector<int> cnt(52,0);//[0.26) is the counts of even index letter, [26, 52) is the counts of old index letter
    	std::set<std::vector<int>> s;
    	for(auto &str : A) {
    		cnt.assign(52,0);
    		for(int i = 0;i < str.size(); ++i)
    			++cnt[str[i] - 'a' + (i&1) * 26];
    		s.insert(cnt);
    	}
    	return s.size();
    }
};

//using sort
class Solution {
public:
    int numSpecialEquivGroups(std::vector<std::string>& A) {
    	std::set<std::string> s;
    	std::string odds(500, '\0'), evens(500,'\0');
    	for(auto &str : A) {
    		odds.clear();
    		evens.clear();
    		for(int i = 0;i < str.size(); ++i)
    			(i & 1 ? odds : evens).push_back(str[i]);
    		std::sort(odds.begin(), odds.end());
    		std::sort(evens.begin(), evens.end());
    		s.insert(odds + evens);
    	}
    	return s.size();
    }
};
