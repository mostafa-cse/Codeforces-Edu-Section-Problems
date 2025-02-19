/*
ID: onceilo1
LANG: C++
TASK:  Merging Arrays,
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int i = 0, j = 0;
    while (i < n and j < m) {
        if (a[i] < b[j]) cout << a[i ++] << " ";
        else cout << b[j++] << " ";
    }
    while (i < n) cout << a[i++] << " ";
    while (j < m) cout << b[j++] << " ";
    return 0;
}
