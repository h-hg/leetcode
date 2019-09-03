#include <string>
#include <vector>
class Solution {
public:
    bool buddyStrings(std::string &A, std::string &B) {
        if(A.size() != B.size())
        	return false;
        std::vector<int> idxes, cnts(26,0);
        for(int i = 0;i < A.size(); ++i) {
        	++cnts[A[i] - 'a'];
        	if(A[i] != B[i]) {
        		idxes.push_back(i);
        		if(idxes.size() > 2)
        			return false;
        	}
        }
        switch(idxes.size()) {
        case 0:
        	for(auto cnt:cnts)
        		if(cnt >= 2)//swap two same char
        			return true;
        	return false;
        case 1:
        	return true;
        case 2:
        	return A[idxes.front()] == B[idxes.back()] && A[idxes.back()] == B[idxes.front()];
        default:
            return false;
        }
    }
};