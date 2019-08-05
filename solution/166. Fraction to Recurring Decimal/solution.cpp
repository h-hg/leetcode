#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define INT_BIT (sizeof(int)*8)
#define LONG_BIT (sizeof(long)*8)
class Solution {
public:
    //numerator / denominator = quotient + remainder
    std::string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        long n = long(numerator), d = long(denominator), r = n % d, q = n / d;//using long to avoid -2^32
        //deal with negative
        std::string ans;
        if( (numerator ^ denominator) >> (INT_BIT -1 )  && q == 0)
            ans.push_back('-');
        ans += std::to_string(q);
        if(r == 0)
            return ans;
        else if(r < 0)
            r = - r;
        if(d < 0)
            d = -d;

        std::vector<int> remainders;
        std::string quotients;

        int idx_repeat = -1;
        do{
            //judge repeating
            idx_repeat = std::find(remainders.begin(),remainders.end(),r) - remainders.begin();
            if(idx_repeat != remainders.size())
                break;
            //calculate next quotient and remainder
            remainders.push_back(r);
            r *= 10;
            quotients.push_back('0' + r / d);
            r %= d;
        }while(r);
        ans.reserve(ans.size() + quotients.size() + 3);//3 is '.', '(' and ')'
        ans.push_back('.');
        
        
        if(r != 0) {
            ans.append(quotients.begin(), quotients.begin()+idx_repeat);
            ans.push_back('(');
            ans.append(quotients.begin()+idx_repeat,quotients.end());
            ans.push_back(')');
        }else
            ans.append(quotients.begin(), quotients.end());
        return ans;
    }
};