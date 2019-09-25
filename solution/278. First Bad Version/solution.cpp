// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid;
        while(l <= r) {
            mid = l + ((r-l)>>1);
            if(isBadVersion(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return isBadVersion(mid) ? mid : mid + 1;
    }
};