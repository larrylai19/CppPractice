// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int idx = 41;
        while(idx >= 40) idx = 7 * (rand7() - 1) + (rand7() - 1);
        return idx % 10 + 1;
    }
};