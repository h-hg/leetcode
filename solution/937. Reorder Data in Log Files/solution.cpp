#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    inline bool isDigistLog(std::string &str) {
   		return '0' <= str.back() && str.back() <= '9';
    }
public:
	std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
        // Put digit-logs to the end of logs, retain original order
        int letterLogCnt = logs.size();
        for(auto iter = logs.rbegin(); iter != logs.rend();++iter)
        	if(isDigistLog(*iter))
        		std::swap(*iter, logs[--letterLogCnt]);

        // sort letter digits
        std::stable_sort(
        	logs.begin(),
        	logs.begin() + letterLogCnt,
            [](const std::string& x, const std::string& y)->bool {
                int i1 = x.find(' '), i2 = y.find(' ');
                int res = x.substr(i1+1).compare(y.substr(i2+1));//compare the words after the identifier, the reason why we don't use split(' ') is int(' ') < int('a') < .. < int('z')
                return res == 0 ? x.substr(0, i1) < y.substr(0, i2) : res < 0;
            }
        );
        return logs;
    }
};