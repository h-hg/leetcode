#include <vector>
class Solution {
public:
 	void setZeroes(std::vector<std::vector<int>>& matrix) {
		bool firstColZero = false;
		int row = matrix.size();
		int col = matrix[0].size();

		for (int i = 0; i < row; ++i) {
			// Since first cell for both first row and first column is the same i.e. matrix[0][0]
			// We can use an additional variable for either the first row/column.
			// For this solution we are using an additional variable for the first column
			// and using matrix[0][0] for the first row.
			if (matrix[i][0] == 0)
		    	firstColZero = true;

			for (int j = 1; j < col; ++j)
			    // If an element is zero, we set the first element of the corresponding row and column to 0
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
		}
		// Iterate over the array once again and using the first row and first column, update the elements.
		for (int i = 1; i < row; ++i) {
			bool rowZero = matrix[i][0] == 0;
		 	for (int j = 1; j < col; ++j)
		 		if (rowZero || matrix[0][j] == 0)
		      		matrix[i][j] = 0;
		}

		// See if the first row needs to be set to zero as well
		if (matrix[0][0] == 0)
			for (int j = 0; j < col; ++j)
				matrix[0][j] = 0;

		// See if the first column needs to be set to zero as well
		if (firstColZero)
		 	for (int i = 0; i < row; ++i)
				matrix[i][0] = 0;
	}
};