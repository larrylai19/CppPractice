class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int>v;
        for(int i = A.size(); i > 0; --i)
        {
            int pos = find(A.begin(), A.end(), i) - A.begin();
            reverse(A.begin(), A.begin() + pos + 1);
            if(pos) v.emplace_back(pos + 1);
            reverse(A.begin(), A.begin() + i);
            v.emplace_back(i);
        }
        return v;
    }
};