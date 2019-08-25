
#include <string>
#include <utility>
//(a1+b1i)(a2+b2i) = (a1a2-b1b2)+(a1b2+b1a2)i


class Solution {
private:
    inline std::pair<int,int> str2complex(std::string &s) {
        int pos = s.find('+');
        int a = std::stoi(s.substr(0, pos)),
            b = std::stoi(s.substr(pos + 1, s.size()-2-pos));
        return std::pair<int,int>(a,b);
    }
public:
    std::string complexNumberMultiply(std::string a, std::string b) {
        auto c1 = str2complex(a), c2 = str2complex(b);
        return std::to_string(c1.first*c2.first-c1.second*c2.second).append(1,'+').append(std::to_string(c1.first*c2.second+c1.second*c2.first)).append(1,'i');
    }
};