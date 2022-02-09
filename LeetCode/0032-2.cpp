// ref: https://www.youtube.com/watch?v=39CEPFCl5sE&ab_channel=LeetCode%E5%8A%9B%E6%89%A3

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> Stack;
        Stack.push(-1);
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                Stack.push(i);
                continue;
            }
            
            Stack.pop();
            if (Stack.empty()) {
                Stack.push(i);
                continue;
            }
            
            ret = max(i - Stack.top(), ret);
        }
        
        return ret;
    }
};