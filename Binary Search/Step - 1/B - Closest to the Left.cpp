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
        int el = upper_bound(a.begin(), a.end(), x) - a.begin();
        cout << el << endl;
    }
    return 0;
}
