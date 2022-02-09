class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        ++digits[i];
        
        while (i > 0 && digits[i] >= 10) {
            digits[i - 1] += digits[i] / 10;
            digits[i--] %= 10;
        }
        
        if (digits[0] >= 10) {
            digits.insert(digits.begin(), digits[0] / 10);
            digits[1] %= 10;
        }
        
        return digits;
    }
};