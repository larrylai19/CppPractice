class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        long long mid, squareMid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            squareMid = mid * mid;
            if(squareMid == num)
                return true;
            else if(squareMid > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};