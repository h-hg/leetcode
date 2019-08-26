#include <string>
class Solution {
    inline bool isValidGroup4(const std::string &group) {
        if(group.empty() || group.size() > 3) //error length
            return false;
        if(group.front() == '0' && group.size() > 1)//error number
            return false;
        int val = 0;
        for(auto c:group)
            if('0' <= c && c <= '9')
                val = val * 10 + c - '0';
            else
                return false;
        return val < 256;
    }
    inline std::string validIP4(std::string &IP){
        size_t first = 0, last;
        for(int i = 0;i < 3;++i){
            if( (last = IP.find('.', first)) == std::string::npos)
                return "Neither";
            if(isValidGroup4(IP.substr(first, last - first)) == false)
                return "Neither";
            first = last + 1;
        }
        if(isValidGroup4(IP.substr(first,IP.size() - first )) == false)
            return "Neither";
        return "IPv4";
    }
    inline bool isVaildGroup6(const std::string &group){
        if(group.empty() || group.size() > 4)
            return false;
        for(auto c:group)
            if( !( ('0' <= c && c <= '9') || ('a' <= c && c<= 'f') || ('A' <= c && c <= 'F') ) )
                return false;
        return true;
    }
    inline std::string validIP6(std::string &IP){
        size_t first = 0, last, val;
        for(int i = 0;i < 7;++i){
            if( (last = IP.find(':', first)) == std::string::npos)
                return "Neither";
            if(first == last || isVaildGroup6(IP.substr(first, last - first)) == false)
                return "Neither";
            first = last + 1;
        }
        if(first == IP.size() || isVaildGroup6(IP.substr(first, last - first)) == false )
            return "Neither";
        return "IPv6";
    }
public:
    std::string validIPAddress(std::string &IP) {
        if(IP.find('.') != std::string::npos)
            return validIP4(IP);
        else if(IP.find(':') != std::string::npos)
            return validIP6(IP);
        return "Neither";
    }
};