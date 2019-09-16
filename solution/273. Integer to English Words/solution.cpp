#include <vector>
#include <string>
//INT_MAX = 2,147,483,647
class Solution {
private:
    inline std::string lt20(int n) {
        static std::vector<std::string> table = {
    		"", "One ", "Two ", "Three ", "Four ",
            "Five ", "Six ", "Seven ", "Eight ", "Nine ",
    		"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
            "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
        };
        return table[n];
    }
    inline std::string lt100(int n) {
        static std::vector<std::string> table = {
             "", "", "Twenty ", "Thirty ", "Forty ",
             "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "
         };
         return n < 20 ? lt20(n) : table[n/10] + lt20(n%10);
    }
    inline std::string lt1000(int n) {
        int hundred = n / 100;
        return hundred == 0 ? lt100(n) : lt20(hundred) + "Hundred " + lt100(n % 100);
    }
public:
    std::string numberToWords(int num) {
        if(num == 0)
    		return "Zero";
        static std::vector<std::string> units = {"", "Thousand ", "Million ", "Billion "};
        std::string ans;
        for(int idx = 3, gap = 1e9; idx >= 0; --idx, gap /= 1e3) {
            if(num < gap)
                continue;
            ans.append(lt1000(num / gap)).append(units[idx]);
            num %= gap;
        }
        ans.pop_back();
    	return ans;
    }
};