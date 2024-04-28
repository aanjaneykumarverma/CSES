#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    vector<pair<int, long long>> dp(1 << n, {n + 1, x + 1});

    dp[0] = {1, 0};
    for (int i = 1; i < (1 << n); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                int i_prime = i ^ (1 << j);
                long long w_cur = dp[i_prime].second;
                int m_cur = dp[i_prime].first;
                if (w_cur + w[j] <= x)
                    dp[i] = min(dp[i], {m_cur, w_cur + w[j]});
                else
                    dp[i] = min(dp[i], {m_cur + 1, w[j]});
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}