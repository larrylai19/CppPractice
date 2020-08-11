class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, n = citations.size(), i = -1;
        sort(citations.begin(), citations.end(), greater<int>());
        while(++i < n && citations[i] >= i + 1) h = i + 1;
        // for(int i = 0; i < n; ++i) h = citations[i] >= i + 1 ? i + 1 : h;
        return h;
    }
};