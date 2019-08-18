# condition

$\frac{(1+i)*i}{2}  \le n \lt \frac{(1+(i+1))*(i+1)}{2}$
$i^2 + i \le 2n \lt i^2 + 3i + 2$

# Binary Search

$i^2 + i \le 2n \implies i = \sqrt{i^2} \lt \sqrt{i^2 + i} <2n$

$2n \lt i^2 + 3i + 2 \implies 2n < (i+1.5)^2 - 0.25 \implies i > \sqrt{2n+0.25}-1.5$

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0 || n == 1)
            return n;
        for(long double_n = long(n) << 1, l = sqrt(double_n+0.25)-1.5, r = sqrt(double_n), mid, square_mid; l <= r; ){
            mid = l + (r -l) / 2;
            //judge
            square_mid = mid * mid;
            if(square_mid + mid > double_n)
                r = mid -1;
            else if(square_mid + 3 * mid + 2 <= double_n)
                l = mid + 1;
            else
                return mid;
        }
        return 0;//redundant
    }
};
```
# Solving Equations

$i^2 + i <= 2n \implies i \in [ \frac{-1-\sqrt{1+8n}}{2},\frac{-1+\sqrt{1+8n}}{2} ] \implies i \in [ 0,  \frac{-1+\sqrt{1+8n}}{2}]$

$2n \lt i^2 + 3i + 2 \implies i \in (-\infty, \frac{-3-\sqrt{1+8n}}{2}) \bigcup (\frac{-3+\sqrt{1+8n}}{2},+\infty) \implies i \in (\frac{-3+\sqrt{1+8n}}{2},+\infty) $

$i \in  (\frac{-3+\sqrt{1+8n}}{2},\frac{-1+\sqrt{1+8n}}{2}] \implies i = \lfloor \frac{-1+\sqrt{1+8n}}{2} \rfloor$

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1 + sqrt(1+8*double(n))) / 2);
    }
};
```
