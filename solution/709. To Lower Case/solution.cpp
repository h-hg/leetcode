#include <iostream>
class Solution {
public:
    std::string toLowerCase(std::string &str) {
        for(auto &c:str)
        	if('A' <= c && c <= 'Z')
        		c = c - 'A' + 'a';
        return str;
    }
};