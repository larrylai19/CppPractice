class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int timeStamp[1001] = {}, curCap{};
        for(const auto& v : trips) timeStamp[v[1]] += v[0], timeStamp[v[2]] -= v[0];
        for(const auto& num : timeStamp)
        {
            curCap += num;
            if(curCap > capacity) return false;
        }
        return true;
    }
};