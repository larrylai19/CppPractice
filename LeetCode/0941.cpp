class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        
        bool firstDown = false;
        bool isIncrease = false;
        
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                isIncrease = true;
                if (firstDown) return false;
            }
            else if (arr[i] < arr[i - 1]) firstDown = true;
            else return false;
        }
        
        return firstDown && isIncrease;
    }
};