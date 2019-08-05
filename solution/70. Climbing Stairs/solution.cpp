#include <vector>
//Brute Force - recursive
class Solution {
public:
    int climbStairs(int n)// n is stairs left to be reach
    {
    	if(n < 0)
    		return 0;
    	if(n == 0)
    		return 1;
    	return climbStairs(n-1) + climbStairs(n-2);
    }
};
//Brute Force - backtracing
class Solution {
private:
	int ans = 0;
public:
	int climbStairs(int n) {
		if(n == 0)
			return 0;
		climbStairs_backtracing(n);
		return ans;
	}
    void climbStairs_backtracing(int n)// n is stairs left to be reach
    {
    	if(n == 0)
    		++ans;
        else {
    		if(n >= 1)
    			climbStairs_backtracing(n-1);
    		if(n >= 2)
    			climbStairs_backtracing(n-2);    
        }
    }
};

//unrecrusive
/*
	ans[i] = climbStairs(i)
	climbStairs(i) = climbStairs(i-1) + climeStairs(i-2)
*/
class Solution {
public:
    int climbStairs(int n)// n is stairs left to be reach
    {
    	if(n <= 2)
    		return n;
    	int val1 = 1,val2 = 2, ans;
    	for(int i = 3;i <= n;++i) {
    		ans = val1 + val2;
    		val1 = val2;
    		val2 = ans;
    	}
    	return ans;
    }
};