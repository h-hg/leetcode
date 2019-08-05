#include <vector>
#include <iostream>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<int> grid_states(9,0);
        /*
		0 1 2
		3 4 5
		6 7 8
        */
        for(int i = 0; i < 9; ++i) {
        	int row_states = 0, col_states = 0;
        	for(int j = 0; j < 9; ++j) {
        		//row
        		int row_num = board[i][j] - '0';
        		if(0 <= row_num && row_num <= 9) {
	        		int row_exist = row_states & (1 << (row_num-1));
	        		if(row_exist)
	        			return false;
	        		else
	        			row_states |= ( 1 << (row_num-1) );
        		}
        		//column
        		int col_num = board[j][i] - '0';
        		if(0 <= col_num && col_num <= 9) {
	        		int col_exist = col_states & (1 << (col_num-1));
	        		if(col_exist)
	        			return false;
	        		else
	        			col_states |= ( 1 << (col_num-1) );
        		}
        		//grid
        		int grid_num = row_num;
        		int grid_index = i / 3 * 3 + j / 3;
        		if(0 <= grid_num && grid_num <= 9) {
	        		int grid_exist = grid_states[grid_index] & (1 << (grid_num-1));
	        		if(grid_exist)
	        			return false;
	        		else
	        			grid_states[grid_index] |= ( 1 << (grid_num-1) );
        		}
        	}
        }
 		return true;
    }
};