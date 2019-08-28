#include <string>
class Solution {
public:
    bool judgeCircle(std::string &moves) {
        int x = 0, y = 0;
        for(auto c:moves)
            switch(c){
                case 'R':
                    ++x;
                    break;
                case 'L':
                    --x;
                    break;
                case 'U':
                    ++y;
                    break;
                case 'D':
                    --y;
                    break;
            }
        return x == 0 && y == 0;
    }
};