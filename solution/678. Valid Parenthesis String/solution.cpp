//dfs
#include <string>
class Solution {
private:
	int n = 0;
	bool dfs(std::string::iterator first, std::string::iterator last, int lcnt, int status)
	{
		if(first == last)
			return status == 0;
		if(status < 0 || lcnt > n)
			return false;
		if(*first == '(')
			return dfs(++first, last, lcnt + 1, status + 1);
		else if(*first == ')')
			return dfs(++first, last, lcnt, status - 1);
		else {
            ++first;
			if(dfs(first, last, lcnt + 1, status + 1))// * == (
				return true;
			else if(dfs(first, last, lcnt, status - 1))// * == )
				return true;
			else
				return dfs(first, last, lcnt, status);// * == ''
		}
	}
public:
    bool checkValidString(std::string &s) {
        n = s.size() >> 1;
        return dfs(s.begin(), s.end(), 0, 0);
    }
};