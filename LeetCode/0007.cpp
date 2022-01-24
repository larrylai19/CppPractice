class Solution {
public:
    int reverse(int x) {
        int ans = 0, max = INT_MAX / 10, min = INT_MIN / 10;
        while(x != 0)
        {
            if(ans > max || ans < min)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};