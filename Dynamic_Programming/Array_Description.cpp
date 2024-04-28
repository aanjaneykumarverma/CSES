#include <bits/stdc++.h>
using namespace std;
#define MOD (1000000000 + 7)
int add(int a, int b)
{
    int c = (a + b);
    return c % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; ++i)
        if (!a[0] || a[0] == i)
            dp[1][i] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1] && a[i - 1] != j)
                continue;
            if (j - 1 >= 1)
                dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (j + 1 <= m)
                dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = add(ans, dp[n][i]);

    cout << ans;
}