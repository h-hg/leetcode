#include <vector>

//two pass - count
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::map<int,int> val2cnt;
        for(auto val:nums)
            ++val2cnt[val];
        for(auto &p:val2cnt)
            if(p.second == 1)
                return p.first;
        return 0;//redundant
    }
};


//one and half pass - use sum and set
//c = 2 * (a + b + c) - (a + a + b + b + c)
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::set<int> s;
        int smallsum = 0, bigsum = 0;
        for(auto val:nums) {
            s.insert(val);
            smallsum += val;
        }
        for(auto val:s)
        	bigsum += val;
        return 2 * bigsum - smallsum;
    }
};


//one pass - use bit
//a ^ a ^ b ^ b ^ c = (a ^ a) ^ (b ^ b) ^ c = 0 ^ 0 ^ c = c
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
    	int ans = 0;
    	for(auto val:nums)
    		ans ^= val;
    	return ans;
    }
};