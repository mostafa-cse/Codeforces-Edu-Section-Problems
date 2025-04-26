#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l > r) swap(l, r);

        int lcnt = lower_bound(a.begin(), a.end(), l) - a.begin();
        int rcnt = upper_bound(a.begin(), a.end(), r) - a.begin();
        cout << rcnt - lcnt << " ";
    }
    return 0;
}
