class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int l = 0, r = 0; r < A.size(); ++r) if(!(A[r] % 2)) swap(A[l++], A[r]);
        return A;
    }
};