#include <vector>
class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int d = A[1] - A[0], P = 0, Q = 1, ans = 0;
        for(;Q < A.size();++Q)
        	if(A[Q] - A[Q-1] != d) {
        		int len = Q - P;
        		if(len >= 3)
					ans += (1+len-2)*(len-2)/2;
        		//update
        		P = Q-1;
        		d = A[Q] - A[Q-1];
        	}
        int len = Q-P;
        if(len >= 3)
        	ans += (1+len-2)*(len-2)/2;
        return ans;
    }
};