#include <string>
#include <vector>
class Solution {
public:
    int dayOfYear(std::string &date) {
    	int year = (date[0]-'0') * 1000 + (date[1]-'0') * 100 + (date[2]-'0') * 10 + (date[3]-'0'),
    	    month = (date[5]-'0') * 10 + (date[6]-'0'),
    	    day = (date[8]-'0') * 10 + (date[9]-'0');
    	std::vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    	if(year % 100 == 0 ? year % 400 == 0 : year % 4 == 0)
    		days[2] = 29;
    	int ans = 0;
    	for(int i = 1;i < month;++i)
        	ans += days[i];
        return ans + day;
    }
};