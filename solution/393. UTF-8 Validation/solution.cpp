#include <vector>
class Solution {
private:
	static const std::vector<std::pair<int,int>> table;
public:
    bool validUtf8(std::vector<int>& data) {
        for(int i = 0;i < data.size();) {
        	int n = 0;
        	for(;n < 4;++n)
        		if((data[i] >> table[n].first) == table[n].second)/*(n+1)-byte*/
        			break;
        	if(n == 4)
        		return false;
        	++i;
        	if(i + n > data.size())
        		return false;
        	for(int j = 0; j < n; ++j)
        		if((data[i++] >> 6) != 0x2)//whether most significant 2 bits is 10
        			return false;
        }
        return true;

    }
};
const std::vector<std::pair<int,int>> Solution::table = {
	{7, 0x0},//1-byte, 0x0 = 0
	{5, 0x6},//2-byte, 0x6 = 110
	{4, 0xe},//3-byte, 0xe = 1110
	{3, 0x1e}//4-byte, 0x1e = 11110
};