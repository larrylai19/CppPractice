class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string str;
        sort(A.begin(), A.end());
        do
        {
            int hour = A[0] * 10 + A[1], minute = A[2] * 10 + A[3];
            if(!(hour < 24 && minute < 60)) continue;
            str = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        }while(next_permutation(A.begin(), A.end()));
        return str;
    }
};