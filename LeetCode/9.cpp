class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = x, reverse = 0, max = INT_MAX / 10;
        while(temp > 0)
        {
            if(reverse >= max)
                return false;
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }
        return reverse == x;
    }
};