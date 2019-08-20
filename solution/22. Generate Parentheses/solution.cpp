#include <string>
#include <vector>
//dfs
class Solution {
private:
    int len = 0;
    /*
        lpc: count of left parenthes left
        state:
            letf parenthes: +1
            right parenthes:-1
   */
    void dfs(std::string &cur, int lpc, int state, std::vector<std::string> &ans) {
        if(state < 0 || lpc < 0)
            return;
        if(cur.size() == len) {
            ans.push_back(cur);
            return;
        }
        //add '('
        cur.push_back('(');
        dfs(cur,lpc-1,state+1,ans);
        //add ')'
        cur.back() = ')';
        dfs(cur,lpc,state-1,ans);

        cur.pop_back();
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        if( n == 0 ){
            ans.push_back("");
            return;
        }
        std::string cur;
        cur.reserve(len = n << 1);
        cur.push_back('(');
        dfs(cur,n-1,1,ans);
        return ans;
    }
};

//another solution on leetcode's discuss
#include<utility>
class Solution {
public:
    void generate(std::pair<int, int> cnts, std::string &cur, std::vector<std::string> & ans)
    {
        // there is n "(" in cur.
        if(cnts.first == 0) {
            // fill s with the rest ")"
            auto tmp = cur;
            ans.emplace_back(tmp.append(cnts.second,')'));
            return;
        }
        
        // add "("
        cur.push_back('(');
        generate(std::pair<int, int>(cnts.first - 1, cnts.second), cur, ans);
        // add ")" if "(" is less than ")"
        if(cnts.second > cnts.first)
        {
            cur.back() = ')';
            generate(std::pair<int, int>(cnts.first, cnts.second - 1), cur, ans);
        }
        cur.pop_back();
    }
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<string> ans;
        std::string cur;
        cur.reserve(n<<1);
        generate(std::pair<int, int>(n, n), cur, ans);
        return ans;
    }
};