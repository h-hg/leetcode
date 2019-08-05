#include <string>
#include <algorithm>
class Solution {
public:
    bool isAnagram(std::string &s, std::string &t) {
    	std::sort(s.begin(), s.end());
    	std::sort(t.begin(), t.end());
    	return s == t;
    }
};

//count
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() )
        	return false;
        std::vector<int> freq( 26, 0 );
        for( auto c : s ) {
            ++freq[ c - 'a' ];
        }
        for( auto c : t ) {
            --freq[ c - 'a' ];
            if( freq[ c - 'a'] < 0 )
            	return false;
        }
        return true;
    }
};