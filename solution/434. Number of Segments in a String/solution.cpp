class Solution {
public:
    int countSegments(std::string& s) {
        int ans = 0;
        bool flag = false;
        for(auto c:s) {
            if(c != ' ')
                flag = true;
            else if(flag) {
                ++ans;
                flag = false;
            }
        }
        return flag ? ans+1 : ans;
    }
};