#include <vector>
//latyer-by-layer
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    	std::vector<int> ans;
    	if(matrix.size() == 0 || matrix[0].size() == 0)
    		return ans;
        int end_i = matrix.size()-1, end_j = matrix[0].size() -1, start_i = 0, start_j = 0;
    	ans.reserve(end_i*end_j);
        while(start_i <= end_i && start_j <= end_j) {
        	for(int j = start_j;j <= end_j;++j)
        		ans.push_back(matrix[start_i][j]);
        	for(int i = start_i + 1;i <= end_i;++i)
        		ans.push_back(matrix[i][end_j]);
        	if(start_i < end_i && start_j < end_j) {
	        	for(int j = end_j - 1;j >= start_j;--j)
	        		ans.push_back(matrix[end_i][j]);
	        	for(int i = end_i - 1;i > start_i;--i)
	        		ans.push_back(matrix[i][start_j]);
        	}
        	++start_i;
        	++start_j;
        	--end_i;
        	--end_j;
        }
        return ans;
    }
};

