//time: O(n), space: O(n)
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std:vector<bool> states(nums.size()+1, false);
        for(auto num:nums)
            states[num] = true;
        std::vector<int> ans;
        for(int i = 1;i < states.size();++i)
            if(states[i] == false)
                ans.push_back(i);
        //std::sort(nums.begin(), nums.end());
        return ans;
    }
};

//time: O(n), space: O(1)
/*
    nums[i] > 0 means that number i+1 is missing
*/

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums ) {
        for(auto val:nums)
            if(nums[abs(val)-1] > 0)//>0: mean the state of number val hasn't been setted
                nums[abs(val)-1] *= -1;
        std::vector<int> ans;
        for( int i=0; i < nums.size(); ++i )
            if( nums[i] > 0 )
                ans.push_back( i + 1 );
        return ans;
    }
};

//sort
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums ) {
        std::sort(nums.begin(),nums.end());
        std::vector<int> ans;
        auto iter = nums.begin();
        for(int i = 1;i <= nums.size(); ++i){
            if(iter != nums.end() && i == *iter) {
                do{
                    ++iter;
                }while(iter != nums.end() && *iter == i);
            }else
                ans.push_back(i);
        }
        return ans;
    }
};