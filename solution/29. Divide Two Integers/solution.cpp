#include <climits>
/*
principle:
    a / b = sign(a/b) * ( |a| / |b| ) = sign(a/b) * e^( ln(|a|/|b|) ) = sign(a/b) * e^( ln|a| - ln|b| )
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        if((dividend < 0) ^ (divisor < 0)) 
            res = -res;
        if(res > INT_MAX)
            res = INT_MAX;
        return res;
    }
};