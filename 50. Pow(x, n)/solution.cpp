#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <bitset>
//log(n)
class Solution {
public:
    double myPow(double x, int n) {
    	//to judge some specifications
    	if(n == 0 || x == 1)
    		return 1;
    	if(x == -1){
    		if(n & 1) //n % 2 == 1
    			return -1;
    		else
    			return 1;
    	}
    	if(n == INT_MIN)//Here, it also satisfies x != 1 and x != -1, in order to excute n = -n
    		return 0;
    	bool negative = n < 0 ? n = -n, true : false;
    	//products = [x, x^2, x^4, ..., x^{exp}], exp = floor(log(n))
        std::vector<double> products;products.reserve(32);

        unsigned int exp = 1;
        products.push_back(x);
        for(double val = x; (exp << 1) <= n; exp <<= 1/*exp *= 2*/) {
      		val *= val;
        	products.push_back(val);
        }

        int idx = products.size() - 1;
        double ans = 1.0;
        while(n > 0)
        	if(n >= exp) {
        		ans *= products[idx];
        		n -= exp;
        	}else{
	        	--idx;
	        	exp >>= 1;//exp /= 2;
        	}

    	return negative ? 1.0 / ans : ans;
    }
};

//log(n)
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		bool flag = n > 0;
		long long N = abs((long long)n);
		std::bitset<32> b(N);
		double res = 1;
		long long i = 0, j = 1;
		while (true)
		{
			if (b.test(i))
				res *= x;
			x *= x;
			if (j > (N - j))
				break;
			j *= 2;
			++i;
		}
		if (!flag)
			res = 1 / res;
		return res;
	}
};