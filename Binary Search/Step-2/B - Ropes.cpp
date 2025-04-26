#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    cout.unsetf(ios::floatfield);
    cout.precision(10);
    cout.setf(ios::fixed, ios::floatfield);
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (double &i : a) cin >> i;
    function<bool(double)> f = [&](double len) -> bool {
        int cnt = 0;
        for (auto el : a) {
            cnt += (el / len);
        }
        return cnt >= k;
    };

    double ans = 0, l = 0, r = *max_element(a.begin(), a.end());
    for (int i = 0; i <= 100; i++) {
        double mid = (l + r) * 0.5;
        if (f(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
    return 0;
}
