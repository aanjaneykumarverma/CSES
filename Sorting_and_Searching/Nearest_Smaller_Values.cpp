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
    vector<int> nsl(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            nsl[i] = st.top() + 1;
        st.push(i);
    }
    for (int i = 0; i < n; ++i)
        cout << nsl[i] << ' ';
    return 0;
}
