class Solution {
public:
    int findComplement(int num) {
        int count = 32, temp = num;
        while(temp > 0)
            temp >>= 1, --count;
        return ~(num << count) >> count;
    }
};