#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map<int, vector<pair<int, int>>> vals;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            vals[a[i] + a[j]].push_back({i + 1, j + 1});
        }
    for (auto &val : vals)
        sort(val.second.begin(), val.second.end());
    for (auto &val : vals)
    {
        for (auto &nums : val.second)
        {
            auto it = lower_bound(vals[x - val.first].begin(), vals[x - val.first].end(), make_pair(nums.second + 1, -1));
            if (it != vals[x - val.first].end())
            {
                cout << nums.first << ' ' << nums.second << ' ' << (*it).first << ' ' << (*it).second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
