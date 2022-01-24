class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {};
        for(auto i : ransomNote)
            ++count[i - 'a'];
        for(auto i : magazine)
            --count[i - 'a'];
        for(auto i : count)
            if(i > 0)
                return false;
        return true;
    }
};