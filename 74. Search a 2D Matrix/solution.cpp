#include <vector>
//double binary search, one for row, one for column
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix.front().size() == 0)
        	return false;
        if(target < matrix.front().front() || target > matrix.back().back())
        	return false;
        //find the row
        int l = 0, r = matrix.size() - 1, mid = l + (r - l) / 2;
        while(l <= r) {
        	mid = l + (r - l) / 2;
  			if(target < matrix[mid].front())
  				r = mid - 1;
  			else if(target > matrix[mid].back())
  				l = mid + 1;
  			else
  				break;
  		}
  		if(l > r)
  			return false;
  		//find the column
  		auto &v = matrix[mid];
  		l = 0, r = matrix.front().size();
  		while(l <= r) {
  			mid = l + (r - l) / 2;
  			if(v[mid] < target)
  				l = mid + 1;
  			else if(v[mid] > target)
  				r = mid - 1;
  			else
  				return true;
  		}
  		return false;
	}
};
//one binary search, view matrix as a big vector
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
        	return false;
        int col = matrix.front().size();
        if(col == 0)
        	return false;
        int l = 0, r = row * col - 1, mid;
        while(l <= r) {
        	mid = l + (r -l) / 2;
        	int val = matrix[mid / col][mid % col];
        	if(val < target)
        		l = mid + 1;
        	else if(val > target)
        		r = mid - 1;
        	else
        		return true;
        }
        return false;
    }
};