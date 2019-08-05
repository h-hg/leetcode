#include <vector>
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        
        int sum = 1;
        auto iter = digits.rbegin();
        for(;sum != 0 && iter != digits.rend(); ++iter) {
        	sum += *iter;
        	*iter = sum % 10;
        	sum /= 10;
        }
        if(sum != 0)
        	digits.insert(digits.begin(),1);
        return digits;
    }
};