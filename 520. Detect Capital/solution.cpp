class Solution {
public:
    bool detectCapitalUse(string word) {
        auto isCapital = [](char c)->bool{return 'A' <= c && c <= 'Z';};
        int cnt = count_if(word.begin(), word.end(),isCapital );
        if(cnt == word.size() || cnt == 0 )
            return true;
        return cnt == 1 && isCapital(word.front());
    }
};