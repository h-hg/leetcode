#include <vector>
#include <set>
//force
class Solution {
private:
    std::vector<int> squares = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    inline int getNextVal(int val) //using inline to reduce the cost
	{
    	int sum = 0;
    	while(val) {
    		sum += squares[val % 10];
    		val /= 10;
    	}
    	return sum;
    }
public:
    bool isHappy(int n) {
    	std::set<int> vals;
    	while(n != 1){
    		vals.insert(n);
    		n = getNextVal(n);
    		if(vals.count(n))
    			return false;
    	}
    	return true;
    }
};