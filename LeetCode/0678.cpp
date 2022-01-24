class Solution {
public:
    bool checkValidString(string s) {
        int max = 0, min = 0;
        for(auto& i : s)
        {
            if(i == '(')
                ++min, ++max;
            else if(i == ')')
                --min, --max;
            else if(i == '*')
                --min, ++max;
            if(max < 0)
                return false;
            if(min < 0)
                min = 0;
        }
        return min == 0;
    }
};