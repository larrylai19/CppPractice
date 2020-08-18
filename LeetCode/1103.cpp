class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int r = 0, tmp;
        vector<int> v(num_people);
        while(candies >= (tmp = (1 + num_people) * num_people / 2 + num_people * num_people * r)) candies -= tmp, ++r;
        if(r) for(int i = 0; i < num_people; ++i) v[i] += (i + 1 + i + 1 + num_people * (r - 1)) * r / 2;
        for(int i = 0; i < num_people; ++i)
            if(candies >= (tmp = i + 1 + num_people * r)) v[i] += tmp, candies -= tmp;
            else { v[i] += candies; break; }
        return v;
    }
};