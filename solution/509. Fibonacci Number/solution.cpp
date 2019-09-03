class Solution {
public:
    int fib(int N) {
        int prev1 = 0, prev2 = 1;
        if(N == 0)
            return 0;
        int ans = prev2;
        for(int i = 1;i < N;++i){
            ans += prev1;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};