#include <string>
#include <vector>
class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> ans;
        ans.reserve(n);
        for(int i = 1;i <= n; ++i) {
        	bool three = ( i % 3  == 0 );
        	bool five = ( i % 5  == 0 );
        	if(three && five)
        		ans.push_back("FizzBuzz");
        	else if(three)
        		ans.push_back("Fizz");
        	else if(five)
        		ans.push_back("Buzz");
        	else
        		ans.push_back(std::to_string(i));
        }
        return ans;
    }
};