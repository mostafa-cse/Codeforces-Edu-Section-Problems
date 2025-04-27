#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    cout.unsetf(ios::floatfield);
    cout.precision(10);
    cout.setf(ios::fixed, ios::floatfield);
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }
    function<bool(double)> f = [&](double times) -> bool {
        double mn = 1e18, mx = -1e18;
        for (auto [pos, speed] : a) {
            double age = pos - speed * times;
            double pore = pos + speed * times;

            mn = min(pore, mn);
            mx = max(mx, age);
        }
        return mn >= mx;
    };
    double ans = 0, l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) * 0.5;
        if (f(mid)) {
            r = mid;
            ans = mid;
        } else {
            l = mid;
        }
    }
    cout << ans;
    return 0;
}
