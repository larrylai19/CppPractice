// ref: https://www.youtube.com/watch?v=39CEPFCl5sE&ab_channel=LeetCode%E5%8A%9B%E6%89%A3

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ret = 0;
        vector<int> dp(n);
        
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')' && i - dp[i - 1] -1 >= 0 && s[i - dp[i - 1] -1] == '(') {
                int preVaild = (i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0;
                dp[i] = dp[i - 1] + preVaild + 2;
            }
            ret = max(dp[i], ret);
        }
        
        return ret;
    }
};