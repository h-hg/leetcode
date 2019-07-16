#include <string>
class Solution {
public:
    int romanToInt(std::string &s) {
    	int ans = 0;
    	int n = s.size() - 1;
    	for(int i = 0;i < n;++i) {
    		switch(s[i]) {
	    	case 'I':
	    		if(s[i+1] == 'V' || s[i+1] == 'X')
	    			ans -= 1;
	    		else
	    			ans += 1;
	    		break;
	    	case 'V':
	    		ans += 5;
	    		break;
	    	case 'X':
	    		if(s[i+1] == 'L' || s[i+1] == 'C')
	    			ans -= 10;
	    		else
	    			ans += 10;
	    		break;
	    	case 'L':
	    		ans += 50;
	    		break;
	    	case 'C':
	    		if(s[i+1] == 'D' || s[i+1] == 'M')
	    			ans -= 100;
	    		else
	    			ans += 100;
	    		break;
	    	case 'D':
    			ans += 500;
    			break;
	    	case 'M':
	    		ans += 1000;
	    		break;
	    	}
    	}
    	switch(s[n]){
    	case 'I':
    		ans += 1;
    		break;
    	case 'V':
    		ans += 5;
    		break;
    	case 'X':
    		ans += 10;
    		break;
    	case 'L':
    		ans += 50;
    		break;
    	case 'C':
    		ans += 100;
    		break;
    	case 'D':
    		ans += 500;
    		break;
    	case 'M':
    		ans += 1000;
    		break;
    	}
        return ans;
    }
};
#include <vector>
#include <iostream>
int main()
{
	Solution solution;
	std::vector<std::string> v ={"III", "IV", "IX", "LVIII", "MCMXCIV"};
	for(int i = 0;i < v.size();++i)
		std::cout << i << ". " << v[i] << ": " << solution.romanToInt(v[i]) << std::endl;
	return 0;
}