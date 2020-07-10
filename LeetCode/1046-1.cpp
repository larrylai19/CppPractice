class Solution {
public:
    pair<int, int> findMax(vector<int>& stones)
    {
        pair<int, int> max;
        max = {stones[0], 0};
        for(int i = 1; i < stones.size(); ++i)
            if(stones[i] > max.first)
                max = {stones[i], i};
        stones[max.second] = 0;
        return max;
    }
    
    int lastStoneWeight(vector<int>& stones) {
        pair<int, int> x, y;
        do
        {
            y = findMax(stones);
            x = findMax(stones);
            if(y != x)
                stones[y.second] = y.first - x.first;
        }while(x.first != 0);
        return y.first;
    }
};