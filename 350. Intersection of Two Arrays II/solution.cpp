#include <vector>
#include <algorithm>
#include <iterator>
//using sort and library function
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        ans.reserve(std::max(nums1.size(),nums2.size()));
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(ans));
        return ans;    
    }
};


//using map
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::map<int,int> val2num;
        for(auto val:nums1)
            ++val2num[val];
        std::vector<int> ans;
        ans.reserve(std::max(nums1.size(),nums2.size()));
        for(auto val:nums2) {
            auto res = val2num.find(val);
            if(res != val2num.end()){
                ans.push_back(val);
                if(--(res->second) == 0)
                    val2num.erase(res);
            }
        }
        return ans;
    }
};