#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> h(n + 1, 0), s(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
        }
    }

    cout << dp[n][x];
}