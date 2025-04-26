#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &i : a) cin >> i;


    while (q--) {
        int x;
        cin >> x;
        int el = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << el + 1 << endl;
    }
    return 0;
}
