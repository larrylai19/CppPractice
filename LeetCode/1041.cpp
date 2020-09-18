class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        pair<int, int> pos, face{0, 1};
        for(auto c : instructions)
        {
            if(c == 'G') pos.first += face.first, pos.second += face.second;
            else if(c == 'L') face = {-face.second, face.first};
            else face = {face.second, -face.first};
        }
        return (!pos.first && !pos.second) || face.first || face.second != 1;
    }
};