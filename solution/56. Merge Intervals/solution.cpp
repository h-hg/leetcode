class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if(intervals.empty())
            return std::vector<std::vector<int>> ();
        //sort intervals
        std::sort(
            intervals.begin(),
            intervals.end(),
            [](const std::vector<int> &x, const std::vector<int> &y)->bool{
                return x.front() < y.front();
            }
        );
        //merge
        std::vector<std::vector<int>> ans;
        ans.push_back(intervals.front());
        for(auto &interval:intervals) {
            int end = ans.back().back();
            if(end < interval.front())
                ans.push_back(interval);
            else if(end < interval.back())
                ans.back().back() = interval.back();
        }
        return ans;
    }
};