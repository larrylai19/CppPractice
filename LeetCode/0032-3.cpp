// ref: https://www.youtube.com/watch?v=39CEPFCl5sE&ab_channel=LeetCode%E5%8A%9B%E6%89%A3

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, len = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            s[i] == '(' ? ++left : ++right;
            
            if (left == right) {
                len = max(left * 2, len);
            }
            
            if (right > left) left = right = 0;
        }
        
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            s[i] == '(' ? ++left : ++right;
            
            if (left == right) {
                len = max(left * 2, len);
            }
            
            if (left > right) left = right = 0;
        }
        
        return len;
    }
};