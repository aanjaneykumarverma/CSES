#include <bits/stdc++.h>
#define INF 1000001
using namespace std;
typedef pair<int, pair<int, int>> p_of_pint;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, -1e14));

    for (int i = 0; i < n; ++i)
        dp[i][i] = x[i];

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            long long op1 = x[i] - (i + 1 < n ? dp[i + 1][j] : 0);
            long long op2 = x[j] - dp[i][j - 1];
            dp[i][j] = max(op1, op2);
        }
    }

    cout << (sum + dp[0][n - 1]) / 2;
}