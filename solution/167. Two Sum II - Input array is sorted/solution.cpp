class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = numbers.size() - 1;
        for(int sum = numbers[idx1] + numbers[idx2]; sum != target; sum = numbers[idx1] + numbers[idx2])
        	if(sum < target)
        		++idx1;
        	else
        		--idx2;
        return std::vector<int>{idx1+1, idx2+1};
    }
};