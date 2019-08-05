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

//using map, easy to read
class Solution {
public:
    int romanToInt(std::string &s) {
        if(s.empty())
            return 0;
        //std::map<char,int> char2val= {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int char2val[256];
        char2val['I'] = 1;
        char2val['V'] = 5;
        char2val['X'] = 10;
        char2val['L'] = 50;
        char2val['C'] = 100;
        char2val['D'] = 500;
        char2val['M'] = 1000;
        int ans = char2val[s[0]];
        for(int i = 1; i < s.size(); ++i)
        {
            ans += char2val[s[i]];
            if( char2val[s[i-1]] < char2val[s[i]])
                ans -= 2 * char2val[s[i-1]];
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