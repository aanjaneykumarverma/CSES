#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    int median = a[n / 2];
    long long cost = 0;
    for (int i = 0; i < n; ++i)
        cost += abs(median - a[i]);
    cout << cost;
    return 0;
}