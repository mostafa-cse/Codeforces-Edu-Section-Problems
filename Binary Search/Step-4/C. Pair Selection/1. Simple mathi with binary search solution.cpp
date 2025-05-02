#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    cout.unsetf(ios::floatfield);
    cout.precision(10);
    cout.setf(ios::fixed, ios::floatfield);
    int n, k;
    cin >> n >> k;

    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++)  {
        cin >> a[i] >> b[i];
    }

    function<bool(double)> check = [&](double x) -> bool {
        double sum = 0;
        int cnt = 0;
        vector<double> neg;
        for (int i = 0; i < n; i++) {
            double val = a[i] - b[i] * x;
            if (val >= 0) {
                sum += val;
                cnt++;
            } else {
                neg.push_back(val);
            }
        }
        
        sort(neg.rbegin(), neg.rend());
        for (int i = 0; i < neg.size() and cnt < k; i++, cnt++) {
            sum += neg[i];
            if (sum < 0) return false;
        }
        return true;
    };
    double l = 0, r = 1e18;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) * 0.5;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
