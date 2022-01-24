class Solution {
public:
    int next(int n)
    {
        int next = 0;
        while( n > 0)
        {
            next += (n % 10) * ( n % 10);
            n /= 10;
        }
        return next;
    }
    
    bool isHappy(int n) {
        int tortoise = n;
        int hare = n;
        do
        {
            tortoise = next(tortoise);
            hare = next(next(hare));
        }while(tortoise != hare);
        return (hare == 1);
    }
};