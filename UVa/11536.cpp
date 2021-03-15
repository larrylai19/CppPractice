#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/foHacx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int N, M, K;
int Case = 0;
int pos[101];
int arr[1000001] = { 0, 1, 2, 3 };

void init()
{
    fill(pos, pos + 101, 0);

    // compute
    int tmp = arr[1] + arr[2] + arr[3];
    for (int i = 4; i <= N; ++i) arr[i] = tmp % M + 1, tmp += (arr[i] - arr[i - 3]);
}

void solve()
{
    queue<int> q;
    int _min = INT_MAX, cnt = 0, cur;

    for (int i = 1; i <= N; ++i)
    {
        cur = arr[i];
        if (cur < 1 || cur > K) continue;

        q.push(i);
        
        if (!pos[cur]) ++cnt;
        pos[cur] = i;

        while (q.front() != pos[arr[q.front()]]) q.pop();

        if (cnt == K) _min = min(i - q.front() + 1, _min);
    }

    cout << "Case " << ++Case << ": ";
    if (cnt == K) cout << _min << '\n';
    else cout << "sequence nai\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;
        init();
        solve();
    }
}