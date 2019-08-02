#include <iostream>
class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        while(n) 
        	if(n & 1)
        		break;
        	else
        		n >>= 1;
        return n == 1;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while( !(n & 1) )
        	n >>= 1;
        return n == 1;
    }
};
