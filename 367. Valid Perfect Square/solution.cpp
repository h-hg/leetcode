class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        long mid = l + (r -l) / 2;
        while(l <= r){
            mid = l + (r -l) / 2;
            long square = mid * mid;
            if(square == num)
                return true;
            else if(square  < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};