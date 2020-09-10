class Solution {
public:
    string getHint(string secret, string guess)
    {
        int A{}, B{}, n = secret.length();
        vector<int> v(10);
        for(auto& c : secret) ++v[c - '0'];
        for(int i{}; i < n; ++i)
        {
            if(v[guess[i] - '0']) --v[guess[i] - '0'], ++B;
            if(secret[i] == guess[i]) ++A, --B;
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};