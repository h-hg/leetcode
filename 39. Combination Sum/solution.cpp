#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <list>
//c++ bfs
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        /*
            q = std::list(ans)
            sums[i] = q[i][0] + q[i][1] + ... + q[i][q[i].size()-1]
            index[i] is the index of q[i][q[i].size()-1] in the candidates
        */
        std::queue<std::vector<int>> q;//q is queue
        std::queue<int> last_index, sums;
        std::vector<std::vector<int>> ans;
        //init
        int border = candidates.size() - 1;//border is the last index of the value that is less or equal than target
        while(candidates[border] > target && border > 0) // for candidates[i] are positive and unique
            --border;
        //for one element
        for(int i = 0;i <= border;++i) {
            int val = candidates[i];
            if(val == target)
                ans.push_back(std::vector<int>{val});
            else {
                q.push(std::vector<int>{val});
                sums.push(val);
                last_index.push(i);
            }
        }
        //for many elements
        while(q.empty() == false) {
            auto front_vector = q.front();
            q.pop();
            auto front_sum = sums.front();
            sums.pop();
            auto front_index = last_index.front();
            last_index.pop();

            for(int i = front_index;i <= border;++i) {
                int val = candidates[i], sum = front_sum + val;
                if(sum == target) {
                    front_vector.push_back(val);
                    ans.push_back(front_vector);
                    break;//for all candidates[i] is positive and the candidates is ascendant
                }
                else if(sum < target) {
                    auto new_vector = front_vector;
                    new_vector.push_back(val);
                    q.push(new_vector);
                    sums.push(sum);
                    last_index.push(i);
                }
                else
                    break;//for all candidates[i] is positive and the candidates is ascendant
            }
        }
        //dictionary sort
        std::sort(ans.begin(),ans.end(),
            [](const std::vector<int> &a, const std::vector<int> &b){
                int n = std::min(a.size(), b.size());
                for(int i = 0;i < n;++i)
                    if(a[i] < b[i])
                        return true;
                    else if(a[i] > b[i])
                        return false;
                return a.size() <= b.size();
            }
        );
        return ans;
    }
};