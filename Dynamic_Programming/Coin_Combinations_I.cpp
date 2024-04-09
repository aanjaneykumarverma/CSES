#include <bits/stdc++.h>
#define MOD 1000000000 + 7
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> c(n), dp(x + 1, 0);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    dp[0] = 1;
    for (int val = 1; val <= x; ++val)
    {
        for (int i = 0; i < n; ++i)
        {
            if (val - c[i] >= 0)
            {
                dp[val] = dp[val] + dp[val - c[i]];
                dp[val] %= MOD;
            }
        }
    }
    cout << dp[x];
}