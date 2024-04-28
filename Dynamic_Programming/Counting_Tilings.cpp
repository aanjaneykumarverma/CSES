#include <bits/stdc++.h>
#define MOD (1000000000 + 7)
#define ll long long
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> comp(1 << n, vector<int>(1 << n, 0));
    for (int i = 0; i < (1 << n); ++i)
    {
        for (int j = 0; j < (1 << n); ++j)
        {
            int inActive = (~i) & (~j);
            int ok = 1;
            int last = -1;
            for (int k = 0; k < n; ++k)
            {
                if ((1 << k) & inActive)
                {
                    if (last == -1)
                        last = k;
                }
                else
                {
                    if (last != -1)
                    {
                        ok &= (k - last) % 2 == 0;
                        last = -1;
                    }
                }
            }
            if (last != -1)
                ok &= (n - last) % 2 == 0;
            comp[i][j] = ok;
        }
    }
    vector<vector<ll>> dp(m + 2, vector<ll>(1 << n, 0));
    dp[1][0] = 1;
    for (int i = 2; i <= m + 1; ++i)
    {
        for (int j = 0; j < (1 << n); ++j)
        {
            int negJ = (~j) & ((1 << n) - 1);
            for (int subMask = negJ; subMask; subMask = (subMask - 1) & negJ)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][subMask] * comp[j][subMask]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][0] * comp[j][0]) % MOD;
        }
    }
    cout << dp[m + 1][0];
}