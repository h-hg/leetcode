#include <vector>
#include <algorithm>

#define RED 0
#define WHITE 1
#define BLUE 2

//count and set, two pass
class Solution {
public:
	void sortColors(std::vector<int> &nums) {
		int colors[] = {0, 0, 0};
		for(auto val:nums)
			++colors[val];
		colors[1] += colors[0];
		colors[2] += colors[1];
		for(int i = 0;i < colors[0];++i)
			nums[i] = RED;
		for(int i = colors[0]; i < colors[1]; ++i)
			nums[i] = WHITE;
		for(int i = colors[1]; i < colors[2];++i)
			nums[i] = BLUE;
	}
};
//distribution counting - two pass
class Solution{
public:
	void sortColors(std::vector<int>&nums) {
		int colors[] = {0,0,0};
		for(auto val:nums)
			++colors[val];
		colors[1] += colors[0];
		colors[2] += colors[1];
        auto tmp = nums;
		for(auto val:tmp)
			nums[--colors[val]] = val;	
	}
};
//one pass - make sure that the number of RED and BLUE
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
    	int idx_red = -1, idx_blue = nums.size();
    	//fill the red and blue, idx_red < idx_white < idx_blue
    	for(int idx_white = 0; idx_white < idx_blue;){
    		if(nums[idx_white] == RED){
                if(idx_white != ++idx_red)//make sure that idx_red < idx_white
                    std::swap(nums[idx_white], nums[idx_red]);
                else
                    ++idx_white;
            } else if(nums[idx_white] == BLUE)
    			std::swap(nums[idx_white], nums[--idx_blue]);
    		else 
    			++idx_white;
        }
    }
};