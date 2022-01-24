class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string tmp, res, _append = "ma";
        while(ss >> tmp)
        {
            if(!isVowel(tolower(tmp[0]))) tmp += tmp[0], tmp.erase(tmp.begin());
            res += tmp + (_append += 'a') + ' ';
        }
        return res.substr(0, res.size() - 1);
    }
private:
    inline bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
};