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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        int elem = a[i].first;
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = a[l].first + a[r].first;
            if (sum + elem == x)
            {
                cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second;
                return 0;
            }
            else if (sum + elem < x)
                ++l;
            else
                --r;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}