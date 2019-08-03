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
//one pass - make sure that the number of RED and BLUE
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
    	int idx_red = -1, idx_blue = nums.size();
    	//fill the red and blue, idx_red < i < idx_blue
    	for(int i = 0; i < idx_blue;){
    		if(nums[i] == RED){
                if(i != ++idx_red)//make sure that idx_red < i
                    std::swap(nums[i], nums[idx_red]);
                else
                    ++i;
            } else if(nums[i] == BLUE)
    			std::swap(nums[i], nums[--idx_blue]);
    		else 
    			++i;
        }
    	//fill the white
    	for(int idx_white = idx_red + 1;idx_white < idx_blue;++idx_white)
    		nums[idx_white] = WHITE;
    }
};