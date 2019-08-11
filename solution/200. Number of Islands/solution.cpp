#include <vector>
#define TAG  '\0' //the position you have ran
#define LAND '1'
class Solution {
private:
	int row = 0, col = 0;
	void dfs(std::vector<std::vector<char>>& grid, int i, int j){
		if(i < 0 || row <= i || j < 0 || col <= j || grid[i][j] !=  LAND)
			return;
		grid[i][j] = TAG;
		dfs(grid,i - 1, j);
		dfs(grid,i + 1, j);
		dfs(grid,i, j - 1);
		dfs(grid,i, j + 1);
	}
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
		row = grid.size();
        if(row == 0)
            return 0;
		col = grid.front().size();
		int ans = 0;
		for(int i = 0;i < row; ++i) 
			for(int j = 0; j < col; ++j)
				if(grid[i][j] == LAND){
					++ans;
					dfs(grid, i, j);
				}
		return ans;
    }
};