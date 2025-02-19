/*
ID: onceilo1
LANG: C++
TASK: Number of Equal
*/
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int j = 0;
    int sum = 0;
    vector<int> cnt_each(m,0);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        while (j < n and a[j] < b[i]) j++;
        while (j < n and a[j] == b[i]) j++, cnt++;
        cnt_each[i] = cnt;
        if (i and b[i] == b[i - 1]) cnt_each[i] += cnt_each[i - 1];
    }
    sum = accumulate(all(cnt_each), 0ll);
    cout << sum;
    return 0;
}
