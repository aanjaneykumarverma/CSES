#include <bits/stdc++.h>
#define MOD (1000000000 + 7)
using namespace std;
long long power(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}
long long modInverse(int x)
{
    return power(x, MOD - 2);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int maxSum = n * (n + 1);
    if (n % 4 != 0 && n % 4 != 3)
    {
        cout << 0;
        return 0;
    }
    maxSum /= 4;
    vector<int> c(n), dp(maxSum + 1, 0);
    iota(c.begin(), c.end(), 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int val = maxSum; val >= 0; --val)
        {
            if (val - c[i] >= 0)
            {
                dp[val] = dp[val] + dp[val - c[i]];
                dp[val] %= MOD;
            }
        }
    }
    cout << (dp[maxSum] * modInverse(2)) % MOD;
}