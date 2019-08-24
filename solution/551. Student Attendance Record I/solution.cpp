class Solution {
public:
    bool checkRecord(std::string &s) {
        int lcnt = 0, acnt = 0;//count of L, A
        for(auto c: s)
            if(c == 'L') {
                if(++lcnt > 2)
                    return false;
            } else  {
                lcnt = 0;
                if(c == 'A') {
                    if(++acnt > 1)
                        return false;
                }
            }
        return true;
    }
};