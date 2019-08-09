#include <string>
#include <algorithm>
#include <vector>
//brute force
class Solution {
private:
    inline bool canForm(const std::string &lstr, const std::string &sstr)
    {
        if(lstr.size() < sstr.size())
            return false;
        auto iter_l = lstr.begin(), iter_s = sstr.begin();
        while(iter_l != lstr.end() && iter_s != sstr.end())
            if(*iter_l++ == *iter_s)
                ++iter_s;
        if(iter_s == sstr.end())
            return true;
        return false;
    }
public:
    std::string findLongestWord(std::string &s, std::vector<std::string>& d) {
        int ans_len = 0;
        const std::string *ans_ptr = nullptr;
        for(auto &str: d){
            if(str.size() < ans_len)
                continue;
            if(canForm(s,str) == false)
                continue;
            if(ans_ptr == nullptr || str.size() > ans_len) {
                ans_ptr = &str;
                ans_len = str.size();
            } else if(str < *ans_ptr) {
                ans_ptr = &str;
                ans_len = str.size();
            }
        }
        return ans_len == 0 ? "" : *ans_ptr;
    }
};


//using sort
class Solution {
private:
    inline bool canForm(const std::string &lstr, const std::string &sstr)
    {
        if(lstr.size() < sstr.size())
            return false;
        auto iter_l = lstr.begin(), iter_s = sstr.begin();
        while(iter_l != lstr.end() && iter_s != sstr.end())
            if(*iter_l++ == *iter_s)
                ++iter_s;
        if(iter_s == sstr.end())
            return true;
        return false;
    }
public:
    std::string findLongestWord(std::string &s, std::vector<std::string>& d) {
        std::sort(
            d.begin(),
            d.end(),
            [](const std::string &x, const std::string &y)->bool{
                if(x.size() < y.size())
                    return false;
                else if(x.size() > y.size())
                    return true;
                else
                    return x < y;
            }
        );
        for(auto &str:d)
            if(canForm(s,str))
                return str;
        return std::string();
    }
};

