#include <string>
#include <vector>
//brute force
class Solution {
private:
	inline bool isMadeOfSubstr(std::string &s, int last)//string s is made of substr [0,last)
	{
		if(s.size() % last != 0)
			return false;
		for(int i = last, j = 0;i < s.size();++i)//j is the index of substr, i is the index of s
		{
			if(s[i] != s[j])
				return false;
			if(++j == last)
				j = 0;
		}
		return true;
	}
public:
    bool repeatedSubstringPattern(string s) {
        if(s.empty() || s.size() == 1)
            return false;
        char c = s.front();
        for(int i = 1;i < s.size();++i)
        	if(s[i] == c)
        		if(isMadeOfSubstr(s,i))
        			return true;
        return false;
    }
};

//KMP
class Solution {
public:
    bool repeatedSubstringPattern(std::string &s) {
        //Forward ptr
        int F = 1;
        //Behind Ptr
        int B = 0;
        //Put string into KMP array
        std::vector<int> KMP(s.size(),0);
        
        while(F < s.size()) {
            if(s[F] == s[B]) {
                KMP[F] = B + 1;
                F++;
                B++;
            }
            else if(B!= 0)
                B = KMP[B - 1];
            else
                F++;
        }
        //If the last index is zero, we know we don't have a repated substring
        if(KMP[KMP.size() -1] == 0)
            return false;
        //Get the value of the last substring
        int lastSubString = s.size() - KMP[KMP.size() - 1];
        //If we can divide the value of the last substring into the KMP's last element then we know we have a repeated substring 
        if(KMP[KMP.size() - 1 ] % lastSubString == 0)
            return true;
        return false;
    }
};