class Solution {
public:
    int compareVersion(std::string &version1, std::string &version2) {
        auto i1 = version1.begin(), i2 = version2.begin();
        while(true){
            int val1 = 0, val2 = 0;
            while(i1 != version1.end())
                if(*i1 == '.'){
                    ++i1;
                    break;
                }
                else
                    val1 = val1 * 10 + (*i1++ -'0');
            while(i2 != version2.end())
                if(*i2 == '.'){
                    ++i2;
                    break;
                }
                else
                    val2 = val2 * 10 + (*i2++ -'0');
            if(val1 != val2)
                return val1 > val2 ? 1 : -1;
            if(i1 == version1.end() && i2 == version2.end())
                break;
        }
        return 0;
    }
};

//library function
class Solution {
public:
    int compareVersion(std::string &version1, std::string &version2) {\
        std::replace(version1.begin(),version1.end(),'.',' ');
        std::replace(version2.begin(),version2.end(),'.',' ');
        std::istringstream iss1(version1), iss2(version2);
        while(true){
            int val1 = 0, val2 = 0;
            iss1 >> val1;
            iss2 >> val2;
            if(val1 != val2)
                return val1 > val2 ? 1 : -1;
            if(!iss1 && !iss2)
                break;
        }
        return 0;
    }
};