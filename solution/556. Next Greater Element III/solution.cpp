class Solution {
public:
    int nextGreaterElement(int n) {
        auto strn = std::to_string(n);
        if(std::next_permutation(strn.begin(), strn.end()) == false)
        	return -1;
        long ans = std::stol(strn);
        return ans > INT_MAX ? -1 : ans;
    }
};