#include <vector>
#include <string>
#include <algorithm>
#include <climits>
//using sort, time: O(nlogn)
class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::vector<int> mins(timePoints.size() + 1);
        std::transform(
        	timePoints.begin(),
            timePoints.end(),
            mins.begin(),
            [](std::string &s){
            	return (s[0]-'0')*600 + (s[1]-'0')*60 + (s[3]-'0')*10 + (s[4]-'0');
            }
       	);
       	std::sort(mins.begin(),--mins.end());
        mins.back() = mins.front() + 1440;//1440 = 60 * 24
       	for(int i = 1;i < mins.size();++i)
       		ans = std::min()
            if(mins[i] - mins[i-1] < ans)
       			ans = mins[i] - mins[i-1];
       	return ans;
    }
};