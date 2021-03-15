#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fDPncx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int N = (int)1e6;

int L;
int lastIdx; // 最長的 LIS 中的最後一個元素的 index
int nums[N];
int seq[N];
int id[N];   // seq[] 中相應位置元素的 index，即若 seq[0] = nums[5]，id[0] = 5
int pre[N];  // pre[i] 表包含 nums[i] 的 LIS，位於 nums[i] 的前一個元素在 nums[] 中的 index

void LIS()
{
    for (int i = 0; cin >> nums[i]; ++i)
    {
        int pos = lower_bound(seq, seq + L, nums[i]) - seq;
        seq[pos] = nums[i];
        id[pos] = i;
        pre[i] = pos > 0 ? id[pos - 1] : -1;
        if (pos == L - 1) lastIdx = i;
        if (pos == L) ++L;
    }
}

void Print(int idx)
{
    if (idx == -1) return;
    Print(pre[idx]);
    cout << nums[idx] << '\n';
}

void solve()
{
    cout << L << "\n-\n";
    Print(lastIdx);
}

int main()
{
    LIS();
    solve();
}