class Solution {
public:
    bool isSubsequence(std::string &s, std::string &t) {
        if(s.size() > t.size())
        	return false;
        auto first1 = s.begin(), last1 = s.end(),
        	 first2 = t.begin(), last2 = t.end();
        while(first1 != last1 && first2 != last2) {
        	if(*first1 == *first2)
        		++first1;
        	++first2;
        }
        return first1 == last1;
    }
};