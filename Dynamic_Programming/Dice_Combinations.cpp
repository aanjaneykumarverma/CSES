#include <bits/stdc++.h>
#define MOD 1000000000 + 7
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int num = 1; num <= n; ++num)
    {
        for (int i = 1; i <= 6; ++i)
        {
            if (num - i >= 0)
            {
                dp[num] = dp[num] + dp[num - i];
                dp[num] %= MOD;
            }
        }
    }
    cout << dp[n];
}