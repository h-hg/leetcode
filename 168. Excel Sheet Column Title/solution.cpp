class Solution {
public:
    std::string convertToTitle(int n) {
    	if(n == 0)
    		return "";
    	std::string ans;
        while(n){
        	--n;
        	ans.push_back(n % 26 + 'A');
        	n /= 26;
        };
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
