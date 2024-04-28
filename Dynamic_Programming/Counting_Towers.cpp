#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN = 1e6 + 1;
int mult(int a, int b)
{
    int c = (a * b) % MOD;
    if (c < 0)
        c += MOD;
    return c;
}
int add(int a, int b)
{
    int c = (a + b) % MOD;
    if (c < 0)
        c += MOD;
    return c;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<vector<long long>> dp(MAXN, vector<long long>(2, 0));

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        dp[i][1] = (2 * (dp[i - 1][1] % MOD) + MOD) % MOD + (dp[i - 1][0] % MOD);
        dp[i][0] = (dp[i - 1][1] % MOD) + (4 * (dp[i - 1][0] % MOD) + MOD) % MOD;
    }

    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] % MOD + dp[n][1] % MOD) % MOD << "\n";
    }
    return 0;
}
