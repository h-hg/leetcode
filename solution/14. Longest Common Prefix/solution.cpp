//
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size() == 0)
        	return std::string();
        for(int i = 0;i < strs[0].size();++i)
        	for(int j = 1;j < strs.size();++j)
        		if(strs[j][i] != strs[0][i] || i == strs[j].size())
        			return strs[0].substr(0,i);
        return strs[0];
    }
};

//divide and conquer
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size() == 0)
        	return std::string();
       	return longestCommonPrefix(strs, 0 , strs.size() - 1);
    }
	std::string longestCommonPrefix(std::vector<std::string> &strs, int l, int r) {
	    if (l == r) {
	        return strs[l];
	    }
	    else {
	        int mid = (l + r)/2;
	        std::string lcpLeft =   longestCommonPrefix(strs, l , mid);
	        std::string lcpRight =  longestCommonPrefix(strs, mid + 1,r);
	        return commonPrefix(lcpLeft, lcpRight);
	   }
	}

	std::string commonPrefix(std::string &left,std::string &right) {
	    int min = std::min(left.size(), right.size());       
	    for (int i = 0; i < min; i++) {
	        if ( left[i] != right[i] )
	            return left.substr(0, i);
	    }
	    return left.substr(0, min);
	}
};