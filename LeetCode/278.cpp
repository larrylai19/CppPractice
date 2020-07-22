// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long first = 1, last = n, mid = (first + last) / 2;
        while(!isBadVersion(mid) || isBadVersion(mid - 1))
        {
            if(!isBadVersion(mid))
                first = mid + 1;
            else
                last = mid - 1;
            mid = (first + last) / 2;
        }
        return mid;
    }
};