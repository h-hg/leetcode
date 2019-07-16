#include <string>
#include <climits>
#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        	return false;
        int tmp = x;
        long reverse = 0;
        while(tmp){
        	reverse = reverse * 10 + tmp % 10;
        	tmp /= 10;
        }
        return reverse == long(x);
    }
};