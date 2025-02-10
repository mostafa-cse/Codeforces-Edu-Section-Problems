#include <bits/stdc++.h>
using namespace std;
main() {
    vector<set<int>> v(4);
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            v[i].insert(x);
        }
    }

    int a, b, c, d, mn = 1e5, mx = 0, e[4];
    for (int x = 1; x <= 1e5; x++) { // target value
        for (int i = 0; i < 4; i++) {
            if (v[i].lower_bound(x) == v[i].end()) mx = 1e9;
            mx = max(mx, e[i] = *v[i].lower_bound(x));
        }
        if (mx - x < mn) {
            mn = mx - x;
            tie(a, b, c, d) = {e[0], e[1], e[2], e[3]};
        }
    }
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}
