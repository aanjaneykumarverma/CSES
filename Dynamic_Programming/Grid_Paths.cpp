#include <bits/stdc++.h>
#define MOD 1000000000 + 7
using namespace std;

int g(char c)
{
    return (c == '.' ? 1 : 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    dp[0][0] = g(grid[0][0]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j - 1 >= 0)
            {
                dp[i][j] += g(grid[i][j - 1]) * dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            if (i - 1 >= 0)
            {
                dp[i][j] += g(grid[i - 1][j]) * dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << (g(grid[n - 1][n - 1]) ? dp[n - 1][n - 1] : 0);
}