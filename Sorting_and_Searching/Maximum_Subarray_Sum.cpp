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

    long long maxSum = -1e10;
    long long curSum = 0;
    for (int i = 0; i < n; ++i)
    {
        curSum += a[i];
        maxSum = max(maxSum, curSum);
        if (curSum < 0)
            curSum = 0;
    }
    cout << maxSum;
    return 0;
}