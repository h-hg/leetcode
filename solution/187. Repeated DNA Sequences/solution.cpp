#include <string>
#include <map>
#include <vector>
//bruite force
class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string &s) {
        std::vector<std::string> ans;
        if(s.size() <= 10)
            return ans;
        std::map<std::string, int> seq2cnt; //sequence to count
        std::string seq;
        seq.reserve(10);
        for(auto iter = s.begin() + 10; iter != s.end(); ++iter) {
            seq.assign(iter - 10, iter);
            if(++seq2cnt[seq] == 2)
                ans.push_back(seq);
        }
        seq.assign(s.end()-10,s.end());
        if(++seq2cnt[seq] == 2)
            ans.push_back(seq);
        return ans;
    }
};