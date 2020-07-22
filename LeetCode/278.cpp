// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long first = 1, last = n, mid;
        while(true)
        {
            mid = (first + last) / 2;
            if(isBadVersion(mid) && !isBadVersion(mid - 1))
                return mid;
            if(!isBadVersion(mid))
                first = mid + 1;
            else
                last = mid - 1;
        }
        return 0;
    }
};