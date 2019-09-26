#include <string>
#include <vector>
class Solution {
private:
	static const std::vector<char> table;
public:
    std::string toHex(int num) {
    	if(num == 0)
    		return "0";
    	unsigned int _num = num;
        std::string ans;
        while(_num) {
        	ans.push_back(table[_num & 0xf]);
        	_num >>= 4;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
const std::vector<char> Solution::table = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};