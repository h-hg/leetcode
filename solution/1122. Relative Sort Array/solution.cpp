#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::sort(
            arr1.begin(),
            arr1.end(),
            [&](const int a, const int b) -> bool{
                auto it_a = find(arr2.begin(), arr2.end(), a);
                auto it_b = find(arr2.begin(), arr2.end(), b);
                if (it_a == arr2.end() && it_b == arr2.end())
                    return a < b;
                return std::distance(it_a, it_b) > 0;
        });
        return arr1;
    }
};