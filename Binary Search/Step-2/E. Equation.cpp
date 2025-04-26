#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    cout.unsetf(ios::floatfield);
    cout.precision(15);
    cout.setf(ios::fixed, ios::floatfield);
    double c;
    cin >> c;

    double l = 0, r = 1e6, ans = 0;
    for (int i = 0; i <= 100; i++) {
        double mid = (l + r) * 0.5;

        double val = mid * mid + sqrtl(mid);
        if (val <= c) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << ans;
    return 0;
}
