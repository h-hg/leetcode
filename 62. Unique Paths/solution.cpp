//in math, ans = C(m-1,n+m-2) = C(n-1,n+m-2)
class Solution {
public:
    int uniquePaths(int m, int n) {
        --m;
        --n;
        int x = std::min(m, n), s = n + m;
        long ans = 1;
        for(int i = 0;i < x;++i)
            ans *= (s--);
        for(int i = x;i > 1;--i)
            ans /= i;
        return ans;
    }
};
//in dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];//dp[i][j] = the number of the unique paths from (i,j) to destination (m-1,n-1)
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; ++i)
            dp[i][n-1] = 1;
        for(int j = 0; j < n; ++j)
            dp[m-1][j] = 1;
            
        for(int i = m-2; i >= 0; --i)
            for(int j = n-2; j >= 0; --j)
                dp[i][j] = dp[i+1][j] + dp[i][j+1];//for there are two direction to get to the destination
        return dp[0][0];
    }
};