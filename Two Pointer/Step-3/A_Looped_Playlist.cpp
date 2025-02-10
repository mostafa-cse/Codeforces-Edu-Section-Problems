#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int sum = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0 ; i < n; i++)  a.push_back(a[i]);

    int cur = 0, Song = n, idx = 1;
    for (int l = 0, r = 0; l < n; l++) {
        while (cur < p % sum) cur += a[r++];
        if (r - l < Song) {
            Song = r - l;
            idx = l;
        }
        cur -= a[l];
    }
    cout << idx + 1 << " " << Song + n * (p / sum) << "\n";
    return 0;
}