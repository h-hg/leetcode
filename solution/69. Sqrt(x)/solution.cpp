//binary search
class Solution {
public:
    int mySqrt( int x ) {
        if( x < 2 )
            return x;
        long low = 1, high = x, mid, product; // 'long' avoids overflow
        while( low <= high ) {
            mid = low + (high - low) / 2;
            product = mid*mid;
            if( product == x )
                return mid;
            if( product < x )
                low = mid + 1;
            else
                high = mid - 1 ;
        }
        // because we could have incremented mid when 'product < x'
        if( mid * mid > x ) mid = mid - 1;
        return mid;
    }
};

//Newton's method (Newton-Raphson method)
/*
    f(x) - f(x0) = f'(x0)(x - x0)
    when f(x) = 0, x = x0 - f(x0) / f'(x0), x_{n+1} = x_n - f(x_n) / f'(x_n)
    when f(x) = x^2 - a, x_{n+1} = (x_n + a \ x_n) \ 2

*/
class Solution {
public:
    int mySqrt( int x ) {
        if( x < 2 )// 0 1 2 3
            return x;
        int precision = 0.1;
        
        long long ans = x;
        
        do {
            ans = (ans + x / ans) / 2;
        } while((ans * ans - x) > precision);
        
        return ans;
    }
};