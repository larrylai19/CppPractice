class Solution {
public:   
    int lastStoneWeight(vector<int>& stones) {
        int y, x;
        priority_queue<int> maxheap;
        for(auto& i : stones)
            maxheap.push(i);
        while(maxheap.size() > 1)
        {
            y = maxheap.top();
            maxheap.pop();
            x = maxheap.top();
            maxheap.pop();
            if(y != x)
                maxheap.push(y - x);
        }
        return maxheap.empty() ? 0 : maxheap.top();
    }
};