class Solution {
public:
    bool isIsomorphic(const std::string &s,const std::string &t) {
		if(s.size() != t.size())
			return false;
		std::vector<char> s2t(128, '\0'),//mapping from char in s to char in t
						  t2s(128, '\0');//mapping from char in t to char in s
		auto first1 = s.begin(), last1 = s.end(), first2 = t.begin();
		while(first1 != last1) {
			if(s2t[*first1] == '\0' && t2s[*first2] == '\0') {
				s2t[*first1] = *first2;
				t2s[*first2] = *first1;
			}
			if(s2t[*first1] != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
    }
};