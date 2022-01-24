class Solution {
public:
    bool detectCapitalUse(string word) {
        int index, count = 0, n = word.size();
        for(int i = 0; i < n; ++i)
            if(word[i] >= 'A' && word[i] <= 'Z')
                ++count, index = i;
        if(!count || (count == 1 && !index) || count == n)
            return true;
        return false;
    }
};