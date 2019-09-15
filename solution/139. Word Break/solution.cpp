#include <string>
#include <vector>
//brute force - dfs, timeout
class Solution {
private:
    inline bool startOf(std::string::iterator iter, std::string::iterator last, std::string &word) {
        if(last - iter < word.size())
            return false;
        for(auto c:word)
            if(*iter != c)
                return false;
            else
                ++iter;
        return true;
    }
    bool dfs(std::string::iterator first, std::string::iterator last, std::vector<std::string>& wordDict){
        if(first == last)
            return true;
        for(auto &word:wordDict)
            if(startOf(first, last, word) && dfs(first + word.size(), last, wordDict))
                return true;
        return false;
    }
public:
    bool wordBreak(std::string &s, std::vector<std::string>& wordDict) {
        return dfs(s.begin(), s.end(), wordDict);
    }
};

//dfs with memory
class Solution {
private:
    inline bool startOf(std::string &str, int idx, std::string &word) {
        if(str.size()-idx < word.size())
            return false;
        for(auto c:word)
            if(str[idx] != c)
                return false;
            else
                ++idx;
        return true;
    }
    bool dfs(std::string &str, int idx, std::vector<std::string>& wordDict, std::vector<int> &memo){
        if(idx == str.size())
            return true;
        if(memo[idx] != -1)
            return memo[idx];
        for(auto &word:wordDict)
            if(startOf(str, idx, word) && dfs(str,idx + word.size(), wordDict, memo))
                return memo[idx] = true;//true = 1
        return memo[idx] = false;//false = 0
    }
public:
    bool wordBreak(std::string &s, std::vector<std::string>& wordDict) {
        std::vector<int> memo(s.size(), -1);
        return dfs(s, 0, wordDict, memo);
    }
};


//bfs
class Solution {
private:
    inline bool startOf(std::string &str, int idx, std::string &word) {
        if(str.size()-idx < word.size())
            return false;
        for(auto c:word)
            if(str[idx] != c)
                return false;
            else
                ++idx;
        return true;
    }
public:
    bool wordBreak(std::string &s, std::vector<std::string>& wordDict) {
        std::vector<bool> memo(s.size(),false);//true stands for visited
        std::queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            if(memo[idx])
                continue;
            for(auto &word:wordDict)
                if(startOf(s,idx,word)) {
                    if(idx + word.size() == s.size())
                        return true;
                    q.push(idx + word.size());
                }
            memo[idx] = true;
        }
        return false;
    }
};

//dp
class Solution {
public:
    bool wordBreak(std::string &s, std::vector<std::string>& wordDict) {
        std::set<std::string> words(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(s.size()+1,false);//dp[i] = true means that s[0,i) can be made of words in wordDict 
        dp[0] = true;
        //divide s[0,i) into s[0,j) and s[j,i)
        for(int i = 1;i <= s.size();++i)
            for(int j = 0;j < i;++j)
                if(dp[j] && words.count(s.substr(j, i - j)))
                    dp[i] = true;
        return dp[s.size()];
    }
};