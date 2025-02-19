/*
ID: onceilo1
LANG: C++
TASK: Number of Smaller
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
    for (int i = 0; i < m; i++) {
        while (j < n and a[j] < b[i]) j++;
        cout << j << " ";
    }
    return 0;
}
