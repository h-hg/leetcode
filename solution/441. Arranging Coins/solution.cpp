#include <cmath>
//Binary Search
class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0 || n == 1)
            return n;
        for(long double_n = long(n) << 1, l = sqrt(double_n+0.25)-1.5, r = sqrt(double_n), mid, square_mid; l <= r; ){
            mid = l + (r -l) / 2;
            //judge
            square_mid = mid * mid;
            if(square_mid + mid > double_n)
                r = mid -1;
            else if(square_mid + 3 * mid + 2 <= double_n)
                l = mid + 1;
            else
                return mid;
        }
        return 0;//redundant
    }
};

//Solving Equation
class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1 + sqrt(1+8*double(n))) / 2);
    }
};