//using sum
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::set<int> s;
        long smallsum = 0, bigsum = 0;
        for(auto val:nums) {
            s.insert(val);
            smallsum += val;
        }
        for(auto val:s)
        	bigsum += val;
        return (3 * bigsum - smallsum) / 2;
    }
};

//count
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