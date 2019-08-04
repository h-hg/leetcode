#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if(numRows == 0)
            return std::vector<std::vector<int>>();
        std::vector<std::vector<int>> ans;
        ans.reserve(numRows);
        std::vector<int> cur = {1};
        cur.reserve(numRows);
        ans.push_back(std::vector<int>{1});
        for(int i = 1;i < numRows;++i){
            cur.clear();
            cur.push_back(1);
            auto &v = ans.back();
            for(int j = 1;j < i;++j)
                cur.push_back(v[j-1] + v[j]);
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};