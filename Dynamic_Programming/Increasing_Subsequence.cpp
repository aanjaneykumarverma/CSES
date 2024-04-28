#include <bits/stdc++.h>
#define MOD (1000000000 + 7)
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    vector<int> dp(n + 1, MOD);
    dp[0] = -MOD;
    for (int i = 0; i < n; ++i)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();
        if (dp[it - 1] < x[i] && x[i] < dp[it])
            dp[it] = x[i];
    }
    for (int i = n; i >= 0; i--)
        if (dp[i] != MOD)
        {
            cout << i;
            return 0;
        }
}