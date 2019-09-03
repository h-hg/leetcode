class Solution {
public:
    std::string shiftingLetters(std::string &S, std::vector<int>& shifts) {
        int n = S.size();
        shifts.back() %= 26;
        for(int i = n - 2;i >= 0;--i)
        	shifts[i] = ( shifts[i] + shifts[i+1] ) % 26;
        for(int i = 0;i < S.size();++i)
            S[i] = ( S[i] - 'a' + shifts[i] ) % 26 + 'a';
        return S;
    }
};


class Solution {
public:
    std::string shiftingLetters(std::string &S, std::vector<int>& shifts) {
        int shift = 0;
        auto first = S.rbegin(), last = S.rend();
        auto iter = shifts.rbegin();
        while(first != last) {
        	shift = ( shift + *iter ) % 26;
        	*first = (*first - 'a' + shift) % 26 + 'a';
        	++first;
            ++iter;
        }
        return S;
    }
};