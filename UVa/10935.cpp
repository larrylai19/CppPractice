#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    queue< int > cards;

    while ((cin >> n) && n != 0)
    {
        for (int i = 1; i <= n; ++i)
            cards.push(i);

        if (cards.size() == 1) // 當只有一張卡時直接印出即可
            cout << "Discarded cards:" << endl
                << "Remaining card: " << cards.front() << endl;
        else
        {
            cout << "Discarded cards: ";
            while (cards.size() > 2) // 先輸出最上面的卡然後移出，再將第一張放到最後面再移出
            {
                cout << cards.front() << ", ";
                cards.pop();
                cards.push(cards.front());
                cards.pop();
            }
            cout << cards.front(); // 輸出倒數第二張牌
            cards.pop();
            cout << endl << "Remaining card: " << cards.front() << endl;
        }
        cards.pop(); // 將 queue 清空
    }
}