#include <vector>
class Solution {
public:
    int repeatedNTimes(std::vector<int>& A) {
        for(int i = 2;i < A.size();++i)
        	if(A[i] == A[i-1] || A[i] == A[i-2])
        		return A[i];
        return A.front();
    }
};