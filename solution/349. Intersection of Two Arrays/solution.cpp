#include <vector>
#include <algorithm>
#include <iterator>
//using sort
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        ans.reserve(std::max(nums1.size(),nums2.size()));
        //std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(ans));
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        for(auto iter1 = nums1.begin(), iter2 = nums2.begin(); iter1 != nums1.end() && iter2 != nums2.end();) {
        	if(*iter1 < *iter2)
        		++iter1;
        	else if(*iter1 > *iter2)
        		++iter2;
        	else{
        		if(ans.size() == 0 || *iter1 != ans.back())
        			ans.push_back(*iter1);
        		++iter1;
        		++iter2;
        	}
        }
        return ans;
    }
};

//using set
#include <set>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> s1,s2;
        for(auto val:nums1)
            s1.insert(val);
        for(auto val:nums2)
            s2.insert(val);

        std::vector<int> ans;
        ans.reserve(std::max(nums1.size(),nums2.size()));
        std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(ans));
        return ans;
    }
};

//using set
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> s1,ans_set;
        for(auto val:nums1)
            s1.insert(val);
        for(auto val:nums2)
            if(s1.count(val))
                ans_set.insert(val);
        std::vector<int> ans;ans.reserve(ans_set.size());
        std::copy(ans_set.begin(), ans_set.end(), std::back_inserter(ans));
        return ans;
    }
};