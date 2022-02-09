class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string str = countAndSay(n - 1);
        string ret;
        
        int cnt = 1;
        int lastN = str[0] - '0';
        
        for (int i = 1; i < str.size(); ++i) {
            int N = str[i] - '0';
            
            if (N != lastN) {
                ret += to_string(cnt) + to_string(lastN);
                cnt = 1;
                lastN = N;
            } else ++cnt;
        }
        
        if (cnt) ret += to_string(cnt) + to_string(lastN);
        
        return ret;
    }
};