#include <vector>
//a solution by space O(n)
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> ans;ans.reserve(nums1.size());
       	int idx1 = 0, idx2 = 0;
       	while(idx1 < m && idx2 < n)
       		if(nums1[idx1] < nums2[idx2])
       			ans.push_back(nums1[idx1++]);
       		else
       			ans.push_back(nums2[idx2++]);
       	while(idx1 < m)
       		ans.push_back(nums1[idx1++]);
       	while(idx2 < n)
       		ans.push_back(nums2[idx2++]);
       	nums1.swap(ans);
    }
};
//space O(1)
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    	if(n == 0)
    		return;
    	int idx = m + n - 1, idx1 = m - 1, idx2 = n - 1;
       	while(idx1 >= 0 && idx2 >= 0)
       		if(nums1[idx1] > nums2[idx2])
       			nums1[idx--] = nums1[idx1--];
       		else
       			nums1[idx--] = nums2[idx2--];
       	while(idx1 >= 0)
       		nums1[idx--] = nums1[idx1--];
       	while(idx2 >= 0)
       		nums1[idx--] = nums2[idx2--];
    }
};