class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int i = 1; i <= n; ++i)
        {
            string tmp;
            if(!(i % 3)) tmp += "Fizz";
            if(!(i % 5)) tmp += "Buzz";
            if(tmp.empty()) tmp += to_string(i);
            v.emplace_back(tmp);
        }
        return v;
    }
};