#include <vector>
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> ans(rowIndex+1);
        ans[0] = 1;//first position
        for(int i = 1;i <= rowIndex;++i) {
            //calculating from end to begin
        	ans[i] = 1;//last position
        	for(int j = i - 1; j > 0;--j)
        		ans[j] += ans[j-1];
        }
        return  ans;
    }
};