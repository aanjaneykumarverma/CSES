#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    long long ans = 0;
    vector<long long> dp(n + 1, 0);
    vector<pair<int, pair<int, int>>> tasks(n);
    for (int i = 0; i < n; ++i)
    {
        int s, e, p;
        cin >> s >> e >> p;
        tasks[i] = {s, {e, p}};
    }
    std::sort(tasks.begin(), tasks.end());
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int s = tasks[i].first, e = tasks[i].second.first, p = tasks[i].second.second;
        auto it = upper_bound(tasks.begin(), tasks.end(), make_pair(e, make_pair(INF, INF))) - tasks.begin();
        dp[i] = max(dp[i + 1], p + dp[it]);
    }
    std::cout << dp[0];
}