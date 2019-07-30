#include <algorithm>
#include <vector>
//grid[i][j] = the mininal sum from grid[0][0] to grid[row-1][col-1]
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int row = grid.size(), col = grid.front().size();
        for(int i = row - 2;i >= 0;--i)
        	grid[i].back() += grid[i+1].back();
        for(int j = col - 2; j >= 0;--j)
        	grid.back()[j] += grid.back()[j+1];
        //dp
        for(int i = row - 2;i >= 0;--i)
        	for(int j = col - 2; j >= 0;--j)
        		grid[i][j] += std::min(grid[i][j+1],grid[i+1][j]);
       	return grid[0][0];
    }
};

//grid[i][j] = the mininal sum from grid[row-1][col-1] to  grid[0][0]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (auto i = 0 ; i < grid.size(); i++) {
            for (auto j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0)
                    continue;

                int a = j > 0 ? grid[i][j] + grid[i][j - 1] : INT_MAX;
                int b = i > 0 ? grid[i][j] + grid[i - 1][j] : INT_MAX;
                grid[i][j] = min(a, b);
            }
        }
        return grid.back().back();
    }
};