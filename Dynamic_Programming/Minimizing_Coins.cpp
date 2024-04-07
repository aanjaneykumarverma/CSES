#include <bits/stdc++.h>
#define INF 1000000 + 1
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> c(n), dp(x + 1, INF);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    dp[0] = 0;
    for (int val = 1; val <= x; ++val)
    {
        for (int i = 0; i < n; ++i)
        {
            if (val - c[i] >= 0)
                dp[val] = min(dp[val], dp[val - c[i]] + 1);
        }
    }
    cout << (dp[x] != INF ? dp[x] : -1);
}