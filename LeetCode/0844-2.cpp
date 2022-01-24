class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int pos = 0; 
        for(auto& i : S)
            if(i != '#')
                S[pos] = i, ++pos;
            else if(pos > 0)
                --pos;
        S.resize(pos);
        
        pos = 0;
        for(auto& i : T)
            if(i != '#')
                T[pos] = i, ++pos;
            else if(pos > 0)
                --pos;
        T.resize(pos);
        
        return (S == T);
    }
};