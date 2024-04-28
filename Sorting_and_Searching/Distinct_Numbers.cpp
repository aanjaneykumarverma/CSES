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
    set<int> num;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        num.insert(x);
    }
    cout << num.size();
}