#include <iostream>
#include <string>
#include <algorithm>
class Solution {
public:
    std::string intToRoman(int num) {
    	std::string ans;
    	char symbols[] = {'I','V','X','L','C','D','M'};
    	char *table = symbols;
    	//represent in reversed Roman number
    	while(num){
    		int tmp = num % 10;
    		num /= 10;
    		switch(tmp){
    		case 3:
    			ans += table[0];
    		case 2:
    			ans += table[0];
    		case 1:
    			ans += table[0];
    			break;
    		case 4:
    			ans += table[1];
    			ans += table[0];
    			break;
    		case 8:
    			ans += table[0];
    		case 7:
    			ans += table[0];
    		case 6:
    			ans += table[0];
    		case 5:
    			ans += table[1];
    			break;
    		case 9:
    			ans += table[2];
    			ans += table[0];
    			break;
    		}
    		table += 2;
    	}
    	//reverse the roman number
    	std::reverse(ans.begin(),ans.end());
    	return ans;
    }
};