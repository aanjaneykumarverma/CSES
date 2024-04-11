#include <bits/stdc++.h>
#define INF 1000001
using namespace std;
vector<int> get_digits(int x)
{
    vector<int> digits;
    while (x)
    {
        int digit = x % 10;
        if (digit)
            digits.push_back(digit);
        x /= 10;
    }
    return digits;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int val = 1; val <= n; ++val)
    {
        auto digits = get_digits(val);
        for (auto digit : digits)
            dp[val] = min(dp[val], dp[val - digit] + 1);
    }
    std::cout << dp[n];
}